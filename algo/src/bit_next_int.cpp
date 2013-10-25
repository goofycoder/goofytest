/*
    Given an integer, compute the next/previous int that has same number of 1s. 

    Algorithm is inline.

    Date: 10/25/2013
 */
#include <iostream>

// find the next int with same number of bit 1 set
int bit_next_int(const int d)
{
    const int NUM_BITS = 32;
    int res=d;
    /*
        start with least significant bit,
        find the first 0 after finding 1
        flip the first 0 to 1 and change the trailing 1 to be 0
        Example:
            10110(22)  ==>  11010(26)
    */
    bool one_found = false;

    for(int i=0; i<NUM_BITS; i++) {
         if ( (res>>i & 1) == 1 && !one_found) {
            one_found = true;
            continue;
        }

        if ( (res>>i & 1) == 0 && one_found) {
            // set the current bit(0) to be 1
            res |= 1<<i;
        
            // set the trailing bit to be 0
            res &= ~(1<<(i-1));
            return res;
        }
    }
}

// find the prev int with same number of bit 1 set
int bit_prev_int(const int d)
{
    int res = d;
    const int NUM_BITS = 32;
    // starting with the least significant bit
    // find the first 1 after finding 0
    // flip the first 1 to 0, and changing the trailing 0 to 1
    bool zero_found = false;

    for (int i=0; i<NUM_BITS; i++) {
        if ( (res>>i & 1) == 0 && !zero_found ) {
            zero_found = true;
            continue;
        }

        if ( (res>>i & 1) == 1 && zero_found) {
            res ^= 1<<i;
            res |= 1<<(i-1);
            return res;
        }
    }
}

void TEST_bit_next_int()
{
    std::cout << "TEST next int with bit operation.\n";

    int d;
    std::cout << "Enter the input integer: ";
    std::cin >> d;

    int next_int = bit_next_int(d);
    std::cout << "Next int with same number of 1s: " << next_int << "\n";

    int prev_int = bit_prev_int(d);
    std::cout << "Prev int with same number of 1s: " << prev_int << "\n";
}
