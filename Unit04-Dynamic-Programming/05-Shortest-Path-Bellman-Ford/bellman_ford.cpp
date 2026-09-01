// Single-source shortest path with Bellman-Ford (dynamic programming): relax every
// edge V-1 times. Works with negative weights and detects negative cycles.
// Compile: g++ bellman_ford.cpp -o bellman_ford
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_V = 10;
const int MAX_E = 30;
const int INF = 1000000000;

struct Edge { int u, v, w; };

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


// Prints the path from the source to v using the parent[] links.
void printPath(const int parent[], int v) {
    if (parent[v] != -1) { printPath(parent, parent[v]); cout << " -> "; }
    cout << v;
}

int main() {
    Edge edges[MAX_E];
    int dist[MAX_V], parent[MAX_V];
    int V = readInt("Enter number of vertices (1-10): ", 1, MAX_V);
    int E = readInt("Enter number of directed edges (0-30): ", 0, MAX_E);
    if (E > 0) cout << "Enter each edge as: from to weight (weight -100 to 100)\n";
    for (int i = 0; i < E; i++) {
        cout << "Edge " << i + 1 << ": ";
        edges[i].u = readInt("", 0, V - 1);
        edges[i].v = readInt("", 0, V - 1);
        edges[i].w = readInt("", -100, 100);
    }
    int source = readInt("Enter source vertex: ", 0, V - 1);

    for (int i = 0; i < V; i++) { dist[i] = INF; parent[i] = -1; }
    dist[source] = 0;

    for (int pass = 1; pass < V; pass++)            // V-1 rounds of relaxation
        for (int i = 0; i < E; i++)
            if (dist[edges[i].u] < INF && dist[edges[i].u] + edges[i].w < dist[edges[i].v]) {
                dist[edges[i].v] = dist[edges[i].u] + edges[i].w;
                parent[edges[i].v] = edges[i].u;
            }

    for (int i = 0; i < E; i++)                     // one more round: any change = negative cycle
        if (dist[edges[i].u] < INF && dist[edges[i].u] + edges[i].w < dist[edges[i].v]) {
            cout << "\nNegative cycle reachable from the source - no shortest paths.\n";
            return 0;
        }

    cout << "\nShortest distances from vertex " << source << ":\n";
    for (int v = 0; v < V; v++) {
        cout << "  to " << v << " : ";
        if (dist[v] == INF) { cout << "unreachable\n"; continue; }
        cout << dist[v] << "   path: ";
        printPath(parent, v);
        cout << "\n";
    }
    return 0;
}
