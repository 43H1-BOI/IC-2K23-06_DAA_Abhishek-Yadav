// Travelling Salesman Problem (Held-Karp dynamic programming).
// dp[mask][last] = cheapest way to start at city 0, visit exactly the cities in
// 'mask' and end at 'last'. Time O(n^2 * 2^n) instead of O(n!).
// Compile: g++ tsp_dp.cpp -o tsp_dp
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_N = 10;
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
    int cost[MAX_N][MAX_N] = {{0}};
    int n = readInt("Enter number of cities (2-10): ", 2, MAX_N);
    cout << "Enter the cost matrix (1-1000), diagonal is skipped:\n";
    for (int i = 0; i < n; i++) {
        cout << "From city " << i << " to the others: ";
        for (int j = 0; j < n; j++)
            if (i != j) cost[i][j] = readInt("", 1, 1000);
    }

    int full = (1 << n) - 1;
    static int dp[1 << MAX_N][MAX_N], from[1 << MAX_N][MAX_N];
    for (int mask = 0; mask <= full; mask++)
        for (int i = 0; i < n; i++) dp[mask][i] = INF;
    dp[1][0] = 0;                                   // only city 0 visited, standing at 0

    for (int mask = 1; mask <= full; mask++)
        for (int last = 0; last < n; last++) {
            if (!(mask & (1 << last)) || dp[mask][last] == INF) continue;
            for (int next = 0; next < n; next++) {
                if (mask & (1 << next)) continue;   // already visited
                int newMask = mask | (1 << next);
                if (dp[mask][last] + cost[last][next] < dp[newMask][next]) {
                    dp[newMask][next] = dp[mask][last] + cost[last][next];
                    from[newMask][next] = last;     // remember where we came from
                }
            }
        }

    int best = INF, last = -1;
    for (int i = 1; i < n; i++)                     // close the tour by returning to city 0
        if (dp[full][i] + cost[i][0] < best) { best = dp[full][i] + cost[i][0]; last = i; }

    int path[MAX_N], mask = full;
    for (int i = n - 1; i >= 1; i--) {              // rebuild the tour backwards
        path[i] = last;
        int prev = from[mask][last];
        mask ^= (1 << last);
        last = prev;
    }
    cout << "\nMinimum tour cost = " << best << "\nTour: 0";
    for (int i = 1; i < n; i++) cout << " -> " << path[i];
    cout << " -> 0\n";
    return 0;
}
