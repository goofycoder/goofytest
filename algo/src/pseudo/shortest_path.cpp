#include <iostream>
#include <queue>
#include <stack>

// Graph node;
typedef struct gnode {
    struct gnode* neighbors[];
    int data;
} GNode;

// Dijkstra's algorithm
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


// Depth First Search
void dfs(node start) 
{
    std::stack<GNode*> s;
    s.push_back(start);
    
    while (s.empty() == false) {
        top = s.top();
        s.pop();
        
        //mark top as visited;
        markAsVisited(top);
        
        // check for termination condition
        check_term_cond();
        
        // add all of top's unvisited neighbors to the stack.
        vector<GNode*> neighbor;
        
        findNeighbor(start, neighbor);
   
        for (int i=0; i<v.size(); i++) {
            s.push(neighbor[i]);
        }
        
        // mark top as not visited;
        markAsNotVisited(top);
    }
}
