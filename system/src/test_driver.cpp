#include <iostream>
#include "sys_api.hpp" 

int main()
{
    std::cout << "================== System API Lab ==================\n"
              << "1. RAII example.\n";

    unsigned option;
    std::cout << "\nYou choose: \n";

    while ( std::cin>>option ) {
        switch(option) {
        case 1:
            TEST_RAII_example();
            break;
        
        default:
            std::cout << "Invalid option.";
            break;
        }
        std::cout << "\nYou choose: \n";
    }

    return 0;
}
