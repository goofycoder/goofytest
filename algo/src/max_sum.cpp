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
    std::string dflt_file_name("maxsum_input.dat");

    std::cout << "\n *** TEST for Max Sum In Array ***\n";

    std::cout << "Input file that contains data (default: maxsum_input.dat): ";
    
    std::cin >> file_name;

#if 0
    if (file_name == "\n") {
        std::cout << "Using default";
        file_name = dflt_file_name;
    } else {
        std::cout << "using othe files\n";
    }
#endif

    std::ifstream f_in(file_name);

    std::string str;
    std::string token;

    std::getline(f_in, str);
    std::cout << str << "\n";

    std::stringstream iss(str);
    std::vector<int> v;
    
    while (iss >> token) {
        std::cout << "token: " << token << "\n";
        v.push_back(std::stoi(token));
    }

    int sum = maxSum(v, v.size());

    std::cout << "Max Sum in Array is: " << sum << "\n";
}

