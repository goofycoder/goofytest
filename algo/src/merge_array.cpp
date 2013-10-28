/*
    Merge two sorted arrays into one. 

    A[] = {7};
    B[] = {2, 5, 8};
    ==> result:  A[] = {2, 5, 7, 8}

    Algorithm:
        Mergesort(). Pay attention to the case that orginal A[] is shorter than B[];
                     Need to copy the remaining B[] into A[].
 */
#include <iostream>
#include <cstring>       // memset()
#include <fstream>
#include <string>
#include <sstream>
#include "algo.hpp"

void merge_sorted_array(int* a, int len_a, int* b, int len_b)
{
    int i = len_a-1;
    int j = len_b-1;
    int p = len_a + len_b - 1;

    while(i>=0 && j>=0) {
        if (a[i] > b[j]) {
            a[p] = a[i];
            i--;
            p--;
        } else {
            a[p] = b[j];
            j--;
            p--;
        }
    }

    // Note: cases that B is longer than A, need to copy the remaining B[] to A[]
    while (j>=0) {
        a[p] = b[j]; 
        p--;
        j--;
    }
}

void TEST_merge_sorted_array()
{
    std::cout << "TEST merge two sorted arrays.\n";
    
    std::cout << "Enter file name that contains two arrays (hint: merge.txt):\n";
    std::string file;
    std::cin >> file;
    
    std::vector<int> v1;
    std::vector<int> v2;
    
    std::ifstream f_in(file);
    std::string str;
    std::string token;

    // read the first array (line 1)
    std::getline(f_in, str);
    std::stringstream iss(str);
    while (iss >> token) {
        v1.push_back(std::stoi(token));
    }

    // read second array (line 2)
    std::getline(f_in, str);
    std::stringstream iss_2(str);
    while (iss_2 >> token) {
        v2.push_back(std::stoi(token));
    }
   
    int len_1 = v1.size();
    int len_2 = v2.size();
    int len = len_1+len_2;  // enough space to hold both arrays
    
    int arr_1[len];
    int arr_2[len_2];
    std::memset(arr_1, 0, len);

    for(int i=0; i<len_1; i++) {
        arr_1[i] = v1[i];
    }

    for(int i=0; i<len_2; i++) {
        arr_2[i] = v2[i];
    }
    
    printIntArray(arr_1, len_1);
    printIntArray(arr_2, len_2);

    merge_sorted_array(arr_1, len_1, arr_2, len_2);

    std::cout << "Merged result: \n";
    printIntArray(arr_1, len);
}
