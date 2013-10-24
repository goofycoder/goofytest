#include <iostream>
#include <vector>
#include <fstream>
#include "algo.hpp"
#include "undirected_graph.hpp"

UGraph::UGraph(std::string edge_file)
{
    readEdgeFromFile(edge_file, E, V);
}

void UGraph::addVertex(int v)
{
    V.push_back(v);
}

void UGraph::printVertex() const
{
    std::cout << "Vertex in graph: \n";
    for(int i=0; i<V.size(); i++) {
        std::cout << V[i] << " ";
    }

    std::cout << "\n";
}

void UGraph::printEdge() const
{
    std::cout << "Edge in graph: \n";
    for(int i=0; i<E.size(); i++) {
        std::cout << "(" << E[i].first << "," << E[i].second << ")\n";
    }
}

void readEdgeFromFile(const std::string filename, 
                      std::vector<intpair>& E, 
                      std::vector<int>& V)
{
    std::ifstream f_in(filename);
    if (!f_in) {
        std::cout << "Cannot open input file.\n";
        return;
    }

    int num_edge;
    int m,n;
    f_in >> num_edge;

    for(int i=0; i<num_edge; i++) {
        f_in >> m;
        f_in >> n;

        E.push_back(std::make_pair(m,n));

        if (!isMember(V, m)) {
            V.push_back(m);
        }

        if (!isMember(V, n)) {
            V.push_back(n);
        }
    }

    f_in.close();
}

void TEST_undirected_graph()
{
    std::cout << "TEST: undirected graph APIs.\n";

    std::cout << "Enter the name of graph edge file. (hint: ug_edge.txt)\n";
    std::string edge_file;
    std::cin >> edge_file;
          
    UGraph ug(edge_file);
    
    ug.printEdge();
    ug.printVertex();
}
