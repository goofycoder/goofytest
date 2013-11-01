// The idea is similar to shuffle the cards
// pick one char in the string, swap to the beginning, do the shuffle(permute) to the rest of string
//     and swap the chosen char back to its orginal position.
// iterate through string for the same process
#include <iostream>
#include <string>
#include <vector>

static void _strPermute(std::string s, unsigned start);	   // duplicate version

static void _strPermute_NoDup(std::string s, unsigned start);   // no duplicate version

static bool member(std::vector<char> &v, char c);

void strPermute(std::string str) 
{
	_strPermute(str, 0);
}

void strPermute_NoDup(std::string str)
{
	_strPermute_NoDup(str, 0);
}

static void _strPermute(std::string s, unsigned start) 
{
    if (start == s.size()) {
	    std::cout<<s<<"\n";
		return;
	}
	
	for (unsigned i=start; i<s.size(); ++i) {
	    std::swap(s[start], s[i]);
		_strPermute(s, start+1);
		std::swap(s[start], s[i]);
    }
}

static void _strPermute_NoDup(std::string s, unsigned start) 
{
    if (start == s.size()) {
	    std::cout<<s<<"\n";
	    return;
	}

	std::vector<char> v;            // store the unique character set 
                                    // example: ("abbaa" ==> <'a','b'>)
	for (unsigned int i=start; i<s.size(); ++i) {
	    if(member(v,s[i])) continue;   // if the character is duplicated	
	    else v.push_back(s[i]);

	    std::swap(s[start], s[i]);
	    _strPermute_NoDup(s, start+1);
	    std::swap(s[start], s[i]);
	}
}

static bool member(std::vector<char> &v, char c) 
{
	std::vector<char>::iterator it = v.begin();

	for(;it!=v.end();it++) {
		if(*it == c) return true;
	}

	return false;
}

void TEST_str_permute() 
{
    std::cout << "Test for string permutation. (Both has_dup and no_dup.)\n";

    std::cout << "Enter the input string: \n";
	std::string str;
    std::cin >> str;

    std::string str_1(str);
    std::string str_2(str);

    std::cout << "\n=== String Permutation (may have dup) ===\n";
	strPermute(str_1);		    // has duplicate version
	
    std::cout << "\n=== String Permutation (no dup) ===\n";
    strPermute_NoDup(str_2);	// no duplicate version
}
