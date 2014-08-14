/*
    float number comparison and sizeof
 */
#include <iostream>
using namespace std;

void test_float()
{
    float f1 = 0.1;
    float f2 = 0.5;

    // f1 is promoted to double 
    // the promotion of float to double can only cause mismatch 
    // when a value (like 0.1) uses more precision bits than the bits of single precision.
    if(f1==0.1)
        cout << "f1==0.1 true\n";
    else
        cout << "f1==0.1 false\n";

    if(f1==0.1f)
        cout << "f1==0.1f true\n";

    // f2 is not promoted to double
    // the promotion of float to double can only cause mismatch 
    // when a value (like 0.1) uses more precision bits than the bits of single precision.
    if(f2==0.5)
        cout << "f1==0.5 true\n";

    if(f2==0.5f)
        cout << "f1==0.5f true\n";

    cout << "sizeof(f1): " << sizeof(f1) << endl;
    cout << "sizeof(0.1): " << sizeof(0.1) << endl;
    cout << "sizeof(0.1f): " << sizeof(0.1f) << endl;
}

int main()
{
    test_float();
    return 0;
}
