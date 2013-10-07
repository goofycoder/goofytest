#include "algo.hpp"

void rotateStr(std::string& str, const unsigned i) 
{
    if (i==0) 
        return;

    unsigned len = str.length();

    reverseStr(str, 0, i-1);
    reverseStr(str, i, len-1);

    reverseStr(str, 0, len-1);
}

void reverseStr(std::string& str, int bgn, int end)
{
    while (bgn<end) {
        swapChar(str[bgn], str[end]);
        bgn++;
        end--;
    }
}

void TEST_rotateStr()
{
    std::string str;
    
    std::cout << "\n *** TEST for String rotation***\n"
              << "Enter a string: ";
    std::cin>>str;

    unsigned pos;
    std::cout << "Enter the postion in the string to rotate: ";
    std::cin>>pos;



    std::cout << "String before rotation: " << str << "\n";
    rotateStr(str, pos); 
    std::cout << "String after rotation: " << str << "\n";
}
