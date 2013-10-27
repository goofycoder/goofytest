/*
    Find all pairs of integers that sum to the given value (sum)
    
    Algorithm:
        1. sort the array in ascending order
        2. two pointers to the array, beginning and the tail entry
        3. move these pointers as the comparison goes

    Note:
        This algorithm handles the duplicate numbers in the array

    Date: 10/27/2013
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>      // qsort()
#include "algo.hpp"

// needed by qsort() for sorting the array in the acending order 
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void find_pair_to_sum(int* arr, int len, int sum)
{
    // sort the array in ascending order
    qsort(arr, len, sizeof(int), compare);

    int p = 0;
    int q = len-1;

    while (p<q) {
        if (arr[p] + arr[q] == sum) {
            std::cout << "(" << arr[p] << "," << arr[q] << ")\n";
            p++;
            q--;
        } else {
            if (arr[p] + arr[q] > sum) {
                q--;
            } else {  // arr[p] + arr[q] < sum;
                p++;
            }
        }
    }
}

void TEST_find_pair_to_sum()
{
    std::cout << "TEST: find all pairs of integers that sums to specified value.\n";

    std::cout << "Enter the filename that contains the input array (hint: pair_sum.txt): ";
    std::string file;
    std::cin >> file;

    std::cout << "Enter the target sum: ";
    int sum;
    std::cin >> sum;

    std::vector<int> v;    
    readArrayFromFile(file, v);
 
    // sort the vector
    //std::sort(v.begin(), v.end());

    printVector(v);
   
    int len = v.size();
    int arr[len];
    for(int i=0; i<v.size(); i++) {
        arr[i] = v[i];
    }

    find_pair_to_sum(arr, len, sum);
}
