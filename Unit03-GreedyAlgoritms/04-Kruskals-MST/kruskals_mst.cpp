// Kruskal's algorithm (greedy): sort edges by weight and add each edge unless it
// forms a cycle. Cycles are detected with Union-Find (disjoint sets).
// Compile: g++ kruskals_mst.cpp -o kruskals_mst
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_V = 10;
const int MAX_E = 45;

struct Edge { int u, v, w; };

int parent[MAX_V];   // Union-Find: parent[x] is the parent of x in its set

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


// Returns the representative of x's set (with path compression).
int findSet(int x) {
    if (parent[x] != x) parent[x] = findSet(parent[x]);
    return parent[x];
}

int main() {
    Edge edges[MAX_E];
    int V = readInt("Enter number of vertices (2-10): ", 2, MAX_V);
    int E = readInt("Enter number of edges: ", 1, V * (V - 1) / 2);
    cout << "Enter each edge as: u v weight (vertices are 0 to " << V - 1 << ")\n";
    for (int i = 0; i < E; i++) {
        do {
            cout << "Edge " << i + 1 << ": ";
            edges[i].u = readInt("", 0, V - 1);
            edges[i].v = readInt("", 0, V - 1);
            edges[i].w = readInt("", 1, 1000);
            if (edges[i].u == edges[i].v) cout << "Self-loops are not allowed.\n";
        } while (edges[i].u == edges[i].v);
    }

    // insertion sort of edges by weight
    for (int i = 1; i < E; i++) {
        Edge key = edges[i];
        int j = i - 1;
        while (j >= 0 && edges[j].w > key.w) { edges[j + 1] = edges[j]; j--; }
        edges[j + 1] = key;
    }

    for (int i = 0; i < V; i++) parent[i] = i;      // every vertex is its own set
    int total = 0, used = 0;
    cout << "\nEdges in the Minimum Spanning Tree:\n";
    for (int i = 0; i < E && used < V - 1; i++) {
        int a = findSet(edges[i].u), b = findSet(edges[i].v);
        if (a != b) {                               // different sets: no cycle
            parent[a] = b;                          // union
            cout << edges[i].u << " - " << edges[i].v << "  (weight " << edges[i].w << ")\n";
            total += edges[i].w;
            used++;
        }
    }
    if (used < V - 1) cout << "Graph is not connected - this is a spanning forest.\n";
    cout << "Total weight = " << total << "\n";
    return 0;
}
