/*
    Remove the duplicated char in a char string.

    Algorithm:
        1. iterate through the string and use char_map[256] to record the occurance of char
        2. Use a write_ptr (w_ptr) to track the position to write the new char
            if (new_char) write to *w_tpr; update char_map[str[i]]
            else just read the next char
 */

#include <iostream>
#include <string>

void str_remove_dup_char(char*& str, int len)
{
    const int NUM_CHAR=256;
    int char_map[NUM_CHAR] = {0};

    char *wptr = str;

    for(int i=0; i<len; i++) {
        if (char_map[str[i]] == 0) {
            char_map[str[i]] = 1;
            *wptr = str[i];
            wptr++;
        }     
    }

    *wptr = '\0';
}

void TEST_str_remove_dup_char()
{
    std::cout << "TEST: remove duplicate char in the string in place.\n";

    std::string str;
    std::cout << "Enter input string: ";
    std::cin >> str;

    int len = str.length();
    char *s = new char[len+1];

    for(int i=0; i<len; i++) {
        s[i] = str[i];
    }
 
    s[len] = '\0';

    str_remove_dup_char(s, len);

    std::cout << "Result string: " << s << "\n";

    free(s);
}
