/* Mystery code that works */
#include <iostream>

unsigned isqrt(unsigned num)
{
    unsigned res = 0;
    unsigned bit = 1L << 30;    // start with the highest bit set to 1

    // bit is divided by 4 till less than the num
    while (bit > num) {
        bit >>= 2;
    }

    while (bit != 0) {
        if (num >= res+bit) {
            num -= res+bit;
            res = (res >> 1) + bit;
        } else {
            res >>= 1;
        }

        bit >>= 2;
    }

    return res;
}

void TEST_isqrt()
{
    std::cout << "TEST int square root algorithm \n";

    unsigned num;
    std::cout << "Enter an unsigned int: \n";
    std::cin >> num;

    std::cout << "\nThe square root is: " << isqrt(num) << "\n";
}
