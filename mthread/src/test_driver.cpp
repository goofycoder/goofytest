#include <iostream>
#include "mthread.hpp" 

int main()
{
    std::cout << "================== Mthread Lab ==================\n"
              << "1. Async\n";

    unsigned option;
    std::cout << "\nYou choose: \n";

    while ( std::cin>>option ) {
        switch(option) {
        case 1:
            TEST_async();
            break;
        
        default:
            std::cout << "Invalid option.";
            break;
        }
        std::cout << "\nYou choose: \n";
    }

    return 0;
}
