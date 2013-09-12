/*
    boost::asio::io_service io_service;                 // provide core I/O functionality
    boost::asio::io_service::work work(io_service);     // 'work' class is a "class to inform io_service when it has work to do." 
                                                        // As long as an io_service has a work object associated with it, it will never run out of stuff to do. 
    
    io_service.run();   // run io_service object's event processing loop
                        // run() blocks until all work has finished and there are no more handlers to be dispatched,
                        //       or until the io_service has been stopped



 */
#include <boost/asio.hpp>
#include <iostream>

static void example_run();
static void example_poll();

static void example_run()
{
    boost::asio::io_service io_service;                 
    //boost::asio::io_service::work work(io_service);           // will block at run() blow if uncommented
    
    io_service.run();  

    std::cout << "Event processing finishes" << std::endl;      // never reach here if io_server has work object associated with
}

static void example_poll()
{
    const int NUM_TASKS = 23;

    boost::asio::io_service io_service;
    boost::asio::io_service::work work(io_service);

    for (int i=0; i<NUM_TASKS; i++) {
        io_service.poll();
        std::cout << "Task #" << i << "\n";
    }
}

void TEST_boost_asio_api()
{
    std::cout << "\nExample: io_service run:\n";
    example_run();

    std::cout << "\nExample: io_service poll:\n";
    example_poll();
}
