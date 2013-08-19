#ifndef ALGO_H
#define ALGO_H

typedef int Item;

bool isPrime(const int &num);

bool isPalindromeStr(const std::string& str);
bool isPalindromeNum(int x);

bool isAnagram(std::string& str1, std::string& str2);
void buildStat(std::string& str, int* m);
bool compareStat(int* m1, int* m2);

int fibo(const int&n);
int fibo_nr(const int&n);

/* reservior sampling */
void reservior_sample(const Item* stream, const unsigned& stream_len,
                      Item* samples, unsigned sample_size);
void display_samples(const Item* samples, unsigned sample_size);
Item* stream_source(const int &stream_len);
void display_samples(const Item* samples, unsigned sample_size);

// longest non-repeatable-char substr
int longestSubstr(const std::string& str);      

/* Test APIs */
void TEST_isPrime();            // Prime number

void TEST_isPalindromeStr();    // Palindrome String
void TEST_isPalindromeNum();    // Palindrome Number

void TEST_isAnagram();          // Anagram

void TEST_fibo();               // Fibonacci number

void TEST_reservoir_sampling(); // Reservoir sampling

void TEST_reverse_list();       // Reverse singly linked list

void TEST_longestSubstr();      // longest non-repeatable-char substr

// BST test APIs
void TEST_InsertNode();
void TEST_TreeTraverse();
void TEST_BinarySearch(); 
void TEST_TreeAPI();

#endif
