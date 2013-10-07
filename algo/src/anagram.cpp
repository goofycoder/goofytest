/*
    Anagram:
        Rearrange the letters of a word or phrase to produce a new word or phrase, 
        using all the original letters exactly once.

    Example:
        mary <==> army

    Algorithm:
    1) Compute and compare the *signature* of two strings, i.e., counting characters ( O(n)) 
        1. assumes that the set of possible characters in both strings is small.
        2. count the occurance of each char
        3. the count of each char should equal in two strings
    2) sort string (O(logn))
        - sort both strings and compare the sorted string

    **** Extension ****
        - Given an input word, find all the anagrams in a dictionary
        - Solution:
            Step 1: compute the signature of the given word
            Step 2: read the dictionary sequentially and compute the signature of the word in dictionary and compare with the one of the given word.
        - Better solution (if preprocessing of the dictionary is allowed)
            Step 1: preprocess the dictionary 
                    (signature, word) pair sorted by signature)
            Step 2: perform binary search on (signature, word) pairs

    Date: 08/05/2013
*/
#include <iostream>
#include <string>

const unsigned NUM_CHAR = 256;

static void buildStat(std::string& str, int* m);
static bool compareStat(int* m1, int* m2);

bool isAnagram(std::string& str1, std::string& str2)
{
    int m1[NUM_CHAR] = {0};
    int m2[NUM_CHAR] = {0};

    buildStat(str1, m1);
    buildStat(str2, m2);

    return compareStat(m1, m2);
}

static void buildStat(std::string& str, int* m)
{
    unsigned i = 0;
    unsigned slot;

    while (str[i] != '\0') {
        slot = (unsigned)str[i];
        m[slot]++;
        i++;
    }
}

static bool compareStat(int* m1, int* m2)
{
    for (unsigned i = 0; i< NUM_CHAR; i++) {
        if (m1[i] != m2[i]) {
            return false;
        }
    }

    return true;
}

void TEST_isAnagram()
{
    std::string s1;
    std::string s2;

   
    std::cout << "\n*** TEST for isAnagram() ***\n"
              << "Two input strings: \n"
              << "String 1: ";

    while (std::cin>>s1) {
        std::cout << "String 2: ";
        std::cin>>s2;

        if (isAnagram(s1, s2)) {
            std::cout << s1 << " and " << s2 << " is anagram.\n";
        } else {
            std::cout << s1 << " and " << s2 << " is NOT anagram.\n";
        }
        
        std::cout << "\nTwo input strings: \n"
                  << "String 1: ";
    }
}
