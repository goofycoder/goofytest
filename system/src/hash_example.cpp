/*  
    STL Hash function that returns the hash value of a input key.

    The input key could be a string, unique_ptr/shared_ptr, vector, bitset, thread::id ...
 */
#include <iostream>
#include <functional>
#include <string>
#include <memory>

class Object {
public:
    Object(int _d): data(_d) { }

private:
    int data;
};

void TEST_hash()
{
    std::cout << "Enter the string to hash: ";
    std::string str;
    std::cin >> str;

    std::hash<std::string> str_hash;
    std::cout << "The hash of string " << str << " is: " << str_hash(str) << "\n"; 

    std::cout << "Enter the integer to construct the Object:\n";
    int d;
    std::cin >> d;
    
    std::unique_ptr<Object> ptr_obj(new Object(d));

    std::hash<std::unique_ptr<Object> > obj_hash;
    std::cout << "The hash of object is: " << obj_hash(ptr_obj) << "\n"; 
}
