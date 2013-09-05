/*
   Design a stack that supports push, pop, and retrieving the minimum element in constant time.

    Idea: Use an extra stack to maintain the minimums.

    - To retrieve the current minimum, just return the top element from minimum stack.
    - Each time you perform a push operation, check if the pushed element is a new minimum. 
        * If it is, push it to the minimum stack too.
    - When you perform a pop operation, check if the popped element is the same as the current minimum. 
        * If it is, pop it off the minimum stack too.
 */

#include <stack>
#include <iostream>

enum stk_error {
    STK_EMPTY = -99,
};

class min_stack {
public:
    int pop();
    void push(int data);
    int get_min() const;
    int top() const;

private:
    std::stack<int> main_stack;
    std::stack<int> aux_stack;
};

int min_stack::pop() 
{
    if (main_stack.empty() || aux_stack.empty()) {
        return STK_EMPTY;
    } 

    int data = main_stack.top();
    main_stack.pop();

    if (data == aux_stack.top()) {
        aux_stack.pop();
    }

    std::cout << "POP " << data << " out of stack.\n";
    return data;
}

void min_stack::push(int data) 
{
    main_stack.push(data);

    if (aux_stack.empty() || 
        data <= aux_stack.top()) {
        aux_stack.push(data);
    }
    
    std::cout << "PUSH " << data << " into stack.\n";
}

int min_stack::get_min() const
{
    if (aux_stack.empty()) {
        return STK_EMPTY;
    } else {
        return aux_stack.top();
    }
}

int min_stack::top() const
{
    if (main_stack.empty()) {
        return STK_EMPTY;
    } else {
        return main_stack.top();
    }
}   

void TEST_min_stack() 
{
    min_stack mstk;

    mstk.push(30);
    mstk.push(10);
    mstk.push(20);
    mstk.push(5);

    int rv = mstk.get_min();
    std::cout << "min: " << rv << "\n";

    mstk.pop();
    rv = mstk.get_min();
    std::cout << "min: " << rv << "\n";
}
