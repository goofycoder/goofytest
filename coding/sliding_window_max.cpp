/*
 *  given an array and a sliding window size, generate another array that  
 *  each element in output array is the max number in each sliding window
 *  Example:
 *      Input: {1, 3, -1, -3, 5, 3, 2, 6, 7} with Window size:  2
 *      Output:{   3,  3, -1, 5, 5, 3, 6, 7}
 */

#include <deque>
#include <iostream>

using namespace std;

void sliding_window_max(int arr[], int len, int window_size, int max_arr[])
{
    deque<int> dq;
    int i;

    for(i=0; i<len; i++) {
        if(arr[i] > dq.front()) {
            while(!dq.empty()) {
                dq.pop_front();
            }

            dq.push_front(arr[i]);
        } else {
            // may need to insert to the end
            while (arr[i]>dq.back()) {
                dq.pop_back();
            }

            if(dq.size() == window_size) {
                // full queue
                dq.pop_front();
            }

            dq.push_back(arr[i]);
        }

        if(i>=window_size-1) {
            max_arr[i-(window_size-1)] = dq.front();
        }
    }
}

int main()
{
    int arr[] = {1, 3, -1, -3, 5, 3, 2, 6, 7}; 
    int len = sizeof(arr)/sizeof(int);

    int window_size = 2;
    int max_arr[len-window_size+1];

    cout << "Input array : ";
    for(int i=0; i<len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    sliding_window_max(arr, len, window_size, max_arr);

    cout << "Output array:   ";
    for(int i=0; i<len-window_size+1; i++) {
        cout << max_arr[i] << " ";
    }
    cout << endl;

    return 0;
}
