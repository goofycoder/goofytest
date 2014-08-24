/*
 *  maintain the top-k (largest K) elements in the stream
 * 
 *  Algorithm:
 *      use min-heap for the top-k  (counter-intuitive!!!)
 *  
 */
#include <iostream>
#include <vector>
using namespace std;

class minheap {
public:
    void buildheap(int a[], int len);

    void traverse() const;

    void insert(int d);

private:
    void min_heapify(int idx);

    vector<int> v;

    int capacity;
};

void minheap::buildheap(int a[], int len)
{
    int i;

    capacity = len;

    for(i=0; i<len; i++) {
        v.push_back(a[i]);
    }

    for(i=len/2; i>=0; i--) {
        min_heapify(i);
    }
}

void minheap::min_heapify(int idx)
{
    int left = 2*idx+1;
    int right = 2*idx+2;

    int smallest;

    if(left<v.size() && v[left]<v[idx])
        smallest = left;
    else
        smallest = idx;

    if(right<v.size() && v[right]<v[smallest])
        smallest = right;

    if(idx!=smallest) {
        swap(v[idx], v[smallest]);

        min_heapify(smallest);
    }
}

void minheap::traverse() const
{
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void minheap::insert(int d)
{   
    if(capacity == v.size()) {
        if (d>v[0]) {
            v[0]=d;
        } else {
            return;
        }
    } else {
        v.push_back(d);
    }

    min_heapify(0);
}

int main()
{
    int K = 3;
    int a[] = {4,1,3};

    minheap minhp;
    minhp.buildheap(a,K);

    int in[] = {2,16,9,10,14,8,7};
    int len = sizeof(in)/sizeof(in[0]);

    for(int i=0; i<len; i++) {
        minhp.insert(in[i]);
    }

    minhp.traverse();
}
