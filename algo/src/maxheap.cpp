#include <iostream>
#include <vector>
#include "heap.hpp"
#include "algo.hpp"

/* Heap: stored in vector
 *   left child:  i*2+1;
 *   right child: i*2+2;
 */
void maxheap::insert(int d)
{
	if (size==maxsize) {
		if(d<v[0])
			v[0]=d;
		else 		
			return;
	}
	else {
		v.push_back(d);
		size++;
	}

	max_heapify();
}

int maxheap::deleteMax()
{
	int ret = v[0];
	v.erase(v.begin());
	max_heapify();
	return ret;
}

void maxheap::buildMaxHeap(int* a, int len)
{
	for (int i=0; i<len; i++) {
		v.push_back(a[i]);
	}

	for (int i=len/2; i>=0; i--) {
		do_max_heapify(i);
	}
}

/* Max_heapify:
 *      - start from the half-size node
 *      - check the heap property on each node and its children
 *      - iterate all the way back to the root node
 */
void maxheap::max_heapify()
{
    // need to start from the half way and back to top
    for (int i=size/2; i>=0; i--) {
    	do_max_heapify(i);
    }
}

void maxheap::do_max_heapify(int i) 
{
	int l = leftChild(i);
	int r = rightChild(i);

    /* compare the value of current node with 
     * its left child and right child, adjust
     * the order if it does not satisfy the heap property
     */
	int largest;
	if (l<=size && v[l]> v[i]) {
		largest = l;
	} else {
        largest = i;
    }
	
	if (r<=size && v[r]>v[largest]) {
		largest = r;
	}
	
	if (largest != i) {
		swapInt(v[i], v[largest]);
		do_max_heapify(largest);
	}
}

void maxheap::traverse() const
{
	for (int i=0; i<size; i++) {
        std::cout << v[i] << " ";
	}
	std::cout << "\n";
}
