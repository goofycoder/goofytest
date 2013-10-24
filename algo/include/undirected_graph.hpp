// Undirected Graph
class UGraph 
{
public:
    UGraph(std::string edge_file);  // read edge information from file

    void addEdge(int v1, int v2);
    void addVertex(int v);

    void printVertex() const;
    void printEdge() const;

private:
    std::vector<int> V;             // Vertex
    std::vector<intpair> E;         // Edge
};
