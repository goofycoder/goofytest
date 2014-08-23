/*
 *  Find the key in the rotated sorted array
 *
 *  http://leetcode.com/2010/04/searching-element-in-rotated-array.html
 *  
 *  Algorithm:
 *      
 *      set L to be 0
 *      set R to be len-1
 *
 *      M = L+R/2
 *
 *      if(a[L]<=a[M])   // left part is sorted
 *          if key is in range [L,M], update R to M-1
 *          if key is not in this range, update R to M+1
 *      else    // right half is sorted
 *          if key is in range [M, R], update L to M+1
 *          else, update R to M-1
 */ 
#include <iostream>
using namespace std;

int search_rotated_array(int a[], int len, int key)
{
    int L = 0;
    int R = len-1;
    int M;

    while(L<=R) {
        M = (L+R)/2;

        if (a[M]==key) {
            return M;
        }

        if (a[L] <= a[M]) {
            if (a[L]<=key && key <= a[M]) {
                R = M-1;
            } else {
                L = M+1;
            }
        } else {
            if (a[M]<key && key <= a[R]) {
                L = M+1;
            } else {
                R = M-1;
            }
        }
    }

    return -1;
}

int main()
{
    int a[] = {8, 10, 12, 14, 15, 5,7};
    //int a[] = {1,2,3,4,5};
    int len = sizeof(a)/sizeof(a[0]);
    int key = 12;

    cout << "Find key " << key << " at " << search_rotated_array(a, len, key) << endl;

    return 0;
}
