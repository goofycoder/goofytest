/*  find all the prime numbers that <= N
 *
 *  Sieve:
 *      bool isPrime[0...N] = {true};
 *
 *      isPrime[0]=false;
 *      isPrime[0]=false;
 *
 *      from 2 to sqrt(N):
 *          if (isPrime[i]==true)
 *              mark all isPrime[p*i] (p starts from 2) as false
 */
#include <iostream>
#include <cmath>
using namespace std;

void prime(int n) 
{
    if (n<0) 
        return;    
    
    int i;

    bool isPrime[n+1];
    for(i=0; i<n+1; i++) {
        isPrime[i]=true;
    }

    isPrime[0] = false;
    isPrime[1] = false;

    i=2;

    while(i<=sqrt(n)) {
        if (isPrime[i] == true) {
            int p = 2*i;

            while(p<=n) {
                isPrime[p]=false;
                p+=i;
            }
        }
        
        i++;
    }

    for(int j=0; j<=n; j++) {
        if (isPrime[j]==true) {
            cout << j << " ";
        }
    }

    cout << endl;
}

int main()
{
    int n = 100;

    prime(n);

    return 0;
}
