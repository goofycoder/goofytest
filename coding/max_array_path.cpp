/*
 *
 * Given two sorted arrays such the arrays may have some common elements. 
 * Find the sum of the maximum sum path to reach from beginning of any array to end of any of the two arrays. 
 * We can switch from one array to another array only at common elements.
 *
 * Expected time complexity is O(m+n) where m is the number of elements in ar1[] and n is the number of elements in ar2[].
 *
 * Examples:
 *
 * Input:  ar1[] = {2, 3, 7, 10, 12}, ar2[] = {1, 5, 7, 8}
 * Output: 35
 * 35 is sum of 1 + 5 + 7 + 10 + 12.
 * 
 * We start from first element of arr2 which is 1, then we
 * move to 5, then 7.  From 7, we switch to ar1 (7 is common)
 * and traverse 10 and 12.
 *
 * Input:  ar1[] = {10, 12}, ar2 = {5, 7, 9}
 * Output: 22
 * 22 is sum of 10 and 12.
 * Since there is no common element, we need to take all 
 * elements from the array with more sum.
 *
 * Input:  ar1[] = {2, 3, 7, 10, 12, 15, 30, 34}
 *         ar2[] = {1, 5, 7, 8, 10, 15, 16, 19}
 *         Output: 122
 *         122 is sum of 1, 5, 7, 8, 10, 12, 15, 30, 34
 */
#include <iostream>
using namespace std;

int max_sum_path(int a[], int m,
                  int b[], int n) 
{
    int i=0;
    int j=0;
    int res = 0;
    int sum_a = 0;
    int sum_b = 0;

    while(i<m && j<n) {
        if(a[i]<b[j]) {
            sum_a += a[i++];
        } 

        if(a[i]>b[j]) {
            sum_b += b[j++];
        }

        if(a[i]==b[j]) {
            sum_a += a[i++];
            sum_b += b[j++];

            res+=max(sum_a, sum_b);

            sum_a = 0;
            sum_b = 0;
        }
    }

    if (i<m) {
        while(i<m) {
            sum_a+=a[i++];
        }
    }

    if (j<n) {
        while(j<n) {
            sum_b+=b[j++];
        }
    }

    res+=max(sum_a, sum_b);

    return res;
}

int main()
{
    int arr_1[] = {2, 3, 7, 10, 12};
    int arr_2[] = {1, 5, 7, 8};
    
    //int arr_1[]  = {2, 3, 7, 10, 12, 15, 30, 34};
    //int arr_2[] =  {1, 5, 7, 8, 10, 15, 16, 19};

    //int arr_1[] = {10, 12};
    //int arr_2[] = {5, 7, 9};

    int len_1 = sizeof(arr_1)/sizeof(int);
    int len_2 = sizeof(arr_2)/sizeof(int);

    int sum;
    
    sum = max_sum_path(arr_1, len_1, arr_2, len_2);

    cout << "Max sum: " << sum << endl;

    return 0;
}
