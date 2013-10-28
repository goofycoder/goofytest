/*
    read/print the last K lines in a file.

    Algorithm:
        use a K size circular array to store last K strings
    
    Note:
        Be careful with the index when traversing the circular array.

    Date: 10/27/2013
 */
#include <iostream>
#include <vector>
#include <fstream>
#include "algo.hpp"

void read_last_k_line(std::string filename, int k)
{
    std::ifstream f_in(filename);
    
    std::string str;   

    std::string str_arr[k];

    int i=0;
    while(std::getline(f_in, str)) {
        str_arr[i] = str;
        i = (i+1)%k;   
    }

    int j=i;
    do {
        std::cout << str_arr[j] << "\n";
        j = (j+1)%k;
    } while (j!=i);
}

void TEST_read_last_k_line()
{
    std::cout << "TEST read last K lines from file.\n";

    std::string file;
    std::cout << "Enter the file name (hint: k_line.txt): ";
    std::cin >> file;

    std::vector<std::string> v;

    readFileToVector(file, v);

    printStrVector(v);

    std::cout << "Enter K (specify how many lines read from the end of file): ";
    int K;
    std::cin >> K;

    read_last_k_line(file, K);
}
