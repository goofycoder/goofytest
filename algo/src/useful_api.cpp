#include "algo.hpp"
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

/*
    Note: this function only read one line. Thus, the array should be 
    put in the first line, delimited by any number of spaces
 
    Input: file name string
    Output: a vector that contains all the numbers in the file 
           (currently only read the first line)
 */
void readArrayFromFile(const std::string& file_name, std::vector<int>& v)
{
    std::ifstream f_in(file_name);

    std::string str;
    std::string token;

    // Only read one line.
    std::getline(f_in, str);

    std::stringstream iss(str);
    
    while (iss >> token) {
        v.push_back(std::stoi(token));
    }
}

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
    return std::min(a, std::min(b,c));
}

void swapInt(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void swapChar(char& a, char& b)
{
    char tmp = a;
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

/* ==================== Matrix-related APIs ========================*/
void alloc_matrix(int**& matrix, int row, int col)
{
    matrix = new int*[row];

    for(int i=0; i<row; i++) 
        matrix[i] = new int[col];
}

void free_matrix(int**& matrix, int row, int col)
{
    for(int i=0; i<row; i++)
        delete[] matrix[i];

    delete[] matrix;
}

void readMatrixFromFile(std::string filename, int**& matrix, int row, int col)
{
    std::ifstream f_in(filename);
    if (!f_in) {
        std::cout << "Cannot open input file.\n";
        return;
    }

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            f_in >> matrix[i][j];
        }
    }

    f_in.close();
}

void printMatrix(int** matrix, int row, int col)
{
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}
/* =================================================================*/
