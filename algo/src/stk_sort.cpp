/*
    Sort a int stack (not in-place, the result goes to a new stack)

    Algorithm:
        Input stack:  top 2 3 1 base
        Result stack: (expected:  top 3 2 1 base)
        
        pop the input stack, store the top in the buf.

        while (stack r is empty || r.top() > buf)
            pop the top of stack r and insert back to input stack
        }

        push the buf into stack r
        
    Time:   O(N^2)
    Space:  O(N)

    Date: 10/23/2011
 */
#include <iostream>
#include <stack>
#include "algo.hpp"

std::stack<int> sort_stk(std::stack<int>& stk)
{
    std::stack<int> r;

    while (!stk.empty()) {
        int buf = stk.top();
        stk.pop();

        while (!r.empty() && r.top() > buf) {
            stk.push(r.top());
            r.pop();
        }

        r.push(buf);
    }

    return r;
}


void TEST_sort_stack()
{
    std::cout << "TEST: sort a stack.\n";
    
    std::stack<int> stk;

    stk.push(7);
    stk.push(2);
    stk.push(3);
    stk.push(7);
    stk.push(8);
    stk.push(5);
    
    std::cout << "Input stack: \n";
    printStack(stk);

    std::stack<int> res = sort_stk(stk);
    
    std::cout << "\nSorted stack: \n";
    printStack(res);
}
