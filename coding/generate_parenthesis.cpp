/*
 *  generate all legal parenthesis
 *        
 *  Algorithm:
 *      - use three additional argument
 *          * pos:  the position in the result char array
 *          * open: the number of open parenthesis
 *          * close: the number of close parenthesis
 */
#include <iostream>
#include <string>
using namespace std;

static char s[100];

void _parenthesis(int pos, int n, int open, int close);

void gen_parenthesis(int n)
{
    _parenthesis(0,n,0,0);
}

void _parenthesis(int pos, int n, int open, int close)
{
    if(close==n) {
        cout << s << endl;
        return;
    }

    if (open>close) {
        s[pos]=')';

        _parenthesis(pos+1, n, open, close+1);
    } 

    if (open<n) {
        s[pos]='(';

        _parenthesis(pos+1, n, open+1, close);
    }
}

int main()
{
    int n = 3;

    gen_parenthesis(n);

    return 0;
}
