// Multistage Graph (dynamic programming): shortest path from the source (stage 1)
// to the sink (last stage). cost[i] = min over edges (i,j) of weight + cost[j].
// Vertices are numbered stage by stage: stage 1 first, last stage last.
// Compile: g++ multistage_graph.cpp -o multistage_graph
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_V = 14;
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
    int c[MAX_V][MAX_V], stageOf[MAX_V];
    for (int i = 0; i < MAX_V; i++)
        for (int j = 0; j < MAX_V; j++) c[i][j] = INF;

    int k = readInt("Enter number of stages (2-6): ", 2, 6);
    int n = 0;                                      // total vertices
    for (int s = 0; s < k; s++) {
        cout << "Vertices in stage " << s + 1 << ": ";
        int count = (s == 0 || s == k - 1) ? readInt("", 1, 1) : readInt("", 1, 3);
        for (int i = 0; i < count; i++) stageOf[n++] = s;
    }

    int E = readInt("Enter number of edges (1-100): ", 1, 100);
    cout << "Enter each edge as: u v weight (vertices 0 to " << n - 1 << ", only to the next stage)\n";
    for (int e = 0; e < E; e++) {
        int u, v, w;
        bool ok;
        do {
            cout << "Edge " << e + 1 << ": ";
            u = readInt("", 0, n - 1);
            v = readInt("", 0, n - 1);
            w = readInt("", 1, 1000);
            ok = (stageOf[v] == stageOf[u] + 1);
            if (!ok) cout << "An edge must go from a stage to the very next stage.\n";
        } while (!ok);
        c[u][v] = w;
    }

    int cost[MAX_V], nextVertex[MAX_V];
    cost[n - 1] = 0;
    nextVertex[n - 1] = -1;                         // the sink has no next vertex
    for (int i = n - 2; i >= 0; i--) {              // work backwards from the sink
        cost[i] = INF;
        nextVertex[i] = -1;
        for (int j = i + 1; j < n; j++)
            if (c[i][j] < INF && c[i][j] + cost[j] < cost[i]) {
                cost[i] = c[i][j] + cost[j];
                nextVertex[i] = j;
            }
    }

    if (cost[0] >= INF) { cout << "\nNo path from source to sink.\n"; return 0; }
    cout << "\nMinimum cost = " << cost[0] << "\nPath: 0";
    for (int v = nextVertex[0]; v != -1; v = nextVertex[v]) cout << " -> " << v;
    cout << "\n";
    return 0;
}
