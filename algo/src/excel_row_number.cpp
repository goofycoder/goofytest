#include <iostream>
#include <string>

const int ALPHA_NUM = 26;

std::string int_to_excel_row(int n)
{
    std::string str(1, 'a' + n%ALPHA_NUM);  // initialized to the last char

    n = n/ALPHA_NUM;
    while (n != 0) {
        str = (char)('a' + (n-1)%ALPHA_NUM) + str;     // append ahead of existing string
        n = (n-1)/ALPHA_NUM;
    }
    
    return str;
}

void TEST_int_to_excel_row()
{
    std::cout << "TEST convert integer to excel row number.\n";

    std::cout << "Enter an integer: ";
    int num;
    std::cin >> num;

    std::cout << "Result: " << int_to_excel_row(num) << "\n";
}
