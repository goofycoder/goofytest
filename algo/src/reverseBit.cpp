/*
    reverse the bit in unsigned integer

    Example:
        22 (10110) ==> 13 (01101)
        11 (1011)  ==> 13 (1101)
        3  (11)    ==> 3  (11)
        1  (1)     ==> 1  (1)
*/

#include "algo.hpp"

void reverseBit(unsigned &input) 
{
    unsigned numOfBits = getNumOfBits(input);
   
    for (unsigned i=0; i<numOfBits/2; i++) {
        swapBit(input, numOfBits-1-i, i);   
    }
}

unsigned getNumOfBits(const unsigned input)
{
    unsigned testBit = 1;   
    unsigned leftPos = 0; 

    for(unsigned i=0; i<sizeof(input)*8-1; i++) {
        if ( input&testBit ) {
            leftPos = i;
        } 
        
       testBit *= 2;
    }

    return leftPos+1;
}

void swapBit(unsigned &input, unsigned left, unsigned right) 
{
    unsigned leftBit  = (input>>left) & 1;
    unsigned rightBit = (input>>right) & 1; 

    if (leftBit^rightBit) {
        //toggle both bits for swap
        input ^= (1<<left);
        input ^= (1<<right);
    }
}

void TEST_reverseBit()
{
    std::cout << "\n*** TEST for reverseBit() ***\n"
              << "Enter an interger: ";

    unsigned num;
    std::cin>>num;

    std::cout << "Interger before reverseBit(): " << num << "\n";
    reverseBit(num);

    std::cout << "Interger after reverseBit(): " << num << "\n";
}

