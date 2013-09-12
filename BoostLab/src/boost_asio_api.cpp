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
 */
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>

static void example_run();
static void example_poll();
static void example_reset();

static void example_run()
{
    boost::asio::io_service io_service;                 
    //boost::asio::io_service::work work(io_service);           // will block at run() blow if uncommented
    
    io_service.run();  

    std::cout << "Event processing is not blocked." << std::endl;      // never reach here if io_server has work object associated with
}

static void example_poll()
{
    const int NUM_TASKS = 23;

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

void TEST_boost_asio_api()
{
    std::cout << "\nExample: io_service run:\n";
    example_run();

    std::cout << "\nExample: io_service poll:\n";
    example_poll();
    
    std::cout << "\nExample: io_service reset:\n";
    example_reset();
}
