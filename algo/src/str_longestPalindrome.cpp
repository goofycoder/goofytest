/*
  Transform S into T.
  For example, S = "abba", T = "^#a#b#b#a#$".
  '^' and '$' signs are sentinels appended to each end to avoid bound checking

    O(n^2) solution:
        - iterate through the string and expand at each postion. 
        - save the palindrome substr with max length.

    More efficient algorithm O(n):
        http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
*/
#include <iostream>
#include <string>

static std::string preProcess(std::string s);
static std::string postProcess(std::string s);
static inline int expandAt(std::string s, int c);

std::string longestPalindrome(std::string& s)
{
    std::string t = preProcess(s);
    
    int center = 0;
    int max_len = 0; 
    int len;

    for(int i=1; i<t.length(); i++) {
        len = expandAt(t, i);

        if (len>max_len) {
            center = i;
            max_len = len;
        }
    }

    //the result in the padded string
    std::string p = t.substr(center-max_len+1, 2*max_len-1);

    return postProcess(p);     // remove the padding '#
}

static std::string preProcess(std::string s)
{
    int n = s.length();
    
    if (n == 0) 
        return "^$";
    
    std::string ret = "^";
    
    for (int i=0; i<n; i++)
        ret += "#" + s.substr(i, 1);
 
    ret += "#$";
    return ret;
}

static std::string postProcess(std::string s)
{
    int n = s.length();

    for (int i=0; i<n; i++) {
        if (s[i] == '#') 
            s.erase(i,1);
    }

    return s;
}

static inline int expandAt(std::string s, int c)
{
    int len = 0;

    while (s[c-len] == s[c+len]) {
        len++;
    }

    return len;
}

void TEST_longestPalindrome()
{
    std::cout << "TEST the longest palindrome substring in a string.\n";

    std::string s;
    std::cout << "Enter the input string: ";
    std::cin >> s;

    std::string r = longestPalindrome(s);

    std::cout << "The longest palindrome is: " << r << "\n";
}

#if 0
std::string longestPalindrome(std::string s) 
{
    std::string T = preProcess(s);
    int n = T.length();
    
    int *P = new int[n];
    int C = 0, R = 0;
    
    for (int i = 1; i < n-1; i++) 
    {
        int i_mirror = 2*C-i; // equals to i' = C - (i-C)
    
        P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
    
        // Attempt to expand palindrome centered at i
        while (T[i+1+P[i]] == T[i-1-P[i]])
            P[i]++;
 
        // If palindrome centered at i expand past R,
        // adjust center based on expanded palindrome.
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }
 
    // Find the maximum element in P.
    int maxLen = 0;
    int centerIndex = 0;
    
    for (int i = 1; i < n-1; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }
  
    delete[] P;
  
    return s.substr((centerIndex-1-maxLen)/2, maxLen);
}
#endif




