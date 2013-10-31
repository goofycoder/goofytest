/*
    Idea: 
        - Recursion
        - Keep track of open and close brackets.
 */
#include <iostream>

#define MAX_SIZE 100

static void _printParenthesis(int n, int pos, int open, int close);

/* print all the valid parenthesis of n */
void printParenthesis(int n)
{
    if (n>0)
        _printParenthesis(n, 0, 0, 0);

    return;
}

void _printParenthesis(int n, int pos, int open, int close)
{
    static char str[MAX_SIZE];

    if (close==n) {
        std::cout << str << "\n";
        return;
    }

    if (open>close) {
        str[pos] = '}';
        _printParenthesis(n, pos+1, open, close+1);
    }

    if (open<n) {
        str[pos] = '{';
        _printParenthesis(n, pos+1, open+1, close);
    }
}

void TEST_print_parenthesis()
{
    std::cout << "TEST print parenthesis.\n";
    
    int n;
    std::cout << "Enter the number of parenthesis.\n";
    std::cin >> n;

    printParenthesis(n);
}
