#include <iostream>
#include "sys_api.hpp" 

int main()
{
    std::cout << "================== System API Lab ==================\n"
              << "1. RAII example.\n"
              << "2. Exception example.\n"
              << "3. rlimit example.\n"
              << "4. hash example.\n"
              << "5. unordered map.\n"
              << "6. [PCAP]: example.\n";

    unsigned option;
    std::cout << "\nYou choose: \n";

    while ( std::cin>>option ) {
        switch(option) {
        case 1:
            TEST_RAII_example();
            break;
        
        case 2:
            TEST_exception_example();
            break;
        
        case 3:
            TEST_rlimit();
            break;
        
        case 4:
            TEST_hash();
            break;
       
        case 5:
            TEST_hashtable();
            break;
        
        case 6:
            TEST_pcap_example();
            break;

        default:
            std::cout << "Invalid option.";
            break;
        }
        std::cout << "\nYou choose: \n";
    }

    return 0;
}
