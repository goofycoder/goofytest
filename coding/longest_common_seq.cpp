/*
 *  Calculate the length of longest common sequence in two strings
 */
#include <iostream>
#include <cstring>
using namespace std;

int lcs(char* A, int m, char* B, int n)
{
    if (m==0 || n==0) return 0;

    if (A[m-1]==B[n-1]) {
        return lcs(A, m-1, B, n-1)+1; 
    }

    return max(lcs(A, m-1, B, n), lcs(A, m, B, n-1));
}

int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    
    cout << "Length of longest common seqence: " 
         << lcs(X, strlen(X), Y, strlen(Y)) << endl;

    return 0;
}
