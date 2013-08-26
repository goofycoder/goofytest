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

// Rejection sampling */
int rand10();       // made from rand7()
int rand7();        

// longest non-repeatable-char substr
int longestSubstr(const std::string& str);      

// longest common sequence between two strings
int lcs(const std::string& s1, const std::string& s2);
void printLCS(char** b, const std::string& s, int i, int j);

// Max sum in the array
int maxSum(const std::vector<int>& arr, const unsigned len);

// Rotate string at postion i
// "abcde" ==> "cdeab"
void rotateStr(std::string& str, const unsigned i);
void swapChar(char& a, char& b);
void reverseStr(std::string& str, int bgn, int end);

// Reverse Bits in the unsigned integer
// 8 (1010) ==> 5 (101)
void reverseBit(unsigned &input);
unsigned getNumOfBits(const unsigned input);
void swapBit(unsigned &input, unsigned left, unsigned right);

// Edit distance between two strings
// "hat" ==> "cap": distance 2
int editDistance(const std::string& s, const std::string& t);
int editDistanceInt(const char *s, int len_s, const char *t, int len_t);

// top-K, partial sort algorithm
// minimum k elements in the array
void min_k(int arr[], int len, int k);		// a[] is the stream, find minimum k elements in a[]
 

/* ======================= Commonly Used APIs ========================== */
std::string intToStr(int val);          // Convert an integer value to string

int minOfThree(int a, int b, int c);    // minimum of three integer

void swapInt(int& a, int& b);           // swap two integers

void printIntArray(const int *arr, int len);    // print integer array

/* ======================= Test APIs ========================== */
void TEST_isPrime();            // Prime number

void TEST_isPalindromeStr();    // Palindrome String
void TEST_isPalindromeNum();    // Palindrome Number

void TEST_isAnagram();          // Anagram

void TEST_editDistance();       // Edit distance of two strings

void TEST_fibo();               // Fibonacci number

void TEST_reservoir_sampling(); // Reservoir sampling

void TEST_rejection_sampling(); // Rejection sampling: rand7() ==> rand10()

void TEST_reverse_list();       // Reverse singly linked list

void TEST_longestSubstr();      // longest non-repeatable-char substr

void TEST_rotateStr();          // rotate string: "abcde" ==> "cdeab"

void TEST_LongestCommonSeq();	// longest common sequence

void TEST_maxSum();             // test max sum in array 

void TEST_reverseBit();         // reverse bit of an unsigned integer

// BST test APIs
void TEST_InsertNode();
void TEST_TreeTraverse();
void TEST_BinarySearch(); 
void TEST_TreeAPI();
void TEST_lca();
void TEST_prettyprintBST();

void TEST_min_k();

#endif
