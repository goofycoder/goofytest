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

void readFileToVector(const std::string& filename, std::vector<std::string>& v)
{
    std::ifstream f_in(filename);

    std::string str;
    while(std::getline(f_in, str)) {
        v.push_back(str);
    }
}

void printStrVector(const std::vector<std::string>& v) 
{
    //std::vector<std::string>::iterator it = v.begin();
    auto it = v.begin();    

    for (; it!=v.end(); ++it) {
        std::cout << *it << "\n";
    }

    std::cout << "\n";
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

bool isMember(const std::vector<int> &v, int d)
{
    for(int i=0; i<v.size(); i++) {
        if (v[i] == d)
            return true;
    }

    return false;
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

void printStack(std::stack<int> stk)
{
    if (stk.empty()) {
        std::cout << "Empty stack.\n";
        return;
    }   
    
    std::cout << "=== Stack Top ===\n";
    while(!stk.empty()) {
        std::cout << stk.top() <<"\n";
        stk.pop();
    }
    std::cout << "=== Stack Base ===\n";
}


/* ==================== Bit-related APIs ========================*/
/* Note: does not print the sign bit.
 *       TO-DO: negative number needs to be further verified.
 */
void print_int_by_bit(const int d)
{
    int t;          // unsigned version of d
    if (d<0) {
        t = -d;
    } else {
        t = d;
    }

    int flag = 0;       // flag that signals the start of print
    for(int i=30; i>=0; i--) {
        if (flag==0 && t>>i == 1) {
            flag = 1;
        } 
        
        if (flag == 1) {
            std::cout << (t>>i);           
        }

        // set the checked bit to 0
        t = t&((1<<i)-1);
    }

    std::cout << "\n";
}

/* integer:    **...**
 * pos:       31     0 
 */
bool check_bit_one(const int num, int pos)
{
    return ((num>>pos & 1) == 1);
}

void set_bit_one(int& num, int pos) 
{
    num |= (1<<pos);
}

void set_bit_zero(int& num, int pos)
{
    num &= ~(1<<pos);
}
/* =================================================================*/


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
