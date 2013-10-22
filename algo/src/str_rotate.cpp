/*  
    Rotate the string s at position i (In place)
        Algorithm:
            reverse the string [0, i-1];
            reverse the string [i, n-1];
            reverse teh string [0, n-1];
        
    Check whether string s1 is the rotation of string s2
        Example:
            s1: bcda   s2: abcd   ==> s1 is rotation of s2

        Algorithm:
          * check the length of s1, s2 (if not equal, return false)    
                - this check is necessary for the case:
                    s1: abcd    s2: abc
          * concat s1 with s1 
                find s2 in s1+s1. if found, return true
 */
#include <iostream>
#include <string>
#include "algo.hpp"

void rotateStr(std::string& str, const unsigned i) 
{
    if (i==0) 
        return;

    unsigned len = str.length();

    reverseStr(str, 0, i-1);
    reverseStr(str, i, len-1);

    reverseStr(str, 0, len-1);
}

void reverseStr(std::string& str, int bgn, int end)
{
    while (bgn<end) {
        swapChar(str[bgn], str[end]);
        bgn++;
        end--;
    }
}

// check whether s1 is a rotation of s2
bool isRotation(std::string& s1, std::string& s2)
{
    if (s1.length() != s2.length()) 
        return false;

    return str_search_robin_karp(s1+s1, s2);
}

void TEST_rotateStr()
{
#if 0
    std::string str;

    std::cout << "\n *** TEST for String rotation***\n"
              << "Enter a string: ";
    std::cin>>str;

    unsigned pos;
    std::cout << "Enter the postion in the string to rotate: ";
    std::cin>>pos;

    std::cout << "String before rotation: " << str << "\n";
    rotateStr(str, pos); 
    std::cout << "String after rotation: " << str << "\n";
#endif

    std::cout << "TEST: whether string s1 is a rotation of string s2.\n";

    std::string s1, s2;
    std::cout << "Enter string s1: \n";
    std::cin >> s1;

    std::cout << "Enter string s2: \n";
    std::cin >> s2;

    if (isRotation(s1, s2)) {
        std::cout << "Is Rotation.\n";
    } else {
        std::cout << "Is NOT rotation.\n";
    }
}
