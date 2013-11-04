/*  
    Unordered_map example:
        Build a simple NFL player DB. Using first_name as the key (for demo purpose).
        Also display the index in the hash table.
 */
#include <iostream>
#include <unordered_map>
#include <string>

class Record {
public:
    Record(int _key, std::string fn, std::string ln, int _age): key(_key), first_name(fn), last_name(ln), age(_age) { }
    void display() const;

private:
    int         key;
    std::string first_name;
    std::string last_name;
    int         age;
};

void Record::display() const
{
    std::cout << "Record key: " << key
              << "\n\t" << first_name << "\t" << last_name << "\tAge: " << age << "\n";
}

typedef std::unordered_map<std::string, Record*> record_map; 

void TEST_hashtable() 
{
    record_map rec_map;

    record_map::hasher fn = rec_map.hash_function();
    
    Record* rec_a = new Record(1, "Tom", "Brady", 36);
    Record* rec_b = new Record(2, "Peyton", "Manning", 37);
    Record* rec_c = new Record(3, "Alex", "Smith", 30);
    Record* rec_d = new Record(4, "Aaron", "Rogers", 28);
    
    rec_map["Tom"] = rec_a;
    rec_map["Peyton"] = rec_b;
    rec_map["Alex"] = rec_c;
    rec_map["Aaron"] = rec_d;

    std::cout << "Player DB: \n"; 
    for (auto& x: rec_map) {
        x.second->display();
    }

    std::cout << "\n DB lookup: \n";
    std::cout << "Enter the first name of player to search: \n";
    std::string fname;
    std::cin >> fname;

    std::cout << "Search result: ";
    std::cout << "hash table index: " << fn(fname) << "\n";
    rec_map[fname]->display();
    
    for (auto& x: rec_map) {
        delete x.second;
    }
}


