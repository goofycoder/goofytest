#include <iostream>
#include <exception>    // exception class

static void exception_demo()
{
    try {
        throw 20;
    }
    catch (int e) {
        std::cout << "Caught exception: " << e << "\n";
    }
}

static void mem_exception_demo()
{
    int* array;

    try {
        array = new int[100];
    }
    catch (std::exception& e) {
        std::cout << "Standard exception: " << e.what() << "\n";
    }

    // do something with array
    delete[] array;
}

void TEST_exception_example()
{
    exception_demo();

    mem_exception_demo();
}
