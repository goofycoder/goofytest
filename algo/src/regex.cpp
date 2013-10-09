/*  
    Regular expression match

    Algorithm:
        Recursion!
        Step 1:
            If the next character of p is NOT ‘*’:
                - it must match the current character of s. 
                - continue pattern matching with the next character of both s and p.
            If the next character of p is ‘*’: 
                - Do a brute force exhaustive matching of 0, 1, or more repeats of current character of p.
                - until we could not match any more characters.
        Step 2:
 */

#include <iostream>
#include <string>

bool regex_match(const char *s, const char *p)
{
    if (*p=='\0')
        return *s=='\0';

    if (*(p+1)!='*') {     
        // next char is not '*', need to be exact match
        if  ( (*p==*s) || (*p=='.' && *s!='\0') ) { 
            return regex_match(s+1, p+1);
        } else {
            return false;
        }
    } else {
        // next char is '*'. match till '*' cannot match any more
        while ( (*p==*s) || (*p=='.' && *s!='\0') ) {
            if (regex_match(s, p+2)) 
                return true;
            s++;
        }

        return regex_match(s, p+2);
    }
}

void TEST_regex()
{
    std::cout << "TEST regular expression matching.\n";

    std::cout << "Enter two strings to match.\n";

    std::string a, b;
    std::cout << "Enter standard string A (does not have '*' or '.'): ";
    std::cin >> a;
    
    std::cout << "Enter regex string B (have '*' or '.'): ";
    std::cin >> b;

    if (regex_match(a.c_str(),b.c_str()))  
        std::cout << "B matches A.\n";
    else
        std::cout << "B does NOT match A.\n";
}
