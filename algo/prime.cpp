#include <iostream>

bool isPrime(const int& num)
{
    /* 1 or less */
    if ( num<=1 )   
        return false;

    /* 2 and even number */
    if ( num%2 == 0) {
        return (num == 2);          // nice trick:)
    }

    /* >=2 and odd */
    for (unsigned i = 3; ; i+=2) {
        if ( i > num/i ) {
            return true;
        } else {
            if ( num%i == 0 ) 
                return false;
        }
    }
}

void TEST_isPrime()
{
    int num;
    
    std::cout << "\nTEST for isPrime():\n"
              << "Enter a interger: ";

    while (std::cin>>num) {
        if ( isPrime(num) ) {
            std::cout << num << " is a prime.\n";
        } else {
            std::cout << num << " is NOT a prime.\n";
        }

        std::cout << "\nEnter a interger: ";
    }
    
    std::cout << "\nTEST for isPrime() finished.\n";
}


