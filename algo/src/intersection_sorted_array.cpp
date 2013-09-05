/*
    Find the intersection of two sorted arrays.
    Example:
        A = {1,2,4};
        B = {2,4,5,7};

        Result: {2,4};
    
    Algorithm:
        * Use two index, both starts at zero. 
        * Compare the two first elements of A and B. 
            - If A[0] > B[0], increase index of B by one. 
            - If B[0] > A[0], increase index of A by one. 
            - If A[0] = B[0], add it to the result array(vector) and increment index of A and B by one. 
        * Termination conditation
            - Once either index reaches the end of A or B, we find all the intersections of A and B.

    Time complexity: 
        O(m+n):  m and n are the length of two arrays, respectively.
 */

#include "algo.hpp"
#include <vector>
#include <iostream>

void intersectionOfSortedArray(std::vector<int> &v1,
                               std::vector<int> &v2,
                               std::vector<int> &res) 
{
    int m = v1.size();
    int n = v2.size();
    int i = 0, j = 0;

    while (i < m && j < n) {
        if (v1[i] > v2[j]) {
            j++;
        } else if (v1[i] < v2[j]) {
            i++;
        } else {
            res.push_back(v1[i]);
            i++;
            j++;
        }
    }
}

void TEST_intersectionOfSortedArray()
{
    std::vector<int> v;

    int arr_1[] = {1,2,4};
    int len_1 = sizeof(arr_1)/sizeof(arr_1[0]);
    std::vector<int> v1(arr_1, arr_1+len_1);    // convert array to vector
    
    int arr_2[] = {2,4};
    int len_2 = sizeof(arr_2)/sizeof(arr_2[0]);
    std::vector<int> v2(arr_2, arr_2+len_2);

    std::cout << "The intersection of two arrays is: \n";
    intersectionOfSortedArray(v1, v2, v);

    printVector(v);
}
