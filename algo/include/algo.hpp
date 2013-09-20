#ifndef ALGO_H
#define ALGO_H

#include <iostream>
#include <vector>
#include <string>

typedef int Item;

bool isPrime(const int &num);

// compute the sqrt of an integer
unsigned isqrt(unsigned num);   

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

// the sliding window max in the array
void slide_window_max(int A[], int n, int w, std::vector<int>& v);

// Rotate string at postion i
// "abcde" ==> "cdeab"
void rotateStr(std::string& str, const unsigned i);
void swapChar(char& a, char& b);
void reverseStr(std::string& str, int bgn, int end);

void strPermute(std::string str);
void strPermute_NoDup(std::string str);

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

// count how many bits need to swap from intA to intB
int bitSwap(int num_1, int num_2);
int countBitOne(int num);

// remove space in the string (in place)
void removeSpaceInStr_inPlace(char *str);

void intersectionOfSortedArray(std::vector<int> &v1,
                               std::vector<int> &v2,
                               std::vector<int> &res);

// number of unique paths from upper-left to bottom-right in the table
int unique_path(int** table, int width, int height);

/* ======================= Commonly Used APIs ========================== */
std::string intToStr(int val);          // Convert an integer value to string

int minOfThree(int a, int b, int c);    // minimum of three integer

void swapInt(int& a, int& b);           // swap two integers

void printIntArray(const int *arr, int len);    // print integer array

void printVector(const std::vector<int> &v);    // print vector

void print_2D_array(int** table, int width, int height);    // print 2D array

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

void TEST_find_loop();          // find loop in the list

void TEST_longestSubstr();      // longest non-repeatable-char substr

void TEST_rotateStr();          // rotate string: "abcde" ==> "cdeab"

void TEST_LongestCommonSeq();	// longest common sequence

void TEST_maxSum();             // test max sum in array 

void TEST_slide_window_max();   // test the sliding window max in an array

void TEST_reverseBit();         // reverse bit of an unsigned integer

// BST test APIs
void TEST_InsertNode();
void TEST_TreeTraverse();
void TEST_BinarySearch(); 
void TEST_TreeAPI();
void TEST_lca();
void TEST_prettyprintBST();
void TEST_BST_API();            // getParent(), getNumOfChild()
void TEST_BST_deleteNode();
void TEST_bst_mirror();         // test the mirror of BST

void TEST_min_k();              // top-k heap algorithm
        
void TEST_bitSwap();            // number of diff bits btwn 2 ints

void TEST_linked_list();        // test linked list APIs

void TEST_rectangle_overlap();  // test whether two rectangles overlap

void TEST_min_stack();          // test the stack that could return min value in the stack

void TEST_removeSpaceInStr();        

void TEST_intersectionOfSortedArray();

void TEST_unique_path();

void TEST_str_permute();

void TEST_split_list();         

void TEST_isqrt();         
#endif
