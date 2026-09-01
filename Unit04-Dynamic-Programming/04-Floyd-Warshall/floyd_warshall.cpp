// Floyd-Warshall (dynamic programming): all-pairs shortest paths. After step k,
// dist[i][j] is the shortest path using only vertices 0..k as intermediates.
// Compile: g++ floyd_warshall.cpp -o floyd_warshall
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_V = 8;
const int INF = 1000000000;

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
    int dist[MAX_V][MAX_V];
    int V = readInt("Enter number of vertices (1-8): ", 1, MAX_V);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) dist[i][j] = (i == j) ? 0 : INF;

    int E = readInt("Enter number of directed edges: ", 0, V * (V - 1));
    if (E > 0) cout << "Enter each edge as: from to weight (weight -100 to 100)\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        do {
            cout << "Edge " << i + 1 << ": ";
            u = readInt("", 0, V - 1);
            v = readInt("", 0, V - 1);
            w = readInt("", -100, 100);
            if (u == v) cout << "Self-loops are not allowed.\n";
        } while (u == v);
        dist[u][v] = w;
    }

    for (int k = 0; k < V; k++)                     // allow vertex k as intermediate
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] < INF && dist[k][j] < INF && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    for (int i = 0; i < V; i++)
        if (dist[i][i] < 0) { cout << "\nNegative cycle detected - shortest paths are undefined.\n"; return 0; }

    cout << "\nShortest distance matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) cout << "INF\t";
            else                   cout << dist[i][j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}
