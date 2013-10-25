/*
    Input:
        integer: base
        integer: pattern
        bit position: start and end
    Output:
        set the position in 'base' from start to end, to be pattern.

    Algorithm:
        1. clear the bits between start and end. (using mask)
        2. bit-or with the pattern

    Date: 10/25/2013
 */

#include <iostream>
#include "algo.hpp"

/* Set the bits starting from postion [start, end] to be the bits in pattern (ptn) */
int bit_set_pattern(int base, int ptn, int start, int end)
{
    // clear the region (set to 0) starting from pos with length len
    int res =  bit_clear_bits(base, start, end);

    // set the pattern
    return res|(ptn<<start);
}

/* set the bits, from start to end, in an integer to 0 */
int bit_clear_bits(int base, int start, int end)
{
    // mask:  10...0011..11
    //        (e)  (s)
    int all_one = ~0;      // all '1'

    // compute the mask:
    //  1.  11..111 ==>  11..100...00       
    //  2.  11..100..00 ==> 11..10..011..11
    int left = all_one - ((1<<end)-1);
    int right = ((1<<start)-1);
    int mask = left|right;
    
    return base&mask;
}


void TEST_bit_set_pattern()
{
    std::cout << "TEST the algorithm to set certain bits to be the pattern.\n";

    int base, pattern;
    std::cout << "Enter the input int: ";
    std::cin >> base;

    std::cout << "Enter the pattern int: ";
    std::cin >> pattern;

    int start, end;
    std::cout << "Enter the start position to set pattern: \n";
    std::cin >> start;
    std::cout << "Enter the end position to set pattern: \n";
    std::cin >> end;

    if (start>end) {
        std::cout << "Invalid range. (start must be less than end).\n";
        return;
    }

    std::cout << base << ": ";
    print_int_by_bit(base);
   
    std::cout << pattern << ": ";
    print_int_by_bit(pattern);

    int result = bit_set_pattern(base, pattern, start, end);
    std::cout << "Result: " << result << "\n";
    print_int_by_bit(result);
}
