/*
    Divide two integers without using multiplication, division and mod operator.
 */
#include <iostream>

void divide_and_mod(int a, int b,
                    int& q,     // output: quotient 
                    int& r)     // output: remainder
{
    do {
        a -= b;
        q++;
    } while(a>=b);

    r = a;    
}

void TEST_divide_and_mod()
{
    std::cout << "TEST: divide and mod of two integers without using division.\n";

    int a, b;
    std::cout << "Enter 1st integer: ";
    std::cin >> a;

    std::cout << "Enter 2nd integer (<= 1st one): ";
    std::cin >> b;

    int q = 0;
    int r = 0;

    divide_and_mod(a, b, q, r);

    std::cout << "Quotient: " << q << "\n";
    std::cout << "Remainder: " << r << "\n";
}
