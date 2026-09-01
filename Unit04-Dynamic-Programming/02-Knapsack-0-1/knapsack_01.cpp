// 0/1 Knapsack (dynamic programming): dp[i][w] = best value using the first i
// items with capacity w. Each item is either taken whole or left.
// Compile: g++ knapsack_01.cpp -o knapsack_01
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_N = 10;
const int MAX_W = 50;

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
    int weight[MAX_N + 1], value[MAX_N + 1];
    int dp[MAX_N + 1][MAX_W + 1] = {{0}};
    int n = readInt("Enter number of items (1-10): ", 1, MAX_N);
    int W = readInt("Enter knapsack capacity (1-50): ", 1, MAX_W);
    for (int i = 1; i <= n; i++) {
        cout << "Item " << i << " - weight and value: ";
        weight[i] = readInt("", 1, MAX_W);
        value[i] = readInt("", 1, 100);
    }

    for (int i = 1; i <= n; i++)
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w];                                  // skip item i
            if (weight[i] <= w && dp[i - 1][w - weight[i]] + value[i] > dp[i][w])
                dp[i][w] = dp[i - 1][w - weight[i]] + value[i];       // take item i
        }

    cout << "\nDP table (rows = items 0.." << n << ", columns = capacity 0.." << W << ")\n";
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) cout << dp[i][w] << "\t";
        cout << "\n";
    }

    cout << "\nMaximum value = " << dp[n][W] << "\nItems taken:";
    int w = W;
    for (int i = n; i >= 1; i--)                    // trace back through the table
        if (dp[i][w] != dp[i - 1][w]) { cout << " " << i; w -= weight[i]; }
    cout << "\n";
    return 0;
}
