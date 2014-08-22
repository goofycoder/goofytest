#include <iostream>
#include <set>
using namespace std;

void rm_dup_array(int a[], int len, int*& b, int& new_len)
{
    set<int> s;
    new_len = 0;
    int i;

    for(i=0; i<len; i++) {
        s.insert(a[i]);
    }

    auto it = s.begin();

    while(it!=s.end()) {
        new_len++;
        it++;
    }

    b = new int[new_len];

    it = s.begin();
    i=0;
    
    for(;it!=s.end(); it++) {
        b[i] = *it;
        i++;
    }
}

int main()
{
    int a[] = {2,7,2,5,1,5};
    int len = sizeof(a)/sizeof(a[0]);
    int *b = NULL;
    int new_len = 0;

    rm_dup_array(a,len, b, new_len);

    for(int i=0; i<new_len; i++) {
        cout << b[i] << " ";
    }

    cout << endl;

    delete[] b;
}
