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

    io_service.post()   // give io_service work via post()
                        // post() asks the io_service to execute the given handler
                        // but without allowing the io_service to call the handler from inside this function.
                        // io_service guarantees that the handler will only be called in a thread in which 
                        // the run(), run_one(), poll() or poll_one() member functions is currently being invoked.

   ** Difference between stop() and reset():
        1) If we had associated a work object with the io_service and wanted to let all queued work finish
            - we would not call stop but rather destroy the work object. 
        2) If we want all work to finish but keep giving the io_service more things to do
            - it will never exit! 
            - In that case, at some point, we would want to call the stop function to ensure the system actually stops.

    boost::bind()       // supports arbitrary function objects, functions, function pointers, and class member function pointers
                        // provides a great deal of flexibility
 */
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/bind.hpp>
#include <iostream>

static void example_run();
static void example_poll();
static void example_reset();
static void example_mthread_io();       
static void WorkerThread(boost::shared_ptr<boost::asio::io_service> io_service_t);
static void example_boost_bind();
static void goo(int i, float f);
static void calc_fibo(size_t n);
static size_t fibo(size_t n);

boost::mutex global_stream_lock;        // for std::cout

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
        size_t rv;
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

static size_t fibo(size_t n)
{
    if (n<=1) 
        return n;

    boost::this_thread::sleep(boost::posix_time::millisec(500));

    return fibo(n-1) + fibo(n-2);
}

static void calc_fibo(size_t n)
{
    global_stream_lock.lock();
    std::cout << "[" << boost::this_thread::get_id()
              << "] Now calculating fib( " << n << " ) " << std::endl;
    global_stream_lock.unlock();

    size_t f = fibo(n);

    global_stream_lock.lock();
    std::cout << "[" << boost::this_thread::get_id()
              << "] fib(" << n << ") = " << f << std::endl;
    global_stream_lock.unlock();
}

static void WorkerThread(boost::shared_ptr<boost::asio::io_service> io_service_t)
{
    global_stream_lock.lock();
    std::cout << "Thread [" << boost::this_thread::get_id() <<"] Starts...\n";
    global_stream_lock.unlock();

    size_t rv = io_service_t->run();         // support more concurrency for processing work through io_service object.

    global_stream_lock.lock();
    std::cout << "Thread [" << boost::this_thread::get_id() <<"] Terminates. Executed " << rv << " tasks.\n";
    global_stream_lock.unlock();
}

// create multiple threads to handle io_service events
static void example_mthread_io()
{
    global_stream_lock.lock();
    std::cout << "Main thread [" << boost::this_thread::get_id() <<"] Starts...\n";
    global_stream_lock.unlock();
    
    const int NUM_THREADS = 3;

    // shared_ptr makes it copyable 
    boost::shared_ptr<boost::asio::io_service> io_service_t(new boost::asio::io_service);
    
    boost::shared_ptr<boost::asio::io_service::work> work(new boost::asio::io_service::work(*io_service_t));

    boost::thread_group worker_threads;

    for (int i=0; i<NUM_THREADS; ++i) {
        worker_threads.create_thread(boost::bind(&WorkerThread, io_service_t));
    }

    // give io_service work via post()
    // post work to other worker threads (because the current thread did not call poll() or run()
    io_service_t->post( boost::bind(calc_fibo, 3) );
    io_service_t->post( boost::bind(calc_fibo, 4) );
    io_service_t->post( boost::bind(calc_fibo, 5) );
    io_service_t->post( boost::bind(calc_fibo, 6) );
    io_service_t->post( boost::bind(calc_fibo, 7) );
    io_service_t->post( boost::bind(calc_fibo, 8) );
      
    size_t rv = io_service_t->poll();
    std::cout << "Main thread processed " << rv << " tasks.\n";

    // reset the work object to signal once the work has been completed that we wish to exit
    work.reset();
    //io_service_t->stop();         // if still use stop(), none of the work would be done

    // wait on all the threads to finish
    worker_threads.join_all();
    
    global_stream_lock.lock();
    std::cout << "Main thread [" << boost::this_thread::get_id() <<"] Terminates.\n";
    global_stream_lock.unlock();
}

void TEST_boost_asio_api()
{
    std::cout << "\n=== Example: io_service run:\n";
    example_run();

    std::cout << "\n=== Example: io_service poll:\n";
    example_poll();
    
    std::cout << "\n=== Example: io_service reset:\n";
    example_reset();

    std::cout << "\n=== Example: boost bind:\n";
    example_boost_bind();
    
    std::cout << "\n=== Example: multithread io:\n";
    example_mthread_io();
}
