/*
   Longest Common Sequence

    Example: 
        st2 = abxycz
        st2 = xabcyz

        the longest common seq: abyz
 */
#include <iostream>
#include <string>
#include "algo.hpp"

int lcs(const std::string& s1, const std::string& s2)
{
    int m=s1.length();
    int n=s2.length();
    
    char **b = new char*[m+1];
    for(int i=0; i<m+1; i++) {
	    b[i]=new char[n+1];
    }

    int c[m+1][n+1];

    for(int i=1; i<=m; i++)
	    c[i][0]=0;

    for(int j=0; j<=n; j++)
    	c[0][j]=0;

    for(int i=1; i<=m; i++) {
    	for(int j=1; j<=n; j++) {
	        if(s1[i-1]==s2[j-1]) { // i, j start both at idx 1, but string starts with idx 0
		        c[i][j]=c[i-1][j-1]+1;
        		b[i][j]='\\';
	        } else {	
        		if(c[i-1][j]>=c[i][j-1]) {
		            c[i][j]=c[i-1][j];
        		    b[i][j]='^';
		        } else {
        		    c[i][j]=c[i][j-1];
		            b[i][j]='<';
		        }       
	        }
	    }   
    }
	
    for(int i=0; i<m+1; i++) {
    	for(int j=0; j<n+1; j++) {
	        std::cout << b[i][j] << " ";
	    }   
    	std::cout << "\n";
    }

    std::cout << "\n";
    for(int i=0; i<m+1; i++) {
	    for(int j=0; j<n+1; j++) {
	        std::cout << c[i][j] << " ";
	    }
    	std::cout << "\n";
    }

    std::cout << "Longest common sequence: ";
    printLCS(&b[0], s1, m, n);
    std::cout << "\n";

    for(int i=0; i<m+1; i++) {
	    delete b[i];
    }
    delete b;

    return c[m][n];
}

void printLCS(char** b, const std::string& s, int i, int j)
{
    if(i==0 || j==0)
	return;

    if(b[i][j]=='\\') {
    	printLCS(b, s, i-1, j-1);
	    std::cout << s[i-1] << " ";		// idx starts with 1, but in string it starts with 0
    } else {
	    if(b[i][j]=='^')
	        printLCS(b,s,i-1,j);
	    else
	        printLCS(b,s,i,j-1);
    }
}

int TEST_LongestCommonSeq()
{
    std::string str1, str2;
    
    std::cout << "\n *** TEST for Longest Common Sequence ***\n"
              << "Enter string 1: ";
    std::cin>>str1;

    std::cout<< "Enter string 2: ";
    std::cin>>str2;
        
    int len = lcs(str1, str2);
    std::cout << "len: " << len << "\n";

    return 0;
}
