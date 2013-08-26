/*
	find top-k min element in a endless stream: (Time complexity: nlog(k) )
	Algorithm:
		1. build a k-size maxheap	// Note: it's max heap for k-minimum elements
	Note:
		1. pay attention to the insert_node() in heap
		2. Time complexity of insert_node:  O(log n): n is the size of heap
*/
#include "heap.hpp"
#include "algo.hpp"
#include <iostream>

/* 
   arr: stream
   k: top K
 */
void min_k(int arr[], int n, int k)
{
	maxheap mh = maxheap(k);
	
	for(int i=0; i<n; i++) {
		mh.insert(arr[i]);
        mh.traverse();          // for debugging
	}
	
	mh.traverse();
}

void TEST_min_k()
{
	int arr[] = {11,4,8,2,16,9,10,8,14,3,7};
	int len = sizeof(arr)/sizeof(arr[0]);
    
    int K;
    std::cout << "\n*** TEST for min_K algorithm (top-K) ***\n"
              << "Enter K: ";
    std::cin >> K;

    printIntArray(arr, len);

	min_k(arr, len, K);
}
