#include <future>
#include <iostream>
#include <chrono>
#include <thread>

static int do_task_A();
static void do_task_B();

void TEST_async()
{
    std::cout << "================== Test Async and future ================ \n";

    std::future<int> status = std::async(do_task_A);
    
    do_task_B();
    
    std::cout<<"The task A's status is " << status.get() << "\n";
}

/* */
static int do_task_A() 
{
    std::cout << "Doing task A...\n";
 
    /* sleep for 2s, testing */   
    std::chrono::milliseconds duration(2000);
    std::this_thread::sleep_for(duration);

    return 1;
}

void do_task_B() 
{
    std::cout << "Doing task B...\n";
}
