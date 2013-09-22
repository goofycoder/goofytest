/*  
    Some bit operation functions:
        - check whether an integer is a power of 2 (AND)
        - check whether two integers have opposite sign (XOR)
 */

#include <iostream>

bool powerOfTwo(int n)
{
    if ( (n&(n-1))==0 ) 
        return true;
    else 
        return false;
}

bool opposite_sign(int x, int y)
{
    if ( (x^y) < 0) 
        return true;
    else 
        return false;
}

void TEST_bit_op()
{
    std::cout << "TEST basic bit operations\n";

    std::cout << "\n[Bit op]: test whether two integers have opposite signs\n";
    int n1, n2;
    std::cout << "Enter 1st int: ";
    std::cin >> n1;
    std::cout << "Enter 2nd int: ";
    std::cin >> n2;
    
    if (opposite_sign(n1, n2)) {
        std::cout << "Opposite sign.\n";
    } else {
        std::cout << "Not opposite sign.\n";
    }
    
    std::cout << "\n[Bit op]: test whether the integer is power of 2.\n";
    std::cout << "Enter an interger:";
    int n;
    std::cin >> n;

    if (powerOfTwo(n)) {
        std::cout << "Is a power of 2.\n";
    } else {
        std::cout << "NOT a power of 2.\n";
    }
}
