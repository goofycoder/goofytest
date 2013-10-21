/*
    Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column is set to 0. (In place)
   
    Algorithm:
        2 Aux arrays:
            zero_row[num_row];
            zero_col[num_col];

        If m[row][col] == 1
            Set to zero_row[i] = 1
            Set to zero_col[i] = 1

        Traverse the matrix, for m[i][j]
            if zero_row[i]==1 or zero_col[j]==1
                set m[i][j] to 0
    
    Date: 10/21/2013
 */
#include <iostream>
#include <string>
#include "algo.hpp"

void matrix_set_zero(int**& matrix, int row, int col)
{
    int zero_row[row];
    int zero_col[col];

    for(int i=0; i<row; i++) {
        zero_row[i] = 0;
    }

    for(int i=0; i<col; i++) {
        zero_col[i] = 0;
    }

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if (matrix[i][j] == 0) {            
                zero_row[i]=1;
                zero_col[j]=1;
            }
        }
    }

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if (zero_row[i] == 1 || zero_col[j] == 1) {
                matrix[i][j] = 0;                   
            }
        }
    }
}

void TEST_matrix_set_zero()
{
    std::cout << "TEST algorithm that if an element in an MxN matrix is 0, its entire row and column is set to 0.\n";

    int row, col;
    std::cout << "Enter the number of rows: ";
    std::cin >> row;

    std::cout << "Enter the number of columns: ";
    std::cin >> col;

    int** matrix = NULL;
    alloc_matrix(matrix, row, col);
    
    std::string filename;
    std::cout << "Enter the filename to read matrix from (hint: matrix_zero.txt): ";
    std::cin >> filename;

    readMatrixFromFile(filename, matrix, row, col);

    std::cout << "Input matrix: \n";
    printMatrix(matrix, row, col);

    matrix_set_zero(matrix, row, col);

    std::cout << "\nThe result matrix: \n";
    printMatrix(matrix, row, col);
    
    free_matrix(matrix, row, col);   
}
