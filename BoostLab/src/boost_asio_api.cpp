/*
    boost::asio::io_service io_service;                 // provide core I/O functionality
    boost::asio::io_service::work work(io_service);     // 'work' class is a "class to inform io_service when it has work to do." 
                                                        // As long as an io_service has a work object associated with it, it will never run out of stuff to do. 
    
    io_service.run()    // run io_service object's event processing loop
                        // run() blocks until all work has finished and there are no more handlers to be dispatched,
                        //       or until the io_service has been stopped
                        // Multiple threads may call the run() function to set up a pool of threads 
                        // from which the io_service may execute handlers. 
                        // All threads that are waiting in the pool are equivalent and 
                        // the io_service may choose any one of them to invoke a handler.

    io_service.poll()   // Run io_service object's event processing loop to execute ready handlers.
                        // poll() function runs handlers that are ready to run, ** without blocking**
                        //        until the io_service has been stopped or there are no more ready handlers.
 
    io_service.reset()  // Remove a work object from io_service
                        // must be called prior to any second or later set of invocations of the run(), run_one(), poll() or poll_one() functions 
                        // when a previous invocation of these functions returned due to the io_service being stopped or running out of work.

    io_service.stop()   // stop() function will signal the io_service that all work should be stopped
                        // so after the current batch of work finishes, no more work will be done. 
                        // It stops the io_service object's event processing loop.
                        // This function does not block, but instead simply signals the io_service to stop.
                        // All invocations of its run() or run_one() member functions should return as soon as possible. 

   ** Difference between stop() and reset():
        1) If we had associated a work object with the io_service and wanted to let all queued work finish
            - we would not call stop but rather destroy the work object. 
        2) If we want all work to finish but keep giving the io_service more things to do
            - it will never exit! 
            - In that case, at some point, we would want to call the stop function to ensure the system actually stops.

    boost::bind()       // supports arbitrary function objects, functions, function pointers, and class member function pointers
 */
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/bind.hpp>
#include <iostream>

static void example_run();
static void example_poll();
static void example_reset();
static void example_mthread_io();       
static void WorkerThread();
static void example_boost_bind();
static void goo(int i, float f);

boost::asio::io_service io_service_t;       // global io_service object for multithread uses

class MyClass 
{
public:
    void mFoo(int i, float f) {
        std::cout << "mFoo has input arg i: " << i << "\n";
        std::cout << "mFoo has input arg f: " << f << "\n";
    }
};

static void example_run()
{
    boost::asio::io_service io_service;                 
    //boost::asio::io_service::work work(io_service);           // will block at run() blow if uncommented
    
    io_service.run();  

    std::cout << "Event processing is not blocked." << std::endl;      // never reach here if io_server has work object associated with
}

static void example_poll()
{
    const int NUM_TASKS = 7;

    boost::asio::io_service io_service;
    boost::asio::io_service::work work(io_service);

    for (int i=0; i<NUM_TASKS; i++) {
        std::size_t rv;
        rv = io_service.poll();
        std::cout << "Task #" << i << " with return value: " << rv << "\n";
    }
}

// remove a work object from an io_service
static void example_reset()
{
    boost::asio::io_service io_service;
    boost::shared_ptr<boost::asio::io_service::work> work(new boost::asio::io_service::work(io_service));

    work.reset();
    io_service.run();
    
    std::cout << "Event processing is not blocked." << std::endl;     
}

// create multiple threads to handle io_service events
static void example_mthread_io()
{
    const int NUM_THREADS = 3;
    
    boost::shared_ptr<boost::asio::io_service::work> work(new boost::asio::io_service::work(io_service_t));

    boost::thread_group worker_threads;

    for (int i=0; i<NUM_THREADS; ++i) {
        worker_threads.create_thread(WorkerThread);
    }

    io_service_t.stop();

    worker_threads.join_all();
}

static void WorkerThread()
{
    std::string id = boost::lexical_cast<std::string>(boost::this_thread::get_id());

    std::cout << "Thread [" << id <<"] Starts...\n";

    io_service_t.run();         // support more concurrency for processing work through io_service object.

    std::cout << "Thread [" << id <<"] Finishes.\n";
}

static void example_boost_bind()
{
    // bind and invocate the regular function
    std::cout << "Bind regular function: \n";
    boost::bind(&goo, 23, 3.14f)();

    // bind and invocate the class member function
    std::cout << "Bind class member function: \n";
    MyClass mc;
    boost::bind(&MyClass::mFoo, mc, 23, 3.14f)();       // pay attention to the bind and invocation of class member function
}

static void goo(int i, float f)
{
    std::cout << "goo has input arg i: " << i << "\n";
    std::cout << "goo has input arg f: " << f << "\n";
}


void TEST_boost_asio_api()
{
    std::cout << "\n=== Example: io_service run:\n";
    example_run();

    std::cout << "\n=== Example: io_service poll:\n";
    example_poll();
    
    std::cout << "\n=== Example: io_service reset:\n";
    example_reset();

    std::cout << "\n=== Example: multithread io:\n";
    example_mthread_io();

    std::cout << "\n=== Example: boost bind:\n";
    example_boost_bind();
}
