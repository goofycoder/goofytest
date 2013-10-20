/*
    Robin-Karp pattern search algorithm
    
    Find pattern string p from string s.

    Algorithm:
       1.  Computer the hash value of pattern p:  h_p; 
       2. From s[0] to s[i] (where i+len_p = len_s)
            computer the hash value of substring
       3. If hash values match, the pattern is found

    Complexity:
       Average and best case: O(n+m)    // n: length of text, m: length of pattern
       Worst case: O(n*m)               // every hash has collison 

    Note: Good for multiple match search
 */

#include <iostream>
#include "algo.hpp"     // for fast_pow()

const int base = 97;    // used to compute the hash value of 
                        // large prime number (not necessarily 97)

static int hash(std::string s, int pos, int len);

bool str_search_robin_karp(std::string str, std::string pattern)
{
    int str_len = str.length();
    int pattern_len = pattern.length();
    int pattern_hash = hash(pattern, 0, pattern_len);
    int str_hash = hash(str, 0, pattern_len); 

    bool flag = false;
    
    for (int i=0; i<=str_len-pattern_len; i++) {
        if (i!=0) {     // i==0 case: pre-computed, no need to update
            // update hash value of the substring to compare
            // idea of rolling hash
             str_hash = (str_hash - str[i-1]*fast_pow(base, pattern_len-1))*base 
                        + str[i+pattern_len-1];
        }

        if (str_hash == pattern_hash) {
            flag = true;
            std::cout << "Match found. Starting at " << i << "\n";  
        }
    }

    return flag;
}

static int hash(std::string s, int pos, int len)
{

    int result = 0;
    int k = len-pos-1;

    for (int i=pos; i<pos+len; i++) {
        result += s[i] * fast_pow(base, k);
        k--;
    }

    return result;
}

void TEST_str_search_robin_karp()
{
    std::cout << "TEST: string pattern search using Robin Karp algorithm.\n";

    std::string str;
    std::string pattern;
    
    std::cout << "Enter the string: \n";
    std::cin >> str;

    std::cout << "Enter the pattern: \n";
    std::cin >> pattern;

    if (!str_search_robin_karp(str, pattern)) {
        std::cout << "No match found.\n";
    }
}
