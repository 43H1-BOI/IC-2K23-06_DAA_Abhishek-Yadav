// Graph Representation: store an undirected graph as an adjacency matrix and as
// an adjacency list (linked list of neighbours for every vertex).
// Compile: g++ graph_representation.cpp -o graph_representation
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_V = 8;

struct ListNode {
    int vertex;
    ListNode* next;
};

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


// Appends 'to' at the end of the neighbour list of 'from'.
void addToList(ListNode* adj[], int from, int to) {
    ListNode* node = new ListNode;
    node->vertex = to;
    node->next = NULL;
    if (adj[from] == NULL) { adj[from] = node; return; }
    ListNode* cur = adj[from];
    while (cur->next) cur = cur->next;
    cur->next = node;
}

int main() {
    int matrix[MAX_V][MAX_V] = {{0}};
    ListNode* adj[MAX_V] = {NULL};
    int V = readInt("Enter number of vertices (1-8): ", 1, MAX_V);
    int E = readInt("Enter number of edges: ", 0, V * (V - 1) / 2);
    if (E > 0) cout << "Enter each edge as: u v (vertices are 0 to " << V - 1 << ")\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        bool bad;
        do {
            cout << "Edge " << i + 1 << ": ";
            u = readInt("", 0, V - 1);
            v = readInt("", 0, V - 1);
            bad = (u == v || matrix[u][v] == 1);
            if (bad) cout << "Self-loops and repeated edges are not allowed.\n";
        } while (bad);
        matrix[u][v] = matrix[v][u] = 1;
        addToList(adj, u, v);
        addToList(adj, v, u);
    }

    cout << "\nAdjacency matrix:\n   ";
    for (int j = 0; j < V; j++) cout << j << " ";
    cout << "\n";
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        for (int j = 0; j < V; j++) cout << matrix[i][j] << " ";
        cout << "\n";
    }

    cout << "\nAdjacency list:\n";
    for (int i = 0; i < V; i++) {
        cout << i << " ->";
        int degree = 0;
        for (ListNode* cur = adj[i]; cur; cur = cur->next) { cout << " " << cur->vertex; degree++; }
        cout << "   (degree " << degree << ")\n";
        for (ListNode* cur = adj[i]; cur;) { ListNode* next = cur->next; delete cur; cur = next; }
    }
    return 0;
}
