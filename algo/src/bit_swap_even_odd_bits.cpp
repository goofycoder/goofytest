/*
    Swap the even and odd bits in the integer.

    Key:
        choose the right mask for even bits (0x55555555) and odd bits (0xAAAAAAAA)
 */

#include <iostream>
#include "algo.hpp"

void swap_even_odd_bit(int& num)
{
    num = ((num&0xAAAAAAAA) >> 1) | ((num&0x55555555) << 1);
}


void TEST_swap_even_odd_bits()
{
    std::cout << "TEST swap even odd bits.\n";

    std::cout << "Enter input integer: \n";
    int num;
    std::cin >> num;

    std::cout << "Before swap: ";
    print_int_by_bit(num);

    swap_even_odd_bit(num);

    std::cout << "After swap: ";
    print_int_by_bit(num);
}
