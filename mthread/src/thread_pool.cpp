#include <iostream>
#include <thread>
#include <vector>
#include <functional>   // mem_fn
#include <algorithm>    // for_each

static void work(int arg);
void stats();

void create_thread_pool(int thread_num)
{
    std::vector<std::thread> thread_pool;

    for (unsigned i=0; i<thread_num; i++) {
        thread_pool.push_back(std::thread(work, i));
    }

    /* join these threads */
    std::for_each(thread_pool.begin(), thread_pool.end(),
                  std::mem_fn(&std::thread::join));
}

void create_one_thread() 
{
    //std::thread::id id= std::this_thread::get_id();

    int arg = 237;          // magic number for test

    /* threads are started by constructing a std::thread object that 
     * specifies the task to run on that thread.
     */
    std::thread t(work, arg);

    /* the calling thread (in main()) to wait for the thread associated 
     * with the std::thread object, in this case, t.
     */
    t.join();
}

void print_thread_stats() 
{
    /* This is only a hint */
    unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " concurrent threads are supported.\n";
}

void TEST_thread_pool()
{
    std::cout << "Thread[" << std::this_thread::get_id() << "]: "
              << "main thread starts...\n\n";
 
    int thread_num;
    std::cout << "Enter the number of threads to create: \n";
    std::cin >> thread_num;

    std::cout << "\n Creating one thread...\n";
    create_one_thread();
    
    std::cout << "\n Creating multiple threads...\n";
    create_thread_pool(thread_num);
}

static void work(int arg)
{
    std::cout << "Thread[" << std::this_thread::get_id() << "]: " 
              << "with arg: " << arg << "\n";
}
