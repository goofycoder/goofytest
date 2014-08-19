#include <iostream>
using namespace std;

int swap_even_odd(int d)
{
    return ((d&0xAAAAAAAA)>>1) | ((d&0x555555)<<1);
}

int main()
{
    int d = 0x99;

    int r = swap_even_odd(d);

    cout << hex << "0x" << r << endl;

    return 0;
}
