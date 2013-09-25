/* 
 * Find the max sum of consecutive integers in the array
 * Algorithm:
 *      Step 1: build an Aux array that each entry in the array 
 *              indicates the max sum ends this
 *           -  aux[0] = a[0]
 *           -  iterate through the list
 *           -  if aux[i-1] + a[i] > a[i]
 *                  aux[i] = aux[i-1]+a[i]
 *              else 
 *                  aux[i] = a[i]
 *      Step 2: find the max in array aux
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "algo.hpp"

int maxSum(const std::vector<int>& arr, const unsigned len) 
{
    int aux[len];

    aux[0] = arr[0];

    for (unsigned i=1; i<len; i++) {
        if (aux[i-1] + arr[i] > arr[i]) {
            aux[i] = aux[i-1] + arr[i];
        } else {
            aux[i] = arr[i];
        }
    }

    int max_sum = aux[0];
    for (unsigned i=0; i<len; i++) {
        if (aux[i]>max_sum) {
            max_sum = aux[i];
        }
    }

    return max_sum;
}

void TEST_maxSum() 
{
    std::string file_name;

    std::cout << "\n *** TEST for Max Sum In Array ***\n";

    std::cout << "Input file (default: maxsum_input.dat) that contains data: ";
    std::cin >> file_name;

    std::vector<int> v;
    readArrayFromFile(file_name, v);
    
    std::cout << "Input array: ";
    printVector(v);

    int sum = maxSum(v, v.size());

    std::cout << "\nMax Sum in Array is: " << sum << "\n";
}
