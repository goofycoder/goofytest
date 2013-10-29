/*
    Search target value in a matrix.
    Each row/column is sorted in ascending order.

    Algorithm:
        Starting at the upper-right corner.
    
    Complexity:
        O(m+n)      // m: #row, n: #column

    Date:   10/28/2013
 */
#include <iostream>
#include <string>
#include "algo.hpp"

bool matrix_search(int target, int** m, int row, int col, 
                   int& tgt_row, int& tgt_col)      // output
{
    int i=0;        // row
    int j=col-1;    // column

    while(i<row && j>=0) {
        if (m[i][j] == target) {
            tgt_row = i;
            tgt_col = j;
            return true;
        }

        if (m[i][j] < target) {
            i++;
        } else {
            j--;
        }
    }    

    return false;
}

void TEST_matrix_search()
{
    std::cout << "TEST matrix search()\n";

    std::cout << "Enter file name that contains matrix (hint: matrix_search.txt): \n";
    std::string file;
    std::cin >> file;

    std::cout << "Enter the search target: ";
    int target;
    std::cin >> target; 

    int row, col;
    std::cout << "Enter the number of rows: ";
    std::cin >> row;

    std::cout << "Enter the number of columns: ";
    std::cin >> col;

    int** matrix = NULL;
    alloc_matrix(matrix, row, col);
    
    readMatrixFromFile(file, matrix, row, col);

    std::cout << "Input matrix: \n";
    printMatrix(matrix, row, col);

    int tgt_row = -1;
    int tgt_col = -1;

    if (matrix_search(target, matrix, row, col, tgt_row, tgt_col)) {
        std::cout << "Found at (" << tgt_row << "," << tgt_col << ").\n";
    } else {
        std::cout << "Cannot find in matrix.\n";
    }

    free_matrix(matrix, row, col);
}
