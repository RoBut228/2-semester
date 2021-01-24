#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H
#include <vector>

using Graph = std::vector<std::vector<std::pair<size_t, int>>>;
using Edges = std::vector<std::pair<size_t, int>>;

//I use simple realization - Adjacency List
//It is much more effective in time and memory than matrix
class DirectedGraph
{
public:
    DirectedGraph(size_t N) : graph(N, std::vector<std::pair<size_t, int>>()) {};

    size_t size() {

        return graph.size();
    }

    void AddEdge(size_t from, size_t to, int weight=0) {

        graph.at(from).push_back({to, weight});
    }

    Edges GetAdj(size_t V) {

        return graph.at(V);
    }

private:
    Graph graph;
};

#endif // DIRECTEDGRAPH_H
