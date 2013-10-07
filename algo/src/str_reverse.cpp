#include <iostream>
#include <string>
#include <cstring>
#include "algo.hpp"

/* In place C-string reverse */
void str_reverse(char* str, int len)
{
    if (str==NULL) 
        return;

    int begin = 0;
    int end = len-1;

    while(begin<end) {
        swapChar(str[begin], str[end]);

        begin++;
        end--;
    }   
}

void TEST_str_reverse() 
{
    std::cout << "TEST c-string reverse.\n";
    
    std::cout << "Enter the string.\n";

    std::string str;
    std::cin >> str;

    char* cstr = new char[str.length()+1];
    std::strncpy(cstr, str.c_str(), str.length()+1);
    
    str_reverse(cstr, str.length());

    std::cout << "Reversed string: " << cstr << "\n";

    delete cstr;
}
