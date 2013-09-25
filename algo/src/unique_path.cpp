/*
    A robot is located at the top-left corner of a m x n grid. 
    The robot can only move either down or right at any point in time. 
    The robot is trying to reach the bottom-right corner of the grid. 
    How many possible unique paths are there?

    Algorithm: bottom-up Dynamic programming.

    1.Fill the [width-1] column with '1'
    2.Fill the [height-1] row with '1'
    3.Start with table[height-2][width-2]:
        the value of this grid is the number in right grid + the number in down grid  
    4. keep doing this till the very upper left grid.
    5. the number in table[0][0] is the total number of unique paths
    
    Extension:
        The obstacle is located at (x,y). Compute the total number of unique path.
   
    Solution:
        Set table[y][x] = 0, follow the algorithm above to compute the #unique path.
 */

#include <iostream>
#include "algo.hpp"

int unique_path(int** table, int width, int height)
{
    // fill the [width-1] column with '1'
    for(int i=0; i<height; i++)
        table[i][width-1] = 1;

    // fill the [height-1] row with '1'
    for(int j=0; j<width; j++)
        table[height-1][j] = 1;

    for(int i=width-2; i>=0; i--) {
        for (int j=height-2; j>=0; j--) {
            table[j][i] = table[j+1][i] + table[j][i+1];
        }
    }       

    return table[0][0];
}

void TEST_unique_path()
{
    std::cout << "========= Test the unique path in 2-d array. ====================\n";   
    
    int height, width;
    std::cout << "Enter the height(>1) of table (2-d array)\n";
    std::cin >> height;

    std::cout << "Enter the width(>1) of table (2-d array)\n";
    std::cin >> width;

    // alloc memory for rectangle
    int** table = new int*[height];

    for(int i=0; i<height; i++) {
        table[i] = new int[width];
    }

    // compute the total number of unique paths
    int paths = unique_path(table, width, height);
    
    // print rectangle
    print_2D_array(table, width, height);

    std::cout << "The number of unique paths: " << paths << "\n";

    // free the memory
    for(int i=0; i<height; i++) {
        delete[] table[i];
    }
    delete[] table;
}
