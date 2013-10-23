/* 
    Implement queue with two stacks.

    two stacks s1 and s2;
        when push(), put into s1
        when pop(),  pop all the elements in s1 and push into s2
                     then pop s2.
 
    Date: 10/22/2013
*/

#include <iostream>
#include <stack>

class MyQ {
public:
    int front();
    int back();

    void push(int a);
    void pop();

    bool empty();

private:
    std::stack<int> s1;
    std::stack<int> s2;
    
    int back_buf;
};

int MyQ::front() 
{
    if (s2.empty()) {
        while(!s1.empty()) {
            int tmp = s1.top();
            s2.push(tmp);
            s1.pop();
        }
    }

    return s2.top();
}

int MyQ::back()
{
    return back_buf;
}

void MyQ::push(int a)
{
    s1.push(a);
    back_buf = a;
}

void MyQ::pop() 
{
    if (s2.empty()) {
        while(!s1.empty()) {
            int tmp = s1.top();
            s2.push(tmp);
            s1.pop();
        }
    }

    if (!s2.empty())
        s2.pop();
}

bool MyQ::empty()
{
    if(s1.empty() && s2.empty()) 
        return true;
    else
        return false;
}

void TEST_MyQ()
{
    std::cout << "TEST MyQ class that implements the queue with two stacks.\n";
   
    MyQ q;

    q.push(7);
    q.push(2);
    q.push(3);

    int f = q.front();    
    int b = q.back();
    std::cout << "Front: " << f << " Back: " << b << "\n";

    q.pop();
    f = q.front();    
    b = q.back();
    std::cout << "Front: " << f << " Back: " << b << "\n";

    q.push(6);
    q.push(5);
    f = q.front();    
    b = q.back();
    std::cout << "Front: " << f << " Back: " << b << "\n";
}
