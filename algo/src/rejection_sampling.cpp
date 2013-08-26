/*
    Given a function which generates a random integer in the range 1 to 7, 
    write a function which generates a random integer in the range 1 to 10 uniformly.
    
    Algorithm:
        1.run rand7() function twice, as they are not enough numbers in the range of 1 to 10. 
          By running rand7() twice, we can get integers from 1 to 49 uniformly.
        2. Since 7*7 is not a multiple of tens, we have to use rejection sampling. 
          The desired range is integers from 1 to 40. If not (the integer falls between 41 to 49), reject it and repeat the process.
 */
#include "algo.hpp"

int rand10() {
    int row, col, idx;

    do {
        row = rand7();
        col = rand7();
   
        idx = row + (col-1)*7;
    } while (idx > 40);

    return 1+(idx-1)%10;
}

int rand7() {
    srand(time(NULL));
    
    return rand()%7+1;      // [1,7]
}

void TEST_rejection_sampling() 
{
    std::cout << "\n *** TEST for Rejection Sampling ***\n";
        
    std::cout << "Generated the random number [1,10] using rand7() is: " << rand10() << "\n";
}
