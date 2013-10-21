/*  
    Rotate a N*N matrix clockwise with different degrees *IN PLACE*

    Algorithm:
       Rotate the matrix by layers  (like onion)

    Space Complexity:
       Only 4 bytes (int) additional memory (buffer as below) is needed.
 */
#include <iostream>
#include <string>
#include "algo.hpp"

#define NINETY_DEGREE 90

void rotate_matrix_clockwise(int**& matrix, int n, int degree)
{
    switch (degree) {
    case NINETY_DEGREE:
        for(int layer=0; layer < n/2; layer++) {
            int first = layer;
            int last = n-1-layer;

            for(int i=first; i<last; i++) {
                int offset = i-first;

                // buffer the upper-left corner
                int buffer = matrix[first][i]; 

                // upper-left corner 
                matrix[first][i] = matrix[last-offset][first];

                // bottom-left corner
                matrix[last-offset][first] = matrix[last][last-offset];
                
                // bottom-right corner
                matrix[last][last-offset] = matrix[i][last];
        
                // upper-right corner
                matrix[i][last] = buffer;
            }
        }

        break;
    case 180:
        /* To-Do */
        break;
    case 270:
        /* To-Do */
        break;
    default:
        std::cout << "invalid degree to rotate.\n";
        return;   
    }
}

void TEST_rotate_matrix()
{
    std::cout << "TEST rotate matrix.\n";

    int n;
    std::cout << "Enter N for the N*N matrix: ";
    std::cin >> n;

    std::string filename;
    std::cout << "Enter the filename to read matrix from (hint: rotate_matrix.txt): ";
    std::cin >> filename;
    
    int** matrix = NULL;

    alloc_matrix(matrix, n, n);

    readMatrixFromFile(filename, matrix, n, n);

    std::cout << "Input matrix: \n";
    printMatrix(matrix, n, n);

    rotate_matrix_clockwise(matrix, n, NINETY_DEGREE);
    
    std::cout << "Matrix after 90-degree clock-wise rotation: \n";
    printMatrix(matrix, n, n);
    
    free_matrix(matrix, n, n);   
}
