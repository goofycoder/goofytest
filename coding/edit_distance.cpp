/*
 *  edit distance of two strings
 *  
 *  Algorithm:
 *      - recursive:
 */
#include <iostream>
#include <cstring>
using namespace std;

int edit_distance(char a[], int len_a, char b[], int len_b)
{
    if (len_a==0) 
        return len_b;

    if (len_b==0)
        return len_a;

    int dist;
    if (a[len_a-1]==b[len_b-1])
        dist = 0;
    else 
        dist = 1;

    int d1, d2, d3;

    d1 = edit_distance(a,len_a-1, b, len_b)+1;
    d2 = edit_distance(a,len_a, b, len_b-1)+1;
    d3 = edit_distance(a, len_a-1, b, len_b-1) + dist;

    return min(d1, min(d2,d3));
}

int main()
{
    char a[] = "bcd";
    char b[] = "acef";

    cout << "Edit distance is: " 
         << edit_distance(a, strlen(a), b, strlen(b)) << endl;

    return 0;
}
