#include <iostream>
#include <cmath>
#include "square.h"

int square(int num);

int main() {
    int num;

    std::cout << "Input: ";
    std::cin >> num;

    std::cout << "Square of " << num << " is: " << square(num) << std::endl;
    
    return 0;
}

int square(int num) {
    return pow(num,2);
}
