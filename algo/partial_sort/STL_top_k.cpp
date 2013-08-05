/*
 *  STL implementation of top-K problem:
 *      - select smallest/largest k elements from data stream
 * 
 *  std::partial_sort()
 *  std::partial_sort_copy()   
 *  std::greater<int>()
 */
#include <algorithm>
#include <vector>
#include <iostream>
 
#define K 5

void STL_top_k(std::vector<int> &v_in);
void STL_top_k_copy(std::vector<int> &v_in, std::vector<int> &v_out);

int main()
{
    static const int arr[] = {25, 7, 4, 2, 8, 6, 1, 9, 0, 3};
    std::vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]) );

    std::cout << "Input array : ";
    for (int a : v) {
        std::cout << a << " ";
    }
    std::cout << "\n";
    
    std::cout << "\nIn-place top-k selection: (input array partially sorted)\n";
    std::cout << "Output array: ";
    STL_top_k(v);
    
    std::cout << "\nTop-k selection: (output to the vector, input array unchanged).\n";
    std::vector<int> v_in(arr, arr + sizeof(arr)/sizeof(arr[0]) );
    std::vector<int> v_out(K);

    STL_top_k_copy(v_in, v_out);

    for (int a : v_out) {
        std::cout << a << " ";
    }
    std::cout << "\n";

    
    return 0;
}

/* In-place */ 
void STL_top_k(std::vector<int> &v_in)
{
    std::partial_sort(v_in.begin(), v_in.begin()+K, v_in.end());
    
    for (int a : v_in) {
        std::cout << a << " ";
    }
    std::cout << "\n";
}

/* yield output, input array changed */
void STL_top_k_copy(std::vector<int> &v_in, std::vector<int> &v_out)
{
    std::partial_sort_copy(v_in.begin(),  v_in.end(), 
                           v_out.begin(), v_out.end(),
                           std::greater<int>());         // greater(): max K
                                                         // by default: min K
}
