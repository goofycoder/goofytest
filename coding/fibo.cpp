/* fibonacci number */
#include <iostream>
using namespace std;

int fibo(int n)
{
    if (n<0) return -1;

    if (n==0 || n==1) return n;

    return fibo(n-1)+fibo(n-2);
}

int main()
{
    int N = 20;

    for(int i=0; i<N; i++) {
        cout << fibo(i) << " ";
    }
    cout << endl;

    return 0;
}
