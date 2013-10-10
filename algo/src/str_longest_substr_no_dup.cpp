/*
    Longest substring without duplicate characters.

    Algorithm:
        1. build a int table of NUM_CHAR (256), each entry initialized to -1.
        2. maintain the bounds of longest substring (left, right).
        3. scan the input string s: 
            if table[s[i]] == -1    // not a dup char
                set table[s[i]] to i
                update the right bound to i
            else                    // a dup
                set 'right' to i-1
                check whether it's longer than previous max
                update 'left' to table[s[i]]+1  // table[s[i]]+1 is the next char of previous occurance
                update table[s[i]] to the current i                
 */

#include <iostream>
#include <string>

#define NUM_CHAR 256
int table[NUM_CHAR];

std::string longest_substr_no_dup(std::string str,
                                  int& max_left, 
                                  int& max_right)
{
    int left = 0;
    int right = 0;
    int max_len = 1;
    int len = str.length();

    // initialize the table
    for(int j=0; j<NUM_CHAR; j++) {
        table[j] = -1;
    }

    for(int i=0; i<len; i++) {
        std::cout << "table[str[i]]: " << table[str[i]] << "\n";

        if (table[str[i]] == -1) {  // not a dup
            table[str[i]] = i;
            right = i;
        } else {        // dup char found
            // check the substr before the dup 
            right = i-1;
            if (right-left+1 > max_len) {
                max_left = left;
                max_right = right;
                max_len = max_right-max_left+1; 
            }

            left = table[str[i]]+1;
            right = left;
            table[str[i]] = i;
        }
    }
    
    return str.substr(max_left, max_right-max_left+1);
}

void TEST_longest_substr_no_dup()
{
    std::cout << "TEST longest substring without dup char.\n";

    std::cout << "Enter input string: ";

    std::string s;
    std::string res;
    std::cin >> s;

    int max_left  = 0;
    int max_right = 0;

    res = longest_substr_no_dup(s, max_left, max_right);

    std::cout << "Longest non-dup substring is:\n" << res << "\n"
              << "from " << max_left << " to " << max_right << "\n";
}
