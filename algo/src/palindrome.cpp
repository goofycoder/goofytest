/*
    A palindrome is a word, phrase, number, or other sequence of symbols or elements, 
    whose meaning may be interpreted the same way in either forward or reverse direction

    Palindrome string (e.g.: abccba)
        Algorithm:
            1. Two ptrs point at head and tail of the string.
            2. The head-ptr traverses forward and tail-ptr traverses backwards
            3. Till the head-ptr reaches the end of string '\0', the chars two ptrs point at should 
               be same all the time.
  ===============================================================
    Palindrome number:
        - example: 1221, 787
        (Decimal, or hex?  negative? ask for clarification)
    
    Algorithm:
        step 1: start from most and least significant digits in the number
        step 2: if these two are same, remove these two digits from the number
        step 3: continue to go back to step 1 until the number becomes 0, 
                then it is palindrome number.
*/

#include "algo.hpp"

bool isPalindromeNum(int x) 
{   
    if (x < 0) 
        return false;
    
    int div = 1;
    while (x / div >= 10) {
        div *= 10;
    }
            
    while (x != 0) {
        int l = x / div;        // most significant digit (ex: 7 in 789)
        int r = x % 10;         // least signifcant digit (ex: 9 in 789)
        if (l != r)         
            return false;
        
        x = (x % div) / 10;     // ex: 789, div: 100, x update to 8
        div /= 100;             // chop both most and least significant bits
                                // thus divided by 100
    }

    return true;
}

bool isPalindromeStr(const std::string& str) {
    if (str.empty()) 
        return false;

    const char *p = &str[0];
    const char *q = &str[str.length()-1];
    
    while ( *p != '\0') {
        if (*p != *q) {
            return false;
        } else {
            p++;
            q--;
        }
    }

    return true;
}

void TEST_isPalindromeStr()
{
    std::string str;
    
    std::cout << "\n *** TEST for Palindrome String ***\n"
              << "Enter a string: ";

    while (std::cin>>str) {
        if ( isPalindromeStr(str) ) {
            std::cout << str << " is a palindrome.\n";
        } else {
            std::cout << str << " is NOT a palindrome.\n";
        }

        std::cout << "\nEnter a string: ";
    }
    
    std::cout << "\nTEST for Palindrome String finished.\n";
}


void TEST_isPalindromeNum()
{
    int num;
    
    std::cout << "\n *** TEST for Palindrome Number ***\n"
              << "Enter an integer: ";

    while (std::cin>>num) {
        if ( isPalindromeNum(num) ) {
            std::cout << num << " is a palindrome number.\n";
        } else {
            std::cout << num << " is NOT a palindrome.\n";
        }

        std::cout << "\nEnter an integer: ";
    }
    
    std::cout << "\nTEST for Palindrome number finished.\n";
}
