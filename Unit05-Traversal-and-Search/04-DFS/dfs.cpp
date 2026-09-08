// Depth First Search: go as deep as possible along one path, then backtrack.
// Records discovery/finish times and counts connected components.
// Compile: g++ dfs.cpp -o dfs
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_V = 10;

int graph[MAX_V][MAX_V];
int V, timer = 0;
int discovery[MAX_V], finish[MAX_V];   // 0 = not visited yet

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



void dfs(int u) {
    discovery[u] = ++timer;
    cout << u << " ";
    for (int v = 0; v < V; v++)
        if (graph[u][v] && discovery[v] == 0) dfs(v);
    finish[u] = ++timer;
}

int main() {
    V = readInt("Enter number of vertices (1-10): ", 1, MAX_V);
    int E = readInt("Enter number of edges: ", 0, V * (V - 1) / 2);
    if (E > 0) cout << "Enter each edge as: u v (vertices are 0 to " << V - 1 << ")\n";
    for (int i = 0; i < E; i++) {
        cout << "Edge " << i + 1 << ": ";
        int u = readInt("", 0, V - 1);
        int v = readInt("", 0, V - 1);
        graph[u][v] = graph[v][u] = 1;
    }
    int start = readInt("Enter start vertex: ", 0, V - 1);

    int components = 0;
    cout << "\nDFS order: ";
    dfs(start);
    components++;
    for (int v = 0; v < V; v++)                     // restart from unvisited vertices
        if (discovery[v] == 0) { cout << "| "; dfs(v); components++; }

    cout << "\n\nVertex  Discovery  Finish\n";
    for (int v = 0; v < V; v++)
        cout << v << "       " << discovery[v] << "          " << finish[v] << "\n";
    cout << "Connected components: " << components << "\n";
    return 0;
}
