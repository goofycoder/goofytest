#include <iostream>
#include <queue>

// Graph node;
typedef struct gnode {
    struct gnode* neighbors[];
    int data;
} GNode;

void shortest_path(GNode* v)
{
    std::priority_queue<GNode*> s;

    s.insert(v);

    while (s.empty() == false) {
        GNode* top = s.top();
        s.pop();

        // mark top as visited
        markAsVisited(top);
        
        // check termination condition such as destination node is reached
        check_term_cond();

        vector<GNode*> neighbor;
        
        findNeighbor(v, neighbor);
   
        for (int i=0; i<v.size(); i++) {
            s.insert(neighbor[i]);
        }
    }
}
