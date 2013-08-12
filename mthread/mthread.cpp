#include <iostream>
#include <thread>

void work(int arg)
{
    std::cout << "Thread[" << std::this_thread::get_id() << "]: " 
              << "the input arg: " << arg << "\n";
}

int main()
{
    std::cout << "Thread[" << std::this_thread::get_id() << "]: "
              << "main thread starts...\n\n";
 
    /* threads are started by constructing a std::thread object that 
     * specifies the task to run on that thread.
     */
    int arg = 3;

    std::thread t(work, arg);

    /* the calling thread (in main()) to wait for the thread associated 
     * with the std::thread object, in this case, t.
     */
    t.join();
}
