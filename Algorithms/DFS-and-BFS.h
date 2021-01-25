#ifndef DFSANDBFS_H
#define DFSANDBFS_H
#include "Graph.h"
#include <stack>
#include <queue>
#include <algorithm>


std::vector<size_t> DFS(UndirectedGraph graph, size_t from) {

    std::vector<int> visited(graph.size(), 0);
    std::stack<size_t> st;
    st.push(from);
    std::vector<size_t> answer;

    while (st.size()) {

        auto curr = st.top();
        st.pop();
        visited[curr] = 1;
        answer.push_back(curr);

        for (auto x : graph.GetAdj(curr)) {

            if (!visited[x.Vertex]) {

                st.push(x.Vertex);
            }
        }
    }

    return answer;
}


std::vector<size_t> DFS(DirectedGraph graph, size_t from) {

    std::vector<int> visited(graph.size(), 0);
    std::stack<size_t> st;
    st.push(from);
    std::vector<size_t> answer;

    while (st.size()) {

        auto curr = st.top();
        st.pop();
        visited[curr] = 1;
        answer.push_back(curr);

        for (auto x : graph.GetAdj(curr)) {

            if (!visited[x.Vertex]) {

                st.push(x.Vertex);
            }
        }
    }

    return answer;
}


void K_DFS(DirectedGraph graph, size_t V, std::vector<int>& visited, std::vector<size_t>& answer) {

    if (visited[V]) return;
    else {

        visited[V] = 1;
        for (auto x : graph.GetAdj(V)) {

            if (!visited[x.Vertex]) {

                K_DFS(graph, x.Vertex, visited, answer);
            }
        }
        answer.push_back(V);
    }
}


std::vector<size_t> BFS (DirectedGraph graph, size_t from) {

    std::vector<int> visited(graph.size(), 0);
    std::queue<size_t> q;
    q.push(from);
    std::vector<size_t> answer;

    while (q.size()) {

        auto curr = q.front();
        q.pop();
        visited[curr] = 1;
        answer.push_back(curr);

        for (auto x : graph.GetAdj(curr)) {

            if (!visited[x.Vertex]) {

                q.push(x.Vertex);
            }
        }
    }

    return answer;
}


std::vector<size_t> BFS (UndirectedGraph graph, size_t from) {

    std::vector<int> visited(graph.size(), 0);
    std::queue<size_t> q;
    q.push(from);
    std::vector<size_t> answer;

    while (q.size()) {

        auto curr = q.front();
        q.pop();
        visited[curr] = 1;
        answer.push_back(curr);

        for (auto x : graph.GetAdj(curr)) {

            if (!visited[x.Vertex]) {

                q.push(x.Vertex);
            }
        }
    }

    return answer;
}


#endif // DFSANDBFS_H
