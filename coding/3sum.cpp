/*
 *  Given an array, a[] = {-1, 0, 1, 2, -1, -4},
 *
 *      find three elements in the array with the sum to a specific value
 *
 *  Algorithm:
 *      - sort the array in ascending order
 *      - use 3 pointers
 *          ptr1: start from the a[0] to a[len-3]
 *          ptr2: start from ptr1+1, move forward till meet ptr3
 *          ptr3: start from a[len-1], move backwards till meet ptr2
 *          
 *          for each ptr1 location:
 *              check wether *ptr2 + *ptr3 could be sum-*ptr1
 *
 */
#include <iostream>
#include <algorithm>
using namespace std;

void three_sum(int* a, int len, int sum)
{
    // sort the array in the ascending order
    sort(a, a+len);

    int *p1;
    int *p2;
    int *p3;
    int part_sum;

    // loop for p1
    for(int i=0; i<len-2; i++) {
        p1 = &a[i];
        p2 = p1+1;              // Note: p2=p1++; is error because it changes both p2 and p1 
        p3 = &a[len-1];
        part_sum = sum-*p1;
        
        while(p2<p3) {
            if (*p2+*p3==part_sum) {
                cout << *p1 << " " << *p2 << " " << *p3 << endl; 
            }

            p2++;
            p3--;
        }
    }
}

int main()
{
    int a[] = {-1, 0, 1, 2, -1, -4};
    int len = sizeof(a)/sizeof(int);
    int sum = 0;

    cout << "Input array: ";
    for(int i=0; i<len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "The sum: " << sum << endl;

    cout << "Output: \n";
    three_sum(a, len, sum);

    return 0;
}
