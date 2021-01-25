#ifndef CONNECTIVITY_H
#define CONNECTIVITY_H
#include "Graph.h"
#include "DFS-and-BFS.h"


//this realization is very simple
//if size of vector after dfs = amount of Verticies ->
//all the verticies were visited -> graph is connected
bool IsConnectedNaive (DirectedGraph graph, size_t from) {

    auto vec = DFS(graph, from);
    return vec.size() == graph.size();
}


bool IsConnectedNaive (UndirectedGraph graph, size_t from=0) {

    auto vec = DFS(graph, from);
    return vec.size() == graph.size();
}


//here I use realization based on reverse Graph and DFS-vectors
//main idea is reversing Graph -> saving DFS-vector ->
//-> doing DFS from biggest Vertex in reverse DFS and saving vectors
//And after that we get vector of components
std::vector<std::vector<size_t>> Kosaraju (DirectedGraph graph, size_t from=0) {

    DirectedGraph INV = graph.Reverse();
    std::vector<int> visited(graph.size(), 0);
    std::vector<size_t> order_inv;

    for (int i = 0; i < INV.size(); ++i) {

        K_DFS(INV, i, visited, order_inv);
    }

    std::vector<std::vector<size_t>> answer;
    std::fill(visited.begin(), visited.end(), 0);

    for (int i = graph.size() - 1; i >= 0; --i) {

        std::vector<size_t> temp;
        K_DFS(graph, order_inv[i], visited, temp);

        if (temp.size()) {

            answer.push_back(temp);
        }
    }

    return answer;
}


//mark 0-not visited, 1-currently in dfs, 2-finished dfs
//so, if in dfs we will find Vertex with status 1 -> it is cycle
bool IsCycle(DirectedGraph graph) {

    std::vector<int> visited(graph.size(), 0);
    std::stack<size_t> st;

    for (int i = 0; i < graph.size(); ++i) {

        if (!visited[i]) {

            st.push(i);

            while(st.size()) {

                size_t curr = st.top();
                st.pop();
                visited[curr] = 1;

                for (auto x : graph.GetAdj(curr)) {

                    if (visited[x.Vertex] == 0) {

                        st.push(x.Vertex);
                    }
                    else if (visited[x.Vertex] == 1) {

                        return true;
                    }
                }

                visited[curr] = 2;
            }
        }
    }

    return false;
}


//in case of Undirected Graph alogoritm is practically the same
//the only difference is that we need to check that we don't come to parent
bool IsCycle(UndirectedGraph graph) {

    std::vector<int> visited(graph.size(), 0);
    std::stack<size_t> st;

    for (int i = 0; i < graph.size(); ++i) {

        if (!visited[i]) {

            st.push(i);

            while(st.size()) {

                size_t curr = st.top();
                st.pop();
                visited[curr] = 1;

                for (auto x : graph.GetAdj(curr)) {

                    if (visited[x.Vertex] == 0) {

                        st.push(x.Vertex);
                    }
                    else if (visited[x.Vertex] == 1 and x.Vertex != curr) {

                        return true;
                    }
                }

                visited[curr] = 2;
            }
        }
    }

    return false;
}
#endif // CONNECTIVITY_H
