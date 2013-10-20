/* 
    Fast version of pow(m,n);

    Divide and Conquer
 */
#include <iostream>

int fast_pow(int m, int n)
{
    if (n==0)
        return 1;

    if (n%2 == 0) 
        return fast_pow(m, n/2) * fast_pow(m, n/2);
    else 
        return m * fast_pow(m, n/2) * fast_pow(m, n/2);
}

void TEST_fast_pow()
{
    std::cout << "TEST fast exponential.\n";

    int m, n;
    std::cout << "Enter the base: ";
    std::cin >> m;

    std::cout << "Enter the exponential: ";
    std::cin >> n;

    std::cout << "The result: " << fast_pow(m, n) << "\n";
}
