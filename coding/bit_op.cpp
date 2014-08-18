#include <iostream>
using namespace std;

#define BITS_IN_INT 32

bool isBitSet(unsigned int a, int pos)
{
    return a & (1<<pos);
}

/*
 * check whether a number is palindrome in binary presentation.
 */
bool is_binary_palindrome(unsigned int a)
{
    unsigned int left = 0;
    unsigned int right = BITS_IN_INT-1;

    while (left<right) {
        if (isBitSet(a, left)^isBitSet(a,right)) {
            return false;
        }
        
        left++;
        right--;
    }

    return true;
}

/* 
 * swap nibble (4-bit) in the byte
 */
unsigned char swap_nibble(unsigned char a)
{
    unsigned char out;

    out = ((a&0x0F)<<4) | ((a&0xF0)>>4);

    return out;
}

int main()
{
    unsigned char a = 0x52;

    unsigned char c = swap_nibble(a);

    cout << hex << (int)c << endl;

    // ===============================
    unsigned int d = 0xFF0210FF;
    
    if(is_binary_palindrome(d)) {
        cout << "d is palindrome in binary.\n";
    } else {
        cout << "d is not palindrome in binary.\n";
    }

    return 0;
}
