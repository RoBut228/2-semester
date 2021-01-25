#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "UndirectedGraph.h"
#include "directedgraph.h"
#include <algorithm>
#include <queue>

//n - amount of Verticies
//m - amount of edges

struct GraphSolution {

    size_t weight;
    std::vector<size_t> path;
};

//This algorithm need to find smallest edge every iteration
//SO it "sort" every iteration, so its time is approximately o(n^2+m)
GraphSolution SlowDijkstra(DirectedGraph graph, size_t from, size_t to) {

    std::vector<size_t> d(graph.size(), -1);
    std::vector<size_t> p(graph.size(), -1);
    std::vector<int> visited(graph.size(), 0);
    d[from] = 0;
    p[from] = 0;

    size_t curr = from;
    while (curr != -1) {

        visited[curr] = 1;

        for (auto x : graph.GetAdj(curr)) {

            size_t mn = -1;
            if (x.second + d[curr] < d[x.first]) {

                d[x.first] = x.second + d[curr];
                p[x.first] = curr;
            }
        }

        size_t mn = -1;
        size_t temp = -1;

        for (int i = 0; i < visited.size(); ++i) {//here we are searching for smallest edge

            if (d[i] < mn && !visited[i]) { //in the worst example we will do it n*n times in algorithm

                mn = d[i];
                temp = i;
            }
        }

        curr = temp;
    }

    std::vector<size_t> answer;
    curr = to;

    while (curr != from) {

        answer.push_back(curr + 1);
        curr = p[curr];
    }
    answer.push_back(from + 1);

    std::reverse(answer.begin(), answer.end());

    GraphSolution temp;
    temp.weight = d[to];
    temp.path = answer;

    return temp;
}


GraphSolution SlowDijkstra(UndirectedGraph graph, size_t from, size_t to) {

    std::vector<size_t> d(graph.size(), -1);
    std::vector<size_t> p(graph.size(), -1);
    std::vector<int> visited(graph.size(), 0);
    d[from] = 0;
    p[from] = 0;

    size_t curr = from;
    while (curr != -1) {

        visited[curr] = 1;

        for (auto x : graph.GetAdj(curr)) {

            size_t mn = -1;
            if (x.second + d[curr] < d[x.first]) {

                d[x.first] = x.second + d[curr];
                p[x.first] = curr;
            }
        }

        size_t mn = -1;
        size_t temp = -1;

        for (int i = 0; i < visited.size(); ++i) {//here we are searching for smallest edge

            if (d[i] < mn && !visited[i]) { //in the worst example we will do it n*n times in algorithm

                mn = d[i];
                temp = i;
            }
        }

        curr = temp;
    }

    std::vector<size_t> answer;
    curr = to;

    while (curr != from) {

        answer.push_back(curr + 1);
        curr = p[curr];
    }
    answer.push_back(from + 1);

    std::reverse(answer.begin(), answer.end());

    GraphSolution temp;
    temp.weight = d[to];
    temp.path = answer;

    return temp;
}


//this realization uses priority_queue which automatically sort by weight every Vertex
//it is done for logn, because it is heap
//so final time is o(n*logn + m*logn) which is approximately o(m*logn)
GraphSolution FastDijkstra(DirectedGraph graph, size_t from, size_t to) {

    std::vector<size_t> d(graph.size(), -1);
    std::vector<size_t> p(graph.size(), -1);
    std::vector<int> visited(graph.size(), 0);
    d[from] = 0;
    p[from] = 0;

    std::priority_queue<std::pair<size_t, size_t>, std::vector<std::pair<size_t, size_t>>, std::greater<std::pair<size_t, size_t>>> q;
    q.push({d[from], from});

    while (q.size()) {

        auto curr = q.top();
        q.pop();
        visited[curr.second] = 1;

        for (auto x : graph.GetAdj(curr.second)) {

            if (x.second + curr.first < d[x.first] && !visited[x.first]) {

                //we just put in queue if did not visited
                q.push({x.second + curr.first, x.first});
                d[x.first] = x.second + curr.first;
                p[x.first] = curr.second;
            }
        }
    }

    std::vector<size_t> answer;
    auto curr = to;

    while (curr != from) {

        answer.push_back(curr + 1);
        curr = p[curr];
    }
    answer.push_back(from + 1);

    std::reverse(answer.begin(), answer.end());

    GraphSolution temp;
    temp.weight = d[to];
    temp.path = answer;

    return temp;
}


GraphSolution FastDijkstra(UndirectedGraph graph, size_t from, size_t to) {

    std::vector<size_t> d(graph.size(), -1);
    std::vector<size_t> p(graph.size(), -1);
    std::vector<int> visited(graph.size(), 0);
    d[from] = 0;
    p[from] = 0;

    std::priority_queue<std::pair<size_t, size_t>, std::vector<std::pair<size_t, size_t>>, std::greater<std::pair<size_t, size_t>>> q;
    q.push({d[from], from});

    while (q.size()) {

        auto curr = q.top();
        q.pop();
        visited[curr.second] = 1;

        for (auto x : graph.GetAdj(curr.second)) {

            if (x.second + curr.first < d[x.first] && !visited[x.first]) {

                //we just put in queue if did not visited
                q.push({x.second + curr.first, x.first});
                d[x.first] = x.second + curr.first;
                p[x.first] = curr.second;
            }
        }
    }

    std::vector<size_t> answer;
    auto curr = to;

    while (curr != from) {

        answer.push_back(curr + 1);
        curr = p[curr];
    }
    answer.push_back(from + 1);

    std::reverse(answer.begin(), answer.end());

    GraphSolution temp;
    temp.weight = d[to];
    temp.path = answer;

    return temp;
}
#endif // ALGORITHMS_H
