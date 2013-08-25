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
    unsigned testBit = 1U;   
    unsigned highPos = 0; 

    for(unsigned i=0; i<sizeof(input)*8-1; i++) {
        if ( input&testBit ) {
            highPos = i;
        } 
        
       testBit *= 2;
    }

    return highPos+1;
}

void swapBit(unsigned &input, unsigned high, unsigned low) 
{
    unsigned highBit = (input>>high) & 1;
    unsigned lowBit  = (input>>low) & 1; 

    if (highBit^lowBit) {
        //toggle both bits for swap
        input ^= (1U<<high);
        input ^= (1U<<low);
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

