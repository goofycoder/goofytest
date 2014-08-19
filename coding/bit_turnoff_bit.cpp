/*
 *  turn off the bit at pos.  pos starts from 0 from the least significant end.
 */

#include <iostream>
#include <cstdlib>
using namespace std;

void turn_off_bit(int& d, int pos)
{
    d &= ~(1<<pos);
}

int main(int argc, char* argv[])
{
    if(argc!=3) {
        cout << "./turn_off_bit <input_int> <position_to_turn_off> \n";
        return 1;
    }

    int d = atoi(argv[1]);
    int n = atoi(argv[2]);

    cout << "Input int: " << d << endl;

    turn_off_bit(d, n);

    cout << d << endl;

    return 0;
}
