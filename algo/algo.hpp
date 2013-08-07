#ifndef ALGO_H
#define ALGO_H

bool isPrime(const int &num);

bool isPalindromeStr(const std::string& str);

bool isAnagram(std::string& str1, std::string& str2);
void buildStat(std::string& str, int* m);
bool compareStat(int* m1, int* m2);

/* Test APIs */
void TEST_isPrime();            // Prime number

void TEST_isPalindromeStr();    // Palindrome String

void TEST_isAnagram();          // Anagram

#endif
