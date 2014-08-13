/*
 * Count the number of words in the string
 *
 *   " abc  de hello   " ==> 3
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int count(char* s, int len)
{
    int i;
    int ctr=0;
    bool inWord = false;

    for(i=0; i<len; i++) {
        if(isalpha(s[i]) && inWord==false) {
            inWord = true;
            ctr++;
        }

        if(!isalpha(s[i]) && inWord==true) {
            inWord = false;
        }    
    }

    return ctr;
}

int main() 
{
    char *s = "   abc  de fg  h  ";

    printf("%d\n", count(s, strlen(s)));

    return 0;
}
