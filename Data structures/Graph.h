#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>

struct VE {

    size_t Vertex;
    int weight;
};

using Graph = std::vector<std::vector<VE>>;
using Edges = std::vector<VE>;

//I use simple realization - Adjacency List
//It is much more effective in time and memory than matrix

class DirectedGraph
{
public:
    DirectedGraph(size_t N) : graph(N, std::vector<VE>()) {};

    size_t size() {

        return graph.size();
    }

    void AddEdge(size_t from, size_t to, int weight=0) {

        graph.at(from).push_back({to, weight});
    }

    Edges GetAdj(size_t V) {

        return graph.at(V);
    }

    DirectedGraph Reverse() {

        DirectedGraph ans(graph.size());

        for (size_t i = 0; i < graph.size(); ++i) {

            for (auto x : graph.at(i)) {

                ans.graph.at(x.Vertex).push_back({i, x.weight});
            }
        }

        return ans;
    }

private:
    Graph graph;
};


class UndirectedGraph
{
public:
    UndirectedGraph(size_t N) : graph(N, std::vector<VE>()) {};

    size_t size() {

        return graph.size();
    }

    void AddEdge(size_t from, size_t to, int weight=0) {

        graph.at(from).push_back({to, weight});
        graph.at(to).push_back({from, weight});
    }

    Edges GetAdj(size_t V) {

        return graph.at(V);
    }

private:
    Graph graph;
};
#endif // GRAPH_H
