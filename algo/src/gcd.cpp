/* 
    Greatest Common Divider

    Euclid's algorithm:
        gcd(a,b) = 
            gcd(a,0) = a;
            gcd(a,b) = gcd(b, a%b);

    If a>0 and b>0: 
        gcd(a,b) :
            gcd(a,a) = a
            gcd(a,b) = gcd(a-b,b)       // if a>b
            gcd(a,b) = gcd(a, b-a)      // if b>a
 */
#include <iostream>

int gcd_e(int a, int b)
{
    if (b==0)
        return a;

    return gcd_e(b, a%b);
}

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
    std::cout << "The greatest common divider (Euclid's algorithm) is " << gcd_e(a,b) << "\n";
}
