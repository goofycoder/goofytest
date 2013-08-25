#ifndef ALGO_H
#define ALGO_H

#include <iostream>
#include <vector>
#include <string>

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

// longest common sequence between two strings
int lcs(const std::string& s1, const std::string& s2);
void printLCS(char** b, const std::string& s, int i, int j);

// Max sum in the array
int maxSum(const std::vector<int>& arr, const unsigned len);

// Rotate string at postion i
void rotateStr(std::string& str, const unsigned i);
void swapChar(char& a, char& b);
void reverseStr(std::string& str, int bgn, int end);

// Reverse Bits in the unsigned integer
void reverseBit(unsigned &input);
unsigned getNumOfBits(const unsigned input);
void swapBit(unsigned &input, unsigned left, unsigned right);

/* Test APIs */
void TEST_isPrime();            // Prime number

void TEST_isPalindromeStr();    // Palindrome String
void TEST_isPalindromeNum();    // Palindrome Number

void TEST_isAnagram();          // Anagram

void TEST_fibo();               // Fibonacci number

void TEST_reservoir_sampling(); // Reservoir sampling

void TEST_reverse_list();       // Reverse singly linked list

void TEST_longestSubstr();      // longest non-repeatable-char substr

void TEST_LongestCommonSeq();	// longest common sequence

void TEST_maxSum();             // test max sum in array 

void TEST_reverseBit();         // reverse bit of an unsigned integer

// BST test APIs
void TEST_InsertNode();
void TEST_TreeTraverse();
void TEST_BinarySearch(); 
void TEST_TreeAPI();
void TEST_lca();

void TEST_rotateStr();

#endif
