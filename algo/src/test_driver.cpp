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
                    \t3) getInorderSuccessor node\n \
                    \t4) Check whether the tree is balanced.\n"
              << "27. [BST] delete a node from BST.\n"
              << "28. #unique paths from left-upper to bottom-right in table.\n"
              << "29. List all the permutation of a string. (both Dup and Non-Dup algorithm.\n"
              << "30. Split the linked list to half.\n"
              << "31. Compute the square root of an int\n"
              << "32. Max in the sliding window of int array.(crash)\n"
              << "33. Mirror of BST.\n"
              << "34. Ugly number.\n"
              << "35. Test basic bit operations.\n \
                    \t1) check whether an integer is a power of two.\n \
                    \t2) check whether two integers have opposite sign\n"
              << "36. Replace the space in a string with pattern.\n"
              << "37. Longest palindrome substring in a string.\n"
              << "38. KMP string search algorithm.\n"
              << "39. Reverse C-string.\n"
              << "40. Greatest Common Divider.\n"
              << "41. Regex match.\n"
              << "42. Circular list.\n"
              << "43. Longest substring without dup character.\n"
              << "44. [BST]: convert BST to circular doubly-linked-list.\n"
              << "45. [STR]: minimum window(substring) in S contains all chars in string T.\n"
              << "46. Print all combination of balanced parenthesis.\n"
              << "47. Compute Divide and Mod without division.\n"
              << "48. [STR] Display the first no-dup char in char stream.\n"
              << "49. Given a target number, print all sum combinations to target.\n"
              << "50. [NUM] Fast pow(m,n).\n"
              << "51. [STR] String pattern search using Robin Karp algorithm.\n"
              << "52. [MTX] Matrix rotation (Rotate N*N matrix 90 degree clockwise).\n"
              << "53. [MTX] Matrix: set entire row/column to zero if there is one element in row/column is zero.\n"
              << "54. [STR] Remove duplicate char in a string (in place).\n"
              << "55. [STL] Unordered map.\n"
              << "56. [LST] Add two linked list as two integers.\n"
              << "57. [STK] Implement Queue using two stacks.\n"
              << "58. [STK] Sort a stack.\n"
              << "59. [GRH] Undirected Graph.\n"
              << "60. [BST] Check whether one BST is another BST's subtree.\n"
              << "61. [BIT] Set a bit region in an integer to be certain pattern.\n"
              << "62. [BIT] Find the next/prev int with same number of 1s set.\n"
              << "63. [BIT] Swap Even-Odd bits in an integer.\n"
              << "64. [ARR] Search key in a rotated and sorted int array.\n"
              << "65. [ARR] Find a pair of integers that sum up to a given sum.\n";

    unsigned option;
    std::cout << "\nYou choose: \n";

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
        
        case 28:
            TEST_unique_path();
	        break;

        case 29:
            TEST_str_permute();
	        break;
        
        case 30:
            TEST_split_list();
	        break;
        
        case 31:
            TEST_isqrt();
	        break;
        
        case 32:
            TEST_slide_window_max();
	        break;
        
        case 33:
            TEST_bst_mirror();
	        break;

        case 34:
            TEST_ugly_number();
	        break;
        
        case 35:
            TEST_bit_op();
	        break;
        
        case 36:
            TEST_str_replace_space();
	        break;
        
        case 37:
            TEST_longestPalindrome();
	        break;
        
        case 38:
            TEST_string_kmp();
	        break;
        
        case 39:
            TEST_str_reverse();
	        break;
        
        case 40:
            TEST_gcd();
	        break;
        
        case 41:
            TEST_regex();
	        break;
        
        case 42:
            TEST_circular_sorted_list();
	        break;
        
        case 43:    
            TEST_longest_substr_no_dup();
	        break;

        case 44:
            TEST_convertToDoublyList();
            break;
        
        case 45:
            TEST_min_cover_window();
            break;
        
        case 46:
            TEST_print_parenthesis();
            break;
        
        case 47:
            TEST_divide_and_mod();
            break;
        
        case 48:
            TEST_stream_no_dup_char();
            break;
        
        case 49:
            TEST_sum_subset();
            break;
        
        case 50:
            TEST_fast_pow();
            break;
        
        case 51:
            TEST_str_search_robin_karp();
            break;

        case 52:
            TEST_rotate_matrix();
            break;
        
        case 53:
            TEST_matrix_set_zero();
            break;
        
        case 54:
            TEST_str_remove_dup_char();
            break;
        
        case 55:
            TEST_unordered_map();
            break;
        
        case 56:
            TEST_linked_list_add();
            break;
        
        case 57:
            TEST_MyQ();
            break;
        
        case 58:
            TEST_sort_stack();
            break;
        
        case 59:
            TEST_undirected_graph();
            break;
        
        case 60:
            TEST_subtree();
            break;
        
        case 61:
            TEST_bit_set_pattern();
            break;
        
        case 62:
            TEST_bit_next_int();
            break;
        
        case 63:
            TEST_swap_even_odd_bits();
            break;
        
        case 64:
            TEST_search_rotate_array();
            break;
        
        case 65:
            TEST_find_pair_to_sum();
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
