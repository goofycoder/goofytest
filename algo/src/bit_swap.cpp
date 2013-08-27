/*
 *  Inut: 2 integers  i1 and i2
 *  Output: the number of bits need to be changed from i1 to i2
 *
 *  Algorithm:  XOR the two number and check how many bits are 1
 */
#include <iostream>
#include "algo.hpp"

int bitSwap(int num_1, int num_2)
{
    return countBitOne(num_1^num_2);
}

int countBitOne(int num)
{
    unsigned mask = 1;
    int rv = 0;

    for(unsigned i=0; i<sizeof(int)*8-1; i++) {
        if (num & mask) {
            rv++;
        }
        mask <<= 1;
    }

    return rv;
}

void TEST_bitSwap()
{
    int num_1, num_2;

    std::cout << "\nEnter 1st integer: ";
	std::cin >> num_1;
    
    std::cout << "\nEnter 2nd integer: ";
	std::cin >> num_2;


    unsigned diff_bits = bitSwap(num_1, num_2);

	std::cout << "The number of diff bits: " << diff_bits << "\n";
}
