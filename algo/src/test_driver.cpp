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
              << "8. Test Binary Search Tree\n"
              << "9. Longest non-repeatable-char substr\n"
              << "10. Longest common sequence\n"
              << "11. Max sum in the array\n"
              << "12. Rotate the string\n"
              << "13. Reverse the bits in the unsigned integer\n"
              << "14. Least Common Ancestor of two nodes in BST\n"
              << "15. Edit distance btwn two strings\n"
              << "16. Rejection sampling\n"
              << "17. Prettyprint a BST\n"
              << "18. Minimum K elements in the stream (Top-K, heap)\n"
              << "19. Number of diff bits between 2 integeres\n"
              << "20. Find whether singly linked list has a loop\n"
              << "21. delete Nth node in the singly list\n"
              << "22. rectangle overlap?\n"
              << "23. the stack that pops minimum in constant time.\n"
              << "24. remove space in string.\n"
              << "25. intersection of two sorted array.\n"
              << "26. [BST] Misc APIs: \n \
                    \t1) get numOfChild of a node.\n \
                    \t2) get Parent node. \n  \
                    \t3) getInorderSuccessor node\n"
              << "27. [BST] delete a node from BST.\n";

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
        
        case 9:
            TEST_longestSubstr();        
            break;

	    case 10:
            TEST_LongestCommonSeq();        
	        break;
	    
        case 11:
            TEST_maxSum();        
	        break;

        case 12:
            TEST_rotateStr();        
	        break;
        
        case 13:
            TEST_reverseBit();        
	        break;
        
        case 14:
            TEST_lca();        
	        break;
        
        case 15:
            TEST_editDistance();        
	        break;
        
        case 16:
            TEST_rejection_sampling();        
	        break;
        
        case 17:
            TEST_prettyprintBST();        
	        break;
        
        case 18:
            TEST_min_k();        
	        break;
        
        case 19:
            TEST_bitSwap();        
	        break;
        
        case 20:
            TEST_find_loop();        
	        break;
        
        case 21:
            TEST_linked_list();        
	        break;
        
        case 22:
            TEST_rectangle_overlap();        
	        break;
        
        case 23:
            TEST_min_stack();        
	        break;
        
        case 24:
            TEST_removeSpaceInStr();        
	        break;
        
        case 25:
            TEST_intersectionOfSortedArray();
	        break;
        
        case 26:
            TEST_BST_API();
	        break;
        
        case 27:
            TEST_BST_deleteNode();
	        break;
        
        default:
            std::cout << "Invalid option.";
            break;
        }
        std::cout << "\nYou choose: \n";
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
