/*
    print all the subset of a given set.

    Example: set is (1,2,3)
        Output:
            (), (1), (2), (3), (1,2), (1,3), (2,3), (1,2,3)
 
    Algorithm:
        Use integer as bitmap (1 means include this element, 0 means not)
        
        (1,2,3) and mask is 5 (101)  ==> subset (1,3)

    Date: 10/27/2013
 */
#include <iostream>
#include <vector>
#include <set>
#include "algo.hpp"

static std::set<int> mask_set_to_subset(int mask, std::set<int>& s);

void all_subset(std::set<int>& s)
{
    int size = s.size();
    int ctr=0;

    int max_mask = (1<<size)-1;         // parenthesis here is a MUST
    
    for(int i=0; i<=max_mask; i++) {
        std::set<int> sub = mask_set_to_subset(i, s);
        printSet(sub);
        ctr++;   
    }

    std::cout << "Total subset#: " << ctr << "\n";
}

static std::set<int> mask_set_to_subset(int mask, std::set<int>& s)
{
    std::set<int> sub;
    int len = s.size();

    int arr[len];
   
    auto it = s.begin();
    for(int i=0; it!=s.end(); it++) {
        arr[i] = *it;
        i++;
    }

    for(int i=0; i<len; i++) {
        if (mask&(1<<i)) {      // bit is set
            sub.insert(arr[i]);
        }        
    }

    return sub;
}

void TEST_all_subset()
{
    std::cout << "TEST print all subset of a given set.\n";

    std::cout << "Enter filename that contains the input array (set) [hint: subset.txt]: ";
    std::string file;
    std::cin >> file;

    std::vector<int> v;
    readArrayFromFile(file, v);

    std::set<int> s;
    for(int i=0; i<v.size(); i++) {
        s.insert(v[i]);
    }

    all_subset(s);
}
