#include <iostream>
#include <thread>
#include <vector>
#include <functional>   // mem_fn
#include <algorithm>    // for_each

#define THREAD_POOL_SIZE 10

void stats();

void work(int arg)
{
    std::cout << "Thread[" << std::this_thread::get_id() << "]: " 
              << "arg: " << arg << "\n";
}

void thread_pool()
{
    std::vector<std::thread> thread_pool;

    for (unsigned i=0; i<THREAD_POOL_SIZE; i++) {
        thread_pool.push_back(std::thread(work, i));
    }

    std::for_each(thread_pool.begin(), thread_pool.end(),
                  std::mem_fn(&std::thread::join));
}


void stats() 
{
    /* This is only a hint */
    unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " concurrent threads are supported.\n";
}

int main()
{
    std::cout << "Thread[" << std::this_thread::get_id() << "]: "
              << "main thread starts...\n\n";
 
    thread_pool();

    int arg = 20;

    /* threads are started by constructing a std::thread object that 
     * specifies the task to run on that thread.
     */
    std::thread t(work, arg);

    /* the calling thread (in main()) to wait for the thread associated 
     * with the std::thread object, in this case, t.
     */
    t.join();
}
