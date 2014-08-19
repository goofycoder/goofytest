#include <iostream>
using namespace std;

void bit_swap_ints(int& x, int& y)
{
    x = x^y;
    y = x^y;    // y = x^y^y = x^(y^y) = x
    x = x^y;    // x = x^y^x = y
}

int main()
{
    int a = 3;
    int b = 7;

    bit_swap_ints(a,b);

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    return 0;
}
