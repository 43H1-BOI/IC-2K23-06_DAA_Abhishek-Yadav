// Travelling Salesman Problem by Branch and Bound: build tours city by city and
// stop extending a tour when (cost so far + cheapest possible rest) >= best tour.
// Lower bound: every city that still needs an outgoing edge pays at least its
// cheapest outgoing edge.
// Compile: g++ tsp_bb.cpp -o tsp_bb
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_N = 10;
const int INF = 1000000000;

int n, cost[MAX_N][MAX_N], minOut[MAX_N];
int path[MAX_N], bestPath[MAX_N];
bool visited[MAX_N];
int bestCost = INF;
long long nodes = 0;               // partial tours explored

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


void explore(int depth, int last, int costSoFar) {
    nodes++;
    if (depth == n) {                               // complete tour: add the way back
        int total = costSoFar + cost[last][0];
        if (total < bestCost) {
            bestCost = total;
            for (int i = 0; i < n; i++) bestPath[i] = path[i];
        }
        return;
    }
    for (int next = 1; next < n; next++) {
        if (visited[next]) continue;
        int newCost = costSoFar + cost[last][next];
        visited[next] = true;
        int bound = newCost + minOut[next];         // 'next' still needs an outgoing edge
        for (int c = 1; c < n; c++)
            if (!visited[c]) bound += minOut[c];    // so does every unvisited city
        if (bound < bestCost) {                     // otherwise prune this branch
            path[depth] = next;
            explore(depth + 1, next, newCost);
        }
        visited[next] = false;
    }
}

int main() {
    n = readInt("Enter number of cities (2-10): ", 2, MAX_N);
    cout << "Enter the cost matrix (1-1000), diagonal is skipped:\n";
    for (int i = 0; i < n; i++) {
        cout << "From city " << i << " to the others: ";
        minOut[i] = INF;
        for (int j = 0; j < n; j++) {
            cost[i][j] = (i == j) ? 0 : readInt("", 1, 1000);
            if (i != j && cost[i][j] < minOut[i]) minOut[i] = cost[i][j];
        }
    }

    path[0] = 0;
    visited[0] = true;
    explore(1, 0, 0);

    long long full = 1;                             // nodes an exhaustive search would visit
    long long level = 1;
    for (int d = 1; d < n; d++) { level *= (n - d); full += level; }
    cout << "\nMinimum tour cost = " << bestCost << "\nTour: ";
    for (int i = 0; i < n; i++) cout << bestPath[i] << " -> ";
    cout << "0\nNodes explored: " << nodes << " (exhaustive search: " << full << ")\n";
    return 0;
}
