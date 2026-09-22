// 0/1 Knapsack by Branch and Bound: explore "take / skip" choices item by item.
// The upper bound of a branch is the fractional-knapsack value of the remaining
// items; a branch is dropped if that bound cannot beat the best value found.
// Compile: g++ knapsack_bb.cpp -o knapsack_bb
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_N = 15;

int n, capacity;
int id[MAX_N], weight[MAX_N], value[MAX_N];     // items sorted by value/weight
bool chosen[MAX_N], bestChosen[MAX_N];
int bestValue = 0;
long long nodes = 0;

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



// Optimistic estimate: fill the remaining space with items i..n-1, allowing a fraction.
double upperBound(int i, int usedWeight, int currentValue) {
    double bound = currentValue;
    int w = usedWeight;
    for (int j = i; j < n; j++) {
        if (w + weight[j] <= capacity) { w += weight[j]; bound += value[j]; }
        else { bound += (double)(capacity - w) * value[j] / weight[j]; break; }
    }
    return bound;
}

void explore(int i, int usedWeight, int currentValue) {
    nodes++;
    if (currentValue > bestValue) {                 // new best solution
        bestValue = currentValue;
        for (int j = 0; j < n; j++) bestChosen[j] = (j < i) && chosen[j];
    }
    if (i == n || upperBound(i, usedWeight, currentValue) <= bestValue) return;   // prune

    if (usedWeight + weight[i] <= capacity) {       // branch 1: take item i
        chosen[i] = true;
        explore(i + 1, usedWeight + weight[i], currentValue + value[i]);
    }
    chosen[i] = false;                              // branch 2: skip item i
    explore(i + 1, usedWeight, currentValue);
}

int main() {
    n = readInt("Enter number of items (1-15): ", 1, MAX_N);
    capacity = readInt("Enter knapsack capacity (1-500): ", 1, 500);
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " - weight and value: ";
        id[i] = i + 1;
        weight[i] = readInt("", 1, 500);
        value[i] = readInt("", 1, 500);
    }

    for (int i = 0; i < n - 1; i++)                 // sort by value/weight, best first
        for (int j = 0; j < n - 1 - i; j++)
            if ((long long)value[j] * weight[j + 1] < (long long)value[j + 1] * weight[j]) {
                int t;
                t = id[j];     id[j] = id[j + 1];         id[j + 1] = t;
                t = weight[j]; weight[j] = weight[j + 1]; weight[j + 1] = t;
                t = value[j];  value[j] = value[j + 1];   value[j + 1] = t;
            }

    explore(0, 0, 0);
    cout << "\nMaximum value = " << bestValue << "\nItems taken:";
    for (int i = 0; i < n; i++)
        if (bestChosen[i]) cout << " " << id[i];
    cout << "\nNodes explored: " << nodes << " (full tree has " << (1LL << (n + 1)) - 1 << ")\n";
    return 0;
}
