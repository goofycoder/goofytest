#include <iostream>
#include <cstdlib>
#include "algo.hpp" 
#include "linked_list.hpp" 
#if 0
#include "gtest/gtest.h"
#endif

int main()
{
    std::cout << "================== Algorithm Library ==================\n"
              << "1. Prime\n"
              << "2. Palindrome String\n"
              << "3. Palindrome Number\n"
              << "4. Anagram\n"
              << "5. Fibonacci number\n"
              << "6. Reservoir sampling\n"
              << "7. Reverse a singly linked list\n"
              << "8. Test Binary Search Tree\n";

    unsigned option;
    std::cout << "You choose: \n";

    while ( std::cin>>option ) {
        switch(option) {
        case 1:
            TEST_isPrime();
            break;

        case 2:
            TEST_isPalindromeStr();
            break;
        
        case 3:
            TEST_isPalindromeNum();
            break;
        
        case 4:
            TEST_isAnagram();
            break;
        
        case 5:
            TEST_fibo();
            break;
        
        case 6:
            TEST_reservoir_sampling();
            break;
        
        case 7:
            TEST_reverse_list();
            break;
        
        case 8:
            TEST_InsertNode();

            TEST_TreeTraverse();
    
            TEST_TreeAPI();

            TEST_BinarySearch();
            break;
        
        default:
            std::cout << "Invalid option.";
            break;
        }
        std::cout << "You choose: \n";
    }

    return 0;
}

#if 0
// Tests IsPrime()

// Tests negative input.
TEST(IsPrimeTest, Negative) {
    // This test belongs to the IsPrimeTest test case.

    EXPECT_FALSE(IsPrime(-1));
    EXPECT_FALSE(IsPrime(-2));
    EXPECT_FALSE(IsPrime(INT_MIN));
}

// Tests some trivial cases.
TEST(IsPrimeTest, Trivial) {
    EXPECT_FALSE(IsPrime(0));
    EXPECT_FALSE(IsPrime(1));
    EXPECT_TRUE(IsPrime(2));
    EXPECT_TRUE(IsPrime(3));
}

// Tests positive input.
TEST(IsPrimeTest, Positive) {
    EXPECT_FALSE(IsPrime(4));
    EXPECT_TRUE(IsPrime(5));
    EXPECT_FALSE(IsPrime(6));
    EXPECT_TRUE(IsPrime(23));
}
#endif
