#include <string>
#include <mutex>
#include <iostream>
#include <fstream>
#include <stdexcept>
 
static void write_to_file(const std::string & message) 
{
    // mutex to protect file access
    static std::mutex mutex;
 
    // lock mutex before accessing file
    std::lock_guard<std::mutex> lock(mutex);
 
    // open file
    std::ofstream file("example.txt");
    if (!file.is_open())
        throw std::runtime_error("unable to open file");
 
    // write message to file
    file << message << std::endl;
 
    // file will be closed first when leaving scope (regardless of exception)
    // mutex will be unlocked second (from lock destructor) when leaving scope 
    // (regardless of exception)
}

void TEST_RAII_example()
{
    std::cout << "Showcase the RAII example.\n";

    std::cout << "Enter a string to write to file (example.txt):\n";

    std::string s;
    std::cin >> s;

    write_to_file(s);
}
