#include <iostream>
#include <cstring>
using namespace std;

int atoi(const char* s)
{
    int r=0;
    unsigned int i;

    for(i=0; i<strlen(s); i++) {
        r = r*10 + (s[i]-'0');
    }

    return r;
}

int main()
{
    char s[] = "237";

    cout << "result: " << atoi(s) << endl;
}
