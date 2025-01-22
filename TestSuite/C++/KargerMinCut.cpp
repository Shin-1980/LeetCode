#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

unordered_map<int, vector<int> > parseGraph(const string &filename) {
    unordered_map<int, vector<int> > graph;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        int node;
        ss >> node;
        int neighbor;
        while (ss >> neighbor) {
            graph[node].push_back(neighbor);
        }
    }

    return graph;
}

void contract(unordered_map<int, vector<int> > &graph, int u, int v) {
    graph[u].insert(graph[u].end(), graph[v].begin(), graph[v].end());

    for (int neighbor : graph[v]) {
        auto &adjList = graph[neighbor];
        replace(adjList.begin(), adjList.end(), v, u);
    }

    graph[u].erase(remove(graph[u].begin(), graph[u].end(), u), graph[u].end());

    graph.erase(v);
}

int kargerMinCut(unordered_map<int, vector<int> > graph) {
    while (graph.size() > 2) {
        auto it = graph.begin();
        advance(it, rand() % graph.size());
        int u = it->first;
        int v = graph[u][rand() % graph[u].size()];

        // Contract the edge
        contract(graph, u, v);
    }

    // Return the size of the cut
    return graph.begin()->second.size();
}

int findMinCut(const unordered_map<int, vector<int> > &graph, int iterations) {
    int minCut = INT_MAX;

    for (int i = 0; i < iterations; ++i) {
        unordered_map<int, vector<int> > graphCopy = graph;
        int cut = kargerMinCut(graphCopy);
        minCut = min(minCut, cut);
    }

    return minCut;
}

int main() {
    srand(time(0));

    string filename = "kargerMinCut.txt";
    unordered_map<int, vector<int> > graph = parseGraph(filename);

    int iterations = 100;
    int minCut = findMinCut(graph, iterations);

    cout << "The minimum cut is: " << minCut << endl;

    return 0;
}
