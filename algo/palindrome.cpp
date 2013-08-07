/*
    A palindrome is a word, phrase, number, or other sequence of symbols or elements, 
    whose meaning may be interpreted the same way in either forward or reverse direction

    Palindrome string (e.g.: abccba)
        Algorithm:
            1. Two ptrs point at head and tail of the string.
            2. The head-ptr traverses forward and tail-ptr traverses backwards
            3. Till the head-ptr reaches the end of string '\0', the chars two ptrs point at should 
               be same all the time.

    Palindrome number:
        12321
        (Decimal, or hex?  negative? ask for clarification)
*/

#include <iostream>
#include <string>

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
    
    std::cout << "\nTEST for isPalindrome():\n"
              << "Enter a string: ";

    while (std::cin>>str) {
        if ( isPalindromeStr(str) ) {
            std::cout << str << " is a palindrome.\n";
        } else {
            std::cout << str << " is NOT a palindrome.\n";
        }

        std::cout << "\nEnter a string: ";
    }
    
    std::cout << "\nTEST for isPalindromeStr() finished.\n";
}
