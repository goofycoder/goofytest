/*
    Given a char stream, display the first non duplicate character met so far.
    
    For example:
       Stream: mitmechanical
       Answer: mmmiiiiiitttt

    Algorithm: O(n)
        Maintain 3 data structures to store related info
        1. char_map[256]:  store whether the char is met before,
                           if yes, set to 1; otherwise, 0
        2. doubly-linked list:
                - head: the first non-dup char
                - if meet a new non-dup one, insert to the tail. 
                    * update tail, thus insertion could be linear
                - if meet a dup one, remove it from the list
                    * O(1) removal needs the node_map[256] below
        3. node_map[256]
                - initialize all entries to NULL
                - if new char is inserted, update the corresponding node to the ptr in double list
 */
#include <iostream>
#include <string>
#include "dlist.hpp"

const int NUM_CHAR=256;

void stream_no_dup_char(std::string str)
{
    char first_no_dup;
    int len = str.length();

    DNode* no_dup_list = NULL;
    DNode* tail = NULL;
    int char_map[NUM_CHAR] = {0};
    DNode* node_map[NUM_CHAR];

    // init the node map to NULL for each entry
    for (int i=0; i<NUM_CHAR; i++) {
        node_map[i] = NULL;
    }

    for (int i=0; i<len; i++) {
        // new node
        if (char_map[str[i]] == 0) {
            char_map[str[i]] = 1;
        
            // make new node
            DNode *p = new DNode;
            p->data = str[i];
            p->prev = NULL;
            p->next = NULL;

            node_map[str[i]] = p;

            // insert the node
            insertNode(no_dup_list, p, tail);
        } else {        // dup node
            DNode *p = node_map[str[i]];
            
            if (p) {
                removeNode(no_dup_list, p, tail);
            }

            node_map[str[i]]=NULL;
        }
        
        if (no_dup_list) {
            first_no_dup = no_dup_list->data;
            std::cout << first_no_dup;
        } else {
            first_no_dup = '\0';
            std::cout << ' ';
        }
        
    }
    
    std::cout << "\n";

    deleteDList(no_dup_list);
}

void TEST_stream_no_dup_char()
{
    std::cout << "TEST algorithm that maintains the first no-dup char in char stream.\n";

    std::cout << "Enter the input string.\n";
    std::string s;
    std::cin >> s;

    stream_no_dup_char(s);
}
