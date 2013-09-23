/*
   Replace the space in a string with certain pattern

    Algorithm:
        1. count the spaces in the string
        2. compute the length of new string (after replacing space with new pattern)
        3. From the end of new string, fill the new string
 */
#include <iostream>
#include <cstring>

static int countSpace(char *str, int len);

void replaceSpace(char *str, int len, char* pattern, int p_len, char*& new_str, int& new_len)
{
    // find pattern's occurance
    int ctr = countSpace(str, len);
    std::cout << ctr << "\n";

    new_len = len + ctr*(p_len-1);
    new_str = new char(new_len+1);
    new_str[new_len] = '\0';
    int j = new_len-1;

    for (int i=len-1; i>=0; i--) {
        if (str[i]==' ') {
            for(int k=0; k<p_len; k++) {
                new_str[j-p_len+k+1] = pattern[k];
            }

            j-=p_len;
        } else {
            new_str[j]=str[i];
            j--;
        }
    }
}

static int countSpace(char *str, int len)
{
    int ctr = 0;    

    for(int i=0; i<len; i++) {
        if (str[i] == ' ') 
            ctr++;
    }

    return ctr;
}

void TEST_str_replace_space()
{
    std::cout << "TEST string replacing space with %20\n";
    
    char str[] = " abc de  f";
    int len = sizeof(str)/sizeof(char)-1;

    char pattern[] = "%20";
    int p_len = std::strlen(pattern);

    char* result = NULL;
    int new_len=0;

    replaceSpace(str, len, pattern, p_len, result, new_len);
    std::cout << result << "\n";
}
