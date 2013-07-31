/*
 *  Inut: 2 integers  i1 and i2
 *  Output: the number of bits need to be changed from i1 to i2
 *
 *  Algorithm:  XOR the two number and check how many bits are 0
 */

#include <iostream>
#include <cstdlib>

#define DEBUG

int bit_swap(int num_1, int num_2)
{
	unsigned int mask = 1;
	int ctr = 0;	
	int tmp = num_1^num_2;
	std::cout << "XOR of num_1 and num_2: "
	          << tmp << std::endl;

	for(unsigned int i=0; i< 31; i++) {	// all bits need to be same (including sign bit
		if ( (tmp&mask) == mask) {      // this means tmp bit must be 0
#ifdef DEBUG
			std::cout << "mask: "<< mask << std::endl;
#endif
			ctr++;
		}
		mask <<= 1;
	}
	return ctr;
}

int main(int argc, char* argv[])
{
    unsigned int diff_bits = 0;    

	if (argc != 3) {
		std::cout << "Usage: ./bit_swap <input1> <input2>.\n";
        return -1;
	}
	
	int num_1 = atoi(argv[1]);
	int num_2 = atoi(argv[2]);

    diff_bits = bit_swap(num_1, num_2);
	std::cout << diff_bits << std::endl;

	return 0;
}
