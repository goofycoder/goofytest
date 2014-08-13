/*
 *  remove all the spaces in the string:
 *
 *   Example: "   abc de  fg  " ==> "abcdefg"
 *
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* removeSpace(char* str, int len)
{
    char* p=str;
    int i;

    for(i=0; i<len; i++) {
        if (str[i]!=' ') {
            *p = str[i];
            p++;
        }
    }

    *p = '\0';

    return str;
}

int main()
{
    /* Because removeSpace() would change the str,
     * thus string literal as below would not work 
     * since it is constant char string:
     *    char *str = "   abcd  de f  " 
     */
    char *str = strdup("   abc  de  f  ");

    str = removeSpace(str,strlen(str));
    printf("%s\n",str);

    free(str);

    return 0;
}
