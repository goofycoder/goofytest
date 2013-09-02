/* 
    Remove the space in the string
    
    Idea:
        1. have read-ptr and write-ptr to traverse the string
        2. if (read-ptr is not space) write to the write-ptr
        3. update the null terminator of the string

    Note:
        May not be straightforward to directly manipulate the c++ string class
            Ex:  string str = "abc de";
                 str[3] = '\0';
                 cout << str;       // not "ab"!!
 */

#include <iostream>
#include <string>
#include <cstring>  // strlen()
#include <cctype>   // isspace()

void removeSpaceInStr_inPlace(char* str)
{
    char *rptr = str;
    char *wptr = rptr;

    while (*rptr!='\0') {
        if (!isspace(*rptr)) {
            *wptr = *rptr;
            wptr++;
        }
        
        rptr++;
    }

    *wptr = '\0';
}

void TEST_removeSpaceInStr() 
{
    std::cout << "\n*** TEST for space removal in string ***\n";

    //std::string str;
#if 0   // why this is not working?
    std::cout << "Enter input string:";
    std::getline(std::cin, str);
#endif 

    char str[] = " abc  de fg     ";

    std::cout << "String before space removal: " 
              << str << "; len: " << strlen(str) << "\n";

    removeSpaceInStr_inPlace(str);

    std::cout << "\nstring after space removal: \n" 
              << str << "; len: " << strlen(str) << "\n";
}
