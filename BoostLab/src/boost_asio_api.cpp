#include <boost/asio.hpp>
#include <iostream>

void TEST_boost_asio_api()
{
    boost::asio::io_service io_service;     // provide core I/O functionality
    boost::asio::io_service::work work(io_service);     // The work class is a "class to inform the io_service when it has work to do." 
                                                        // In other words, as long as an io_service has a work object associated with it, it will never run out of stuff to do. 
                                                        // In this case, "Event processing finishes" never gets printed

    io_service.run();   // run io_service object's event processing loop
                        // run() blocks until all work has finished and there are no more handlers to be dispatched,
                        //       or until the io_service has been stopped

    std::cout << "Event processing finishes" << std::endl;
}
