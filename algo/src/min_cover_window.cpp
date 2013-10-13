/*
    Find a minimum window in string S that contains all chars in string T

    Complexity: O(n)    // n is the length of string S
    
    Algorithm:
        Needs two tables:
            - needToFind[NUM_CHAR]
            - hasFound[NUM_CHAR]
        
        The window is defined by two ptrs:
            - begin, end. (both initialized to 0)

        Step 1:  build needToFind[] table based on string T
        Step 2:  scan the string S ( by moving the 'end' ptr)
            - skip the char that is not in needToFind[] table
            - if find a char that belongs to T
                * update hasFound[] table
                * update count
        Step 3: reach a point that count == the length of T
            - this means a potential window is found (not necessary the minimum one)
            - try to shrink the window by moving the 'begin' ptr
                * as long as it does not impact the fact that contains all char in T
 */
#include <iostream>
#include <string>
#include <climits>      // INT_MAX (32767)

const int NUM_CHAR = 256;

bool min_cover_window(std::string& s, std::string& t,
                             int& w_left, int& w_right)
{
    // build needToFind table from string T
    int needToFind[NUM_CHAR] = {0};
    for(int i=0; i<t.length(); i++) {
        needToFind[t[i]]++;
    }

    int hasFound[NUM_CHAR] = {0};
    int begin = 0;
    int end = 0;
    int count = 0;              // count the number of matched chars
    int minWinLen = INT_MAX;
    
    for(; end<s.length(); end++) 
    {
        // skip the char that is not in T
        if (needToFind[s[end]] == 0) 
            continue;

        // found a char interested in        
        // update hasFound[] and count
        hasFound[s[end]]++;
        if (hasFound[s[end]] <= needToFind[s[end]]) 
            count++;

        // found a window that contains all chars in T 
        // (but not necessary the minimum one)
        if (count == t.length()) {
            // advance the 'begin' ptr as far as possible
            // Two cases that 'begin' ptr could advance:
            //      1. s[begin] is not in T , or
            //      2. s[begin] has more than required
            while (needToFind[s[begin]]==0 ||
                   hasFound[s[begin]] > needToFind[s[end]] ) 
            {
                if (hasFound[s[begin]] > needToFind[s[end]]) {
                    hasFound[s[begin]]--;
                }

                begin++;
            }

            //update the result (min window)
            if (end-begin+1 < minWinLen) {
                minWinLen = end-begin+1;
                w_left = begin;
                w_right = end;                
            }
        }
    }

    // return whether a window is found
    if (count == t.length())
        return true;
    else
        return false;
}

void TEST_min_cover_window()
{
    std::cout << "TEST minimum substring (window) in string S that contains all chars in string T\n";

    std::string s,t;
    std::cout << "Enter string S: \n";
    std::cin >> s;

    std::cout << "Enter string T: \n";
    std::cin >> t;

    int w_left = 0;
    int w_right = 0;

    if (min_cover_window(s, t, w_left, w_right)) {
        std::string w = s.substr(w_left, w_right-w_left+1);
        std::cout << "The min window is: " << w << "\n"
              << "Range is [" << w_left << "," << w_right << "].\n";
    } else {
        std::cout << "No minimum window is found.\n";
    }
}
