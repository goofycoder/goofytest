/*
 *  Find the missing number in an array [1...N].
 *  The array has N-1 numbers, missing one in between.
 *
 *  Algorithm:
 *      Naive: just sum up the number in the array
 *             and compare to the sum from 1 to N, 
 *             the diff is the missing number.
 *          Problem: the sum could overflow if it's a stream
 *
 *      Good:
 *          XOR every number in array --> xor_1
 *          XOR every number from 1 to N --> xor_2
 *
 *          xor_1 ^ xor_2 is the missing number
 *
 */
#include <iostream>
using namespace std;

int findMissingNum(int a[], int len, int N)
{
    int expected = 0;
    int actual = 0;
    int i;

    for(i=1; i<=N; i++) {
        expected ^= i;
    }

    for(i=0; i<len; i++) {
        actual^=a[i];
    }

    return (expected^actual);
}

int main()
{
    int a[] = {1, 3, 2, 4, 7, 6};
    int len = sizeof(a)/sizeof(a[0]);
    int N = 7;

    cout << "missing: " << findMissingNum(a, len, N) << endl;

    return 0;
}
