/*
    Ugly numbers are numbers whose only prime factors are 2, 3 or 5. 
    
    Example: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, …
    
    The function gets the N-th ugly number.

    Algorithm:
        1. create a N length array ugly_num[N]. ugly_num[0] = 1.
        2. Maintain 3 buffer for comparison:
            next_2 = 2;
            next_3 = 3;
            next_5 = 5;
           Also maintain three indexes for idx_2, idx_3, idx_5 (initialized to 0)
        3. Get the min of (next_2, next_3, next_5). The min of three fills ugly_num[i];
        4. Update (next_2, next_3, next_5) and update idx_2, idx_3 and idx_5, accordingly.
 */
#include <iostream>
#include "algo.hpp"

unsigned ugly_number(unsigned n)
{
    if (n<=0) {
        std::cout << "Invalid input.\n";
        return 0;
    }

    unsigned* ugly_num = new unsigned[n];

    ugly_num[0] = 1;

    int idx_2 = 0;
    int idx_3 = 0;
    int idx_5 = 0;

    unsigned next_2 = 2;
    unsigned next_3 = 3;
    unsigned next_5 = 5;

    unsigned next_ugly;

    for(unsigned i=1; i<n; i++) {
        next_ugly = minOfThree(next_2, next_3, next_5);
        ugly_num[i] = next_ugly;
        std::cout << next_ugly << std::endl;

        if (next_ugly == next_2) {
            idx_2++;
            next_2 = ugly_num[idx_2]*2;
        }

        if (next_ugly == next_3) {
            idx_3++;
            next_3 = ugly_num[idx_3]*3;
        }

        if (next_ugly == next_5) {
            idx_5++;
            next_5 = ugly_num[idx_5]*5;
        }
    }

    return ugly_num[n-1];
}

void TEST_ugly_number()
{
    std::cout << "TEST ugly number.\n";

    unsigned N;
    std::cout << "Enter the N (to get N_th ugly number):";
    std::cin >> N;

    unsigned ugly_num = ugly_number(N);
    std::cout << "The " << N << "_th ugly number is " << ugly_num << "\n";  
}

