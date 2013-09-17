#include <iostream>
#include "boost_api.hpp" 

int main()
{
    std::cout << "================== Boost Lab ==================\n"
              << "1. Boost asio api.\n"
              << "2. Serialized (Sync'd) IO.\n";

    unsigned option;
    std::cout << "\nYou choose: \n";

    while ( std::cin>>option ) {
        switch(option) {
        case 1:
            TEST_boost_asio_api();
            break;
        
        case 2:
            TEST_boost_serialized_io();
            break;
        
        default:
            std::cout << "Invalid option.";
            break;
        }
        std::cout << "\nYou choose: \n";
    }

    return 0;
}
