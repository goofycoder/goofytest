#ifndef ALGO_H
#define ALGO_H

#include <iostream>
#include <vector>
#include <string>

typedef int Item;


/************************************************
 ********* Commonly used APIs *******************
 ************************************************/
void readArrayFromFile(const std::string& filename, std::vector<int>& v);

std::string intToStr(int val);          // Convert an integer value to string

int minOfThree(int a, int b, int c);    // minimum of three integer

void swapInt(int& a, int& b);           // swap two integers
void swapChar(char& a, char& b);        // swap two chars

void printIntArray(const int *arr, int len);    // print integer array

void printVector(const std::vector<int> &v);    // print vector

void print_2D_array(int** table, int width, int height);    // print 2D array
/************************************************/


/************************************************
 ******** String-related algorithm **************
 ************************************************/
// palindrome string
bool isPalindromeStr(const std::string& str);

// longest palindrome substring in a string
std::string longestPalindrome(std::string& s);

bool isAnagram(std::string& str1, std::string& str2);

// longest non-repeatable-char substr
int longestSubstr(const std::string& str);      

// longest common sequence between two strings
int lcs(const std::string& s1, const std::string& s2);
void printLCS(char** b, const std::string& s, int i, int j);

// Rotate string at postion i
// Example: "abcde" ==> "cdeab"
void rotateStr(std::string& str, const unsigned i);

// string permutation
void strPermute(std::string str);
void strPermute_NoDup(std::string str);

// KMP algorithm: find string w in string s
int string_kmp(std::string s, std::string w);

/* In place C-string reverse */
void str_reverse(char* str, int len);

/* In-place reverse of a STL string */
void reverseStr(std::string& str, int bgn, int end);

// replace the space in a string with certain pattern
void replaceSpace(char *str, int len, 
                  char* pattern, int p_len, 
                  char*& new_str, int& new_len);

// Edit distance between two strings
// "hat" ==> "cap": distance 2
int editDistance(const std::string& s, const std::string& t);
int editDistanceInt(const char *s, int len_s, const char *t, int len_t);

// remove space in the string (in place)
void removeSpaceInStr_inPlace(char *str);

// regular expression strings match
bool regex_match(const char *s, const char *p);

// longest substring without dup character
std::string longest_substr_no_dup(std::string s,
                                  int& max_left, 
                                  int& max_right);

// the minimum substring (window) in string S 
// that contains all chars in string T
bool min_cover_window(std::string& s, std::string& t,
                      int& w_left, int& w_right);
/************************************************/


/************************************************
 ******** Number-related algorithm **************
 ************************************************/
bool isPrime(const int &num);

// Greatest Common Divider
int gcd(int a, int b);
int gcd_e(int a, int b);    // Euclid's algorithm

bool isPalindromeNum(int x);

// Fibonacci number
int fibo(const int&n);      // recursive version
int fibo_nr(const int&n);   // non-recursive version

// compute the sqrt of an integer
unsigned isqrt(unsigned num);   

/* reservior sampling */
void reservior_sample(const Item* stream, const unsigned& stream_len,
                      Item* samples, unsigned sample_size);
void display_samples(const Item* samples, unsigned sample_size);
Item* stream_source(const int &stream_len);
void display_samples(const Item* samples, unsigned sample_size);

// Rejection sampling */
int rand10();       // made from rand7()
int rand7();        

/* Ugly numbers are numbers whose only prime factors are 2, 3 or 5. 
   Get the n-th ugly number. */
unsigned ugly_number(unsigned n);       

void divide_and_mod(int a, int b,
                    int& q,     // output: quotient 
                    int& r);    // output: remainder

/* Given the target 'sum', print all the combinations from input array
 *  that sums up to 'sum'.
 */
void sum_subset(int sum, int* input, int len);

/************************************************/


/************************************************
 ********* Array/stream related algorithm *******
 ************************************************/
// top-K, partial sort algorithm
// minimum k elements in the array
// arr[] is the stream, find minimum k elements in arr[]
void min_k(int arr[], int len, int k);		

// Max sum in the array
int maxSum(const std::vector<int>& arr, const unsigned len);

// the sliding window max in the array
void slide_window_max(int A[], int n, int w, std::vector<int>& v);

// intersection of two sorted arrays
void intersectionOfSortedArray(std::vector<int> &v1,
                               std::vector<int> &v2,
                               std::vector<int> &res);

// number of unique paths from upper-left to bottom-right in the table
int unique_path(int** table, int width, int height);

// print all combination of balanced parenthesis
void printParenthesis(int n);

// displays the first no-dup char in char stream
void stream_no_dup_char(std::string str);
/************************************************/


/************************************************
 ********* Bit operation algorithm **************
 ************************************************/
// Reverse Bits in the unsigned integer
// Example: 8 (1010) ==> 5 (101)
void reverseBit(unsigned &input);
unsigned getNumOfBits(const unsigned input);
void swapBit(unsigned &input, unsigned left, unsigned right);

// count how many bits need to swap from intA to intB
int bitSwap(int num_1, int num_2);

int countBitOne(int num);

bool powerOfTwo(int n);

bool opposite_sign(int x, int y);
/************************************************/

/************************************************
 ********* Unit Test APIS ***********************
 ************************************************/
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

void TEST_str_replace_space();  // replace space in a string with certain pattern

void TEST_string_kmp();         // KMP string search algorithm

void TEST_str_reverse();        // reverse the c-string

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
void TEST_convertToDoublyList();    // convert BST to circular doubly-linked list

void TEST_min_k();              // top-k heap algorithm
        
void TEST_bit_op();             // test the basic bit operations
void TEST_bitSwap();            // number of diff bits btwn 2 ints

void TEST_linked_list();        // test linked list APIs

void TEST_rectangle_overlap();  // test whether two rectangles overlap

void TEST_min_stack();          // test the stack that could return min value in the stack

void TEST_removeSpaceInStr();        

void TEST_intersectionOfSortedArray();

void TEST_unique_path();

void TEST_str_permute();

void TEST_split_list();         

void TEST_isqrt();              // integer square root      

void TEST_gcd();                // greatest common divider  

void TEST_ugly_number();        // compute the n_th ugly number         

void TEST_longestPalindrome();  // longest palindrome substring in a string

void TEST_regex();              // regular expression match

void TEST_circular_sorted_list();

void TEST_longest_substr_no_dup();

void TEST_min_cover_window();

void TEST_print_parenthesis();

void TEST_divide_and_mod();

void TEST_stream_no_dup_char();

void TEST_sum_subset();
#endif  // ALGO_H
