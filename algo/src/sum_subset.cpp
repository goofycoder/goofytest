/* 
    Given a target number, print all the combinations that sums up to the target.

    Example:
        Target: 7
        Input array: 2 3 6 7
        Output:
            2 2 3
            2 3 2
            3 2 2
            7

    Algorithm:
        backtracking. O(n)   
        
        result[MAX_LEN]

        foo(target, input_array)
            => foo_(target, pos, input_array) {
                    if (target == 0) 
                        print_result
                    else if (target > 0)
                        result[pos] = input_array[i]
                        foo_(target-input_array[i], pos+1, input_array)
               }
 */
#include <iostream>
#include <string>
#include <vector>
#include "algo.hpp"

const int MAX_LEN = 100;

static void _sum_subset(int sum, int pos, int* input, int len);

void sum_subset(int sum, int* input, int len)
{
    _sum_subset(sum, 0, input, len);
}

void _sum_subset(int sum, int pos, int* input, int len)
{
    static int result[MAX_LEN];

    if (sum == 0) {
        printIntArray(result, pos);
    } else if (sum>0) {
        for(int i=0; i<len; i++) {
            result[pos] = input[i];
            _sum_subset(sum-input[i], pos+1, input, len);
        }
    }
}

void TEST_sum_subset()
{
    std::cout << "TEST: print all combinations from subset that sums up to a given number.\n";
    
    std::cout << "Enter the number that is the sum of target: ";
    int target;
    std::cin >> target;

    std::cout << "Enter the file name that contains the array (hint: sum_subset.txt): \n";
    std::string filename;
    std::cin >> filename;

    std::vector<int> v;
    readArrayFromFile(filename, v);

    int len = v.size();
    int input[len];

    for(int i=0; i<len; i++) {
        input[i] = v[i];
    }

    printIntArray(input, len);

    sum_subset(target, input, len);
}
