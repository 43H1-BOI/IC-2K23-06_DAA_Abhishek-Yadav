// Breadth First Search: visit the start vertex, then all its neighbours, then
// their neighbours... A queue gives the "level by level" order and the shortest
// number of edges from the start vertex.
// Compile: g++ bfs.cpp -o bfs
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_V = 10;

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
    int graph[MAX_V][MAX_V] = {{0}};
    int V = readInt("Enter number of vertices (1-10): ", 1, MAX_V);
    int E = readInt("Enter number of edges: ", 0, V * (V - 1) / 2);
    if (E > 0) cout << "Enter each edge as: u v (vertices are 0 to " << V - 1 << ")\n";
    for (int i = 0; i < E; i++) {
        cout << "Edge " << i + 1 << ": ";
        int u = readInt("", 0, V - 1);
        int v = readInt("", 0, V - 1);
        graph[u][v] = graph[v][u] = 1;
    }
    int start = readInt("Enter start vertex: ", 0, V - 1);

    int level[MAX_V], queue[MAX_V], head = 0, tail = 0;
    for (int i = 0; i < V; i++) level[i] = -1;      // -1 = not visited
    level[start] = 0;
    queue[tail++] = start;

    cout << "\nBFS order: ";
    while (head < tail) {
        int u = queue[head++];
        cout << u << " ";
        for (int v = 0; v < V; v++)
            if (graph[u][v] && level[v] == -1) {    // unvisited neighbour
                level[v] = level[u] + 1;
                queue[tail++] = v;
            }
    }
    cout << "\n\nVertex  Level (edges from " << start << ")\n";
    for (int v = 0; v < V; v++) {
        cout << v << "       ";
        if (level[v] == -1) cout << "not reachable\n";
        else                cout << level[v] << "\n";
    }
    return 0;
}
