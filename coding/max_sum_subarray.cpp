/*
 *  Max sum of the subarray:
 *
 *  Algorithm:
 *      use aux array to record the max_sum ending at each positon of array.
 *
 *      Input array:  a[];
 *
 *      if known aux[i];
 *          aux[i+1]  = aux[i]+a[i]     // if aux[i]>0
 *                  OR= a[i]            // else
 */
#include <iostream>
using namespace std;

int max_subarray(int a[], int len)
{
    int aux[len];
    aux[0] = a[0];
    int max_sum = a[0];

    for(int i=1; i<len; i++) {
        if(aux[i-1]>0) {
            aux[i] = aux[i-1]+a[i];
        } else {
            aux[i] = a[i];
        }

        if(aux[i]>max_sum) {
            max_sum = aux[i];
        }   
    }

    return max_sum;
}

int main()
{
    int a[] = {-2,9,-3,4,-1,2,1,-5,4};
    int len = sizeof(a)/sizeof(int);

    cout << "max subarray sum: " << max_subarray(a, len) << endl;

    return 0;
}
