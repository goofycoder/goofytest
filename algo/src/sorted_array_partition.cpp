/*
    Partition an sorted array to two arrays, which makes the difference between sum of each array 
    is minimum.

    Algorithm:
        Greedy algorithm:

        Compute the sum of the input array.
        Thus, the target sum of each array is sum/2. (target = sum/2).
        Goal is to get the sum of each array as close as to the 'target'.
        start with i=0; Add arr[i] while (sum<target)

        If adding one more element to the 1st partition will make the sum closer to the target,
        add it. The remaining goes to partition 2.

    Date: 10/29/2013
 */
#include <iostream>
#include "algo.hpp"

void partition_sorted_array(int* arr, int len, 
                            std::vector<int>& p1, std::vector<int>& p2)     // output 
{
    int sum = 0;
    for(int i=0; i<len; i++) {
        sum+=arr[i];
    }

    // this is target sum. make the sum of each partition as close as possible to target
    int target = sum/2;

    int i=0;
    int c_sum = 0;          // current sum

    while (c_sum < target) {
        c_sum += arr[i];
        p1.push_back(arr[i]);
        i++;
    }
    
    // check whether adding one more element will bring the sum closer to the target
    int l_diff = target - c_sum;                // diff when c_sum < target
    int g_diff = c_sum + arr[i+1] - target;     // diff when c_sum > target

    if (l_diff > g_diff) {
        i++;
        p1.push_back(arr[i]);
    }    

    // The remaining goes to partition 2
    for (; i<len; i++) {
        p2.push_back(arr[i]);
    }
}

void TEST_partition()
{
    std::cout << "TEST array partition problem.\n";
    
    std::cout << "Input file (default: partition.txt): ";
    std::string file_name;
    std::cin >> file_name;

    std::vector<int> v;
    readArrayFromFile(file_name, v);

    int len = v.size();
    int arr[len];
    for(int i=0; i<len; i++) {
        arr[i] = v[i];
    }
 
    std::vector<int> p1;
    std::vector<int> p2;   
    partition_sorted_array(arr,len, p1, p2);

    std::cout << "Partition 1: \n";
    printVector(p1);
    
    std::cout << "Partition 2: \n";
    printVector(p2);
}
