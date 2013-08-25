/*
    Algorithm to check whether an integer is a prime number.

    Trivial cases:
        (-inf, 1]:                  NOT prime
        2 and all even numbers:     NOT prime
        3 and all odd number:
            - if (i> (num/i)) : i > square root of num:  is PRIME
            - if  < square root, num can be divided by i, NOT prime
 */

#include "algo.hpp"

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
    
    std::cout << "\n*** TEST for isPrime() ***\n"
              << "Enter an interger: ";

    while (std::cin>>num) {
        if ( isPrime(num) ) {
            std::cout << num << " is a prime.\n";
        } else {
            std::cout << num << " is NOT a prime.\n";
        }

        std::cout << "\nEnter an interger: ";
    }
    
    std::cout << "\nTEST for isPrime() finished.\n";
}
