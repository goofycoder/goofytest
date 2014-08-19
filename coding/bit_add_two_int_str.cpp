/*  
 *  Add two integer strings
 *      Example:
 *          str1 = "101"
 *          str2 =  "11"
 *
 *  sum should be: "1000"
 */
#include <iostream>
#include <string>
using namespace std;

string add_two_int_str(string s1, string s2)
{
    string r;

    int len1 = s1.size();
    int len2 = s2.size();

    if (len1>len2) {
        while(len2<len1) {
            s2 = '0'+s2;
            len2++;
        }
    }

    if (len2>len1) {
        while(len1<len2) {
            s1 = '0'+s1;
            len1++;
        }
    }

    int d1, d2, sum, carry=0;
    for(int i=len1-1; i>=0; i--) {
        d1 = s1[i]-'0';
        d2 = s2[i]-'0';
        
        sum = (d1+d2+carry)%2;
        carry = (d1+d2+carry)/2;
    
        r = (char)(sum+'0')+r;
    }

    if (carry) 
        r = '1'+r;

    return r;
}

int main()
{
    string s1 = "101";
    string s2 = "11";

    string r = add_two_int_str(s1, s2);

    cout << "sum: " << r << endl;

    return 0;
}
