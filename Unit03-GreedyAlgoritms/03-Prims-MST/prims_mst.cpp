// Prim's algorithm (greedy): grow the tree from vertex 0, always adding the
// cheapest edge that connects the tree to a new vertex. Adjacency matrix, O(V^2).
// Compile: g++ prims_mst.cpp -o prims_mst
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_V = 10;
const int INF = 1000000;

int readInt(string prompt, int lo, int hi) {
    int x;

    cout << prompt;
    cin >> x;

    while (x < lo || x > hi) {
        cout << "Invalid! Enter again: ";
        cin >> x;
    }

    return x;
}


int main() {
    int graph[MAX_V][MAX_V] = {0};                  // 0 = no edge
    int V = readInt("Enter number of vertices (2-10): ", 2, MAX_V);
    int E = readInt("Enter number of edges: ", 1, V * (V - 1) / 2);
    cout << "Enter each edge as: u v weight (vertices are 0 to " << V - 1 << ")\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        do {
            cout << "Edge " << i + 1 << ": ";
            u = readInt("", 0, V - 1);
            v = readInt("", 0, V - 1);
            w = readInt("", 1, 1000);
            if (u == v) cout << "Self-loops are not allowed.\n";
        } while (u == v);
        graph[u][v] = graph[v][u] = w;              // undirected
    }

    int key[MAX_V], parent[MAX_V];
    bool inTree[MAX_V];
    for (int i = 0; i < V; i++) { key[i] = INF; parent[i] = -1; inTree[i] = false; }
    key[0] = 0;

    int total = 0;
    for (int count = 0; count < V; count++) {
        int u = -1;                                 // cheapest vertex not yet in tree
        for (int v = 0; v < V; v++)
            if (!inTree[v] && (u == -1 || key[v] < key[u])) u = v;
        if (key[u] == INF) { cout << "Graph is not connected - no spanning tree.\n"; return 0; }
        inTree[u] = true;
        total += key[u];
        for (int v = 0; v < V; v++)                 // update keys of neighbours
            if (graph[u][v] && !inTree[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
    }

    cout << "\nEdges in the Minimum Spanning Tree:\n";
    for (int v = 1; v < V; v++)
        cout << parent[v] << " - " << v << "  (weight " << graph[parent[v]][v] << ")\n";
    cout << "Total weight = " << total << "\n";
    return 0;
}
