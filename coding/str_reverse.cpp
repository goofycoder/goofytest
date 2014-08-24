#include <iostream>
#include <cstring>
using namespace std;

void swap(char& a, char& b);

void str_reverse(char *s, int len)
{
    int i=0;
    int j=len-1;

    while(i<j) {
        swap(s[i], s[j]);
        i++;
        j--;
    }
}

// in-place swap
void swap(char& a, char& b)
{
    a = a^b;
    b = a^b;
    a = a^b;
}

int main()
{   
    char s[] = "hello";

    str_reverse(s, strlen(s));

    cout << s << endl;
}
