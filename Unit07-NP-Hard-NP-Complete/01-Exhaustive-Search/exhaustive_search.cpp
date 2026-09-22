// Exhaustive search (brute force) for the Travelling Salesman Problem:
// try every possible tour starting at city 0 and keep the cheapest.
// There are (n-1)! tours, so this only works for very small n.
// Compile: g++ exhaustive_search.cpp -o exhaustive_search
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_N = 9;
const int INF = 1000000000;

int n, cost[MAX_N][MAX_N];
int path[MAX_N], bestPath[MAX_N];
bool visited[MAX_N];
int bestCost = INF;
long long toursChecked = 0;

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



// Builds tours city by city; at depth n a complete tour is evaluated.
void tryAllTours(int depth, int costSoFar) {
    if (depth == n) {
        int total = costSoFar + cost[path[n - 1]][0];   // return to city 0
        toursChecked++;
        if (total < bestCost) {
            bestCost = total;
            for (int i = 0; i < n; i++) bestPath[i] = path[i];
        }
        return;
    }
    for (int city = 1; city < n; city++)
        if (!visited[city]) {
            visited[city] = true;
            path[depth] = city;
            tryAllTours(depth + 1, costSoFar + cost[path[depth - 1]][city]);
            visited[city] = false;
        }
}

int main() {
    n = readInt("Enter number of cities (2-9): ", 2, MAX_N);
    cout << "Enter the cost matrix (1-1000), diagonal is skipped:\n";
    for (int i = 0; i < n; i++) {
        cout << "From city " << i << " to the others: ";
        for (int j = 0; j < n; j++)
            cost[i][j] = (i == j) ? 0 : readInt("", 1, 1000);
    }

    path[0] = 0;
    visited[0] = true;
    tryAllTours(1, 0);

    cout << "\nTours checked    : " << toursChecked << "\n";
    cout << "Minimum tour cost: " << bestCost << "\nTour: ";
    for (int i = 0; i < n; i++) cout << bestPath[i] << " -> ";
    cout << "0\n";
    return 0;
}
