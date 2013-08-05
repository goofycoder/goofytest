/*
 *  Use partial_sort STL algorithm to find the median and
 *  do order statistics, such as find the 2nd largest number in vector.
 * 
 *  -std=c++0x
 *
 *  getMedian(vector): 
 *      - return the median of a vector of ints.
 *  
 *  getSecLargest(vector):
 *      - return the second largest number in the vector 
 *      - just as an example, could be more general
 *   
 *  STL: nth_element(first, n_th, last)
 *      Partially sorts the range [first, last) in ascending order 
 *  so that all elements in the range [first, nth) are less than those 
 *  in the range [nth, last). 
 */
#include <iostream>
#include <vector>
#include <algorithm>

void showVector(std::vector<int> &v);
int  getMedian(std::vector<int> &v);
int  getSecLargest(std::vector<int> &v); 

int main()
{
    std::cout << "Origin data stream:\n";
    std::vector<int> v{5, 6, 4, 3, 2, 6, 7, 9};      // c++0x
    showVector(v);
    std::cout << "\n";

    int median = getMedian(v);
    std::cout << "The median is " << median << '\n';
    std::cout << "\n";
    
    int secLargest = getSecLargest(v);
    std::cout << "The second largest element is " << v[1] << '\n';
}

int getMedian(std::vector<int> &v)
{
    std::nth_element(v.begin(), v.begin() + v.size()/2, v.end());
    std::cout << "Partially sort to get median:\n";
    showVector(v);
    
    int median = v[v.size()/2];
    return median;
}

int getSecLargest(std::vector<int> &v)
{
    std::nth_element(v.begin(), v.begin()+1, v.end(), std::greater<int>());
    std::cout << "Partially sort to get secondLargest:\n";
    showVector(v);
    
    int ret = v[1];
    return ret;
}

void showVector(std::vector<int> &v)
{
    for (int a : v) {
        std::cout << a << " ";
    }
    std::cout << "\n";
}
