#include <iostream>
#include <climits>

using namespace std;

int (*fp)(int a, int b);

int foo(int a, int b) 
{
    return (a+b);       
}

int main()
{
    cout << INT_MAX << endl;
    cout << INT_MIN << endl;

    //======== pointers ================
    int *p = NULL;
    int **pp = &p;

    if (pp==NULL) {
        cout << "pp is NULL\n";
    } else {
        cout << "pp is not NULL\n";
    }

    if (*pp == NULL) {
        cout << "*pp is NULL\n";
    } else {
        cout << "*pp is not NULL\n";
    }

    //======== function pointers ========
    fp = &foo;          // OK
    //*fp = foo;        // error!

    int a=3;
    int b=4;
    int sum;

    sum = (*fp)(a,b);

    cout << "sum: " << sum << endl;

    return 0;
}
