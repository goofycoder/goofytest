/*
   Longest Substring Without Repeating Characters
   
   Given a string, find the length of the longest substring without repeating characters.
        Example: 
            1. longest substring w/o repeating letters for “abcabcbb” is “abc” (length=3). 
            2. For “bbbbb”, the longest substring is “b”, with the length of 1.

   Algorithm:
        1. build auxiary table: exist[NUM_OF_CHAR] to record whether the char exists

   Time complexity
        O(n): just scan through the string should yield the result.
 */


#include "algo.hpp"

const unsigned NUM_OF_CHAR = 256;

int longestSubstr(const std::string& s) 
{
    int n = s.length();
    int i = 0, j = 0;
    int maxLen = 0;     // maxLen of substr
    int start = 0;      // starting pos in s as longest substr
    int end = 0;        // ending pos in s as longest substr

    bool exist[NUM_OF_CHAR] = { false };

    while (j < n) {
        
        if (exist[s[j]]) {
            //maxLen = max(maxLen, j-i);

            if ((j-i) > maxLen) {
                maxLen = j-i;
                start = i;
                end = j;                
            }        
        
            /* move i to the dup char */
            while (s[i] != s[j]) {
                exist[s[i]] = false;
                i++;
            }

            /* start with the char after the dup char */
            i++;    
        } else {
            exist[s[j]] = true;
        }
        
        j++;
    }

    //maxLen = max(maxLen, j-i);
    if ((j-i) > maxLen) {
        maxLen = j-i;
        start = i;
        end = j;                
    }

    // print out the longest substring
    std::string res(s, start, end-start);
    std::cout << "Longest No-repeated-char Substr is: " << res << " ";

    return maxLen;
}

void TEST_longestSubstr()
{
    std::string str;
    
    std::cout << "\n *** TEST for Longest SubString ***\n"
              << "Enter a string: ";

    while (std::cin>>str) {
        int len = longestSubstr(str);
        std::cout << " (len: " << len << ")\n";

        std::cout << "\nEnter a string: ";
    }
}
