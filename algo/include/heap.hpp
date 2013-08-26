#include <vector>

class maxheap
{	
public:
	maxheap(int* a, int len) { buildMaxHeap(a,len); }
	maxheap(int maxsz) {	maxsize=maxsz; size=0; }
	~maxheap() { }
	void insert(int d);
	void traverse() const;
	int deleteMax();
private:
	std::vector<int> v;
	int maxsize;		// max heapsize
	int size;			// current heapsize
	int leftChild(int i)  { return i*2+1; } // left child: i*2+1
	int rightChild(int i) { return i*2+2; } // right child: i*2+2
	void buildMaxHeap(int* a, int len);
	void do_max_heapify(int i);
	void max_heapify();
};
