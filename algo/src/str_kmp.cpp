/*
    Find string W in string S

    Algorithm:
        1. build partial match table based on string W
        2. start the search from the beginning of s, using m to track the position
            * at position m, match the char in w and s. 
                - if s[m+i] == w[i]
                    - if i is the end of w, match is found, return m
                    - continue to the next char
                - else // s[m+i] != w[i]
                    - update m to start over (m = m+i-T[i])
                    - update i accordingly
                        * i = T[i] iff T[i] != -1
                        * i = 0    iff T[i] == -1   // no backtracking 

    Partial match table T[i]: 
        - The amount of "backtracking" when a mismatch is found.
        - Constructed from the string to search.
            Example: search string W from string S. Partial match table is contructed from string W.
        - Edge case:
            * T[0] = -1;  // if a mismatch is found for 1st char, need to check the next one, no backtracking is needed.
*/

#include <string>
#include <iostream>
#include "algo.hpp"

static void build_kmp_table(std::string s, int* T, int len);

/*
    Search string w in the string s.
    
    Output: the index (0-based) where string w was found.
 */
int string_kmp(std::string s, std::string w)
{
    int w_len = w.length();
    int s_len = s.length();
    int T[w_len];

    build_kmp_table(w, T, w_len);
    
    int m = 0;      // the beginning of current match in s
    int i = 0;      // the position of current character in w

    while (m+i<s_len) {
        if (w[i]==s[m+i]) {
            if (i == w.length()-1)  // match is found
                return m;
            
            i++;
        } else {                    
            m = m+i-T[i];   // T[i] detemines how far backtracking is needed

            if (T[i]>-1)    // not 1st char 
                i = T[i];
            else            
                i = 0;
        }
    }

    return -1;      // string is not found
}

static void build_kmp_table(std::string s, int* T, int len)
{
    T[0] = -1;
    
    if (len==1) 
        return;

    T[1] = 0;

    int pos = 2;
    int cnd = 0;

    while (pos < len) {
        if (s[pos-1] == s[cnd]) {
            cnd++;
            T[pos]=cnd;
            pos++;
        } else if (cnd>0) {
            cnd = T[cnd];
        } else {
            T[pos] = 0;
            pos++;  
        }
    }
}


void TEST_string_kmp()
{
    std::cout<<"TEST KMP string algorithm (find needle in the hay): \n";

    std::string w,s;

    std::cout<<"Enter the needle: \n";
    std::cin>>w;

    std::cout<<"Enter the hay: \n";
    std::cin>>s;

    int idx = string_kmp(s,w);
    if (idx == -1) {
        std::cout << "Cannot find the string.\n";
    } else {
        std::cout << "Find string at idx: " << idx << "\n";
    }
}
