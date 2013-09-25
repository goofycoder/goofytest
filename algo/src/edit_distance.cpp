#include "algo.hpp"

/* Recursive version */ 
int editDistance(const std::string& s, const std::string& t)
{
    return editDistanceInt(&s[0], s.length(), &t[0], t.length());
}

int editDistanceInt(const char *s, int len_s, const char *t, int len_t)
{
    if (len_s==0) {
        return len_t;
    }
    
    if (len_t==0) {
        return len_s;
    }

    int cost;
    if ( s[len_s-1]==t[len_t-1] ) 
        cost = 0;
    else
        cost = 1;

    return minOfThree(editDistanceInt(s, len_s-1, t, len_t)+1,
                      editDistanceInt(s, len_s, t, len_t-1)+1,
                      editDistanceInt(s, len_s-1, t, len_t-1) + cost);
}

void TEST_editDistance()
{
    std::string s, t;
    
    std::cout << "\n *** TEST for the edit distance between 2 strings ***\n"
              << "Enter 1st string: ";
    std::cin >> s;

    std::cout << "Enter 2nd string: ";
    std::cin >> t;

    int dist = editDistance(s,t);

    std::cout << "Edit distance: " << dist << "\n";
}
