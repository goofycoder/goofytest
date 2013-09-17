/*
     io_service::strand class provides the ability to post and dispatch handlers with the guarantee that none of those handlers will execute concurrently.
    
    strand object is serializing the event processing to only one thread at a time. 

Work will still execute serially, but it will execute through whichever worker thread is available at the time. 

We cannot program with the incorrect assumption the same thread will actually process all of the work!
 */
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/bind.hpp>
#include <iostream>

extern boost::mutex global_stream_lock;        // for std::cout

static void sync_io();       
static void WorkerThread(boost::shared_ptr<boost::asio::io_service> io_service_t);
static void PrintNum(int x);

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

static void PrintNum(int x)
{
    std::cout << "[" << boost::this_thread::get_id()
              << "] x: " << x << std::endl;
    boost::this_thread::sleep(boost::posix_time::millisec(500));
}

// create multiple threads to handle io_service events
static void sync_io()
{
    global_stream_lock.lock();
    std::cout << "Main thread [" << boost::this_thread::get_id() <<"] Starts...\n";
    global_stream_lock.unlock();
    
    const int NUM_THREADS = 3;

    // shared_ptr makes it copyable 
    boost::shared_ptr<boost::asio::io_service> io_service_t(new boost::asio::io_service);
    
    boost::shared_ptr<boost::asio::io_service::work> work(new boost::asio::io_service::work(*io_service_t));

    boost::asio::io_service::strand strand(*io_service_t);

    boost::thread_group worker_threads;

    for (int i=0; i<NUM_THREADS; ++i) {
        worker_threads.create_thread(boost::bind(&WorkerThread, io_service_t));
    }

    // give io_service work via post()
    // post work to other worker threads (because the current thread did not call poll() or run()
    strand.post( boost::bind( &PrintNum, 1 ) );
    strand.post( boost::bind( &PrintNum, 2 ) );
    strand.post( boost::bind( &PrintNum, 3 ) );
    strand.post( boost::bind( &PrintNum, 4 ) );
    strand.post( boost::bind( &PrintNum, 5 ) );
    strand.post( boost::bind( &PrintNum, 6 ) );
    strand.post( boost::bind( &PrintNum, 7 ) );
    strand.post( boost::bind( &PrintNum, 8 ) );
    strand.post( boost::bind( &PrintNum, 9 ) );

    // reset the work object to signal once the work has been completed that we wish to exit
    work.reset();
    //io_service_t->stop();         // if still use stop(), none of the work would be done

    // wait on all the threads to finish
    worker_threads.join_all();
    
    global_stream_lock.lock();
    std::cout << "Main thread [" << boost::this_thread::get_id() <<"] Terminates.\n";
    global_stream_lock.unlock();
}

void TEST_boost_serialized_io()
{
    std::cout << "\n=== Example: sync'd io:\n";
    sync_io();
}
