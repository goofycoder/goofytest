/*
    Search key on a rotated and sorted array.
    
    Example:
        int array[] = {7, 8, 9, 1, 2, 3, 4, 5, 6};
        search for key (9), output should be 2 (key_9's index).

    Recursion. (Pay close attention to the corner cases in line.)

    Could be extended to the binary search on the circular list.

    Date: 10/26/2013
 */
#include <iostream>
#include <vector>
#include "algo.hpp"

/* if key is found, pos (starting idx with 0) is the output */
void searchRotateArray(int* arr, int len, int key, int& pos)
{
    _searchRotateArray(arr, 0, len-1, key, pos);
}

/* if key is found, pos (starting idx with 0) is the output */
void _searchRotateArray(int* arr, int l, int r, int key, int& pos)
{
    if (l>r) 
        return;

    int m = l+(r-l)/2;

    if (arr[m] == key) {
        pos = m;
        return;
    }

    if (arr[m] < key) {
        if (arr[r] < key && arr[m] < arr[r]) { 
            // case: 7 8 9 2 3 4 5 6  (search 8)
            _searchRotateArray(arr, l, m-1, key, pos);
        } else {
            // case: 4 5 6 7 8 9 2 3 (search 8)
            _searchRotateArray(arr, m+1, r, key, pos);
        }
    }

    if (arr[m] > key) {
        if (arr[l] > key && arr[m] > arr[r]) {               
            // case: 4 5 6 7 8 9 2 3 (search 3)
            _searchRotateArray(arr, m+1, r, key, pos);
        } else {
            // case: 7 8 1 2 3 4 5 6 (search 1)
            _searchRotateArray(arr, l, m-1, key, pos);
        }
    }
}

void TEST_search_rotate_array()
{
    std::cout << "TEST search rotate array.\n";

    std::cout << "Enter the filename that contains input array (hint: rotate_array.txt): \n";
    std::string file;
    std::cin >> file;

    std::vector<int> v;
    readArrayFromFile(file, v);

    int len = v.size();
    int arr[len];

    for (int i=0; i<len; i++) {
        arr[i] = v[i];
    }

    printIntArray(arr, len);

    for (int i=0; i<12; i++) {
        int pos=-1;
        searchRotateArray(arr, len, i, pos);

        if (pos == -1) {
            std::cout << "Key ("<< i << ") is not found.\n";
        } else {
            std::cout << "Key ("<< i << ") is found at pos: " << pos << "\n";
        }
    }
}
