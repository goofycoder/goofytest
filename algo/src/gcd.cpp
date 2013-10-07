/* 
    Greatest Common Divider
 */
#include <iostream>

int gcd(int a, int b) 
{
    if (a==0 || b==0)
        return -1;
    
    while (a!=b) {
        if (a>b)
            a-=b;
        else
            b-=a;
    }

    return a;
}

void TEST_gcd()
{
    std::cout << "Test Greatest Common Divider algorithm.\n";
    
    int a,b;

    std::cout << "Enter two integers (A, B):\n";
    std::cout << "Enter A: ";
    std::cin >> a;

    std::cout << "Enter B: ";
    std::cin >> b;

    std::cout << "The greatest common divider is " << gcd(a,b) << "\n";
}
