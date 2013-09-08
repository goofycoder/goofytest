#include "algo.hpp"
#include <sstream>
#include <vector>

// Convert an integer value to string
std::string intToStr(int val) 
{
    std::ostringstream ss;
    ss << val;
    return ss.str();
}

// minimum of three integers
int minOfThree(int a, int b, int c) 
{
    if (a<b) {
        if (c<a) return c; 
        else     return a;    
    } else {
        if (c<b) return c;
        else     return b;
    }
}

void swapInt(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void printIntArray(const int *arr, int len)
{
    std::cout << "The array is: ";
    for (int i=0; i<len; i++) {
        std::cout << arr[i] << " ";
    }
    
    std::cout << "\n";
}

void printVector(const std::vector<int> &v)
{
    //std::vector<int>::iterator it = v.begin();
    auto it = v.begin();    

    for (; it!=v.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << "\n";
}

void print_2D_array(int** table, const int width, const int height)
{
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            std::cout << table[i][j] << "\t";
        }
        std::cout << "\n";
    }

    std::cout << "\n";
}
