/*
    unordered map: (C++0x)
        - could be used to implement key-value store
 */

#include <unordered_map>
#include <string>
#include <iostream>

typedef std::unordered_map<std::string, double> stringmap;

static void unordered_map_example();

static void unordered_map_example()
{
    stringmap score_board = {
        {"Patriots", 23.7},
        {"Colts", 20.1},
        {"Dolphins", 15.3} 
    };

    std::string team;
    std::cout << "Enter team name: ";
    std::cin >> team;

    std::cout << "The score is: " << score_board[team] << "\n";
}

void TEST_unordered_map()
{
    unordered_map_example();
}
