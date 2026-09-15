// Sum of Subsets (backtracking): find every subset whose sum equals the target.
// A branch is abandoned as soon as the sum is too big or can no longer reach
// the target even if all remaining items are taken.
// Compile: g++ sum_of_subsets.cpp -o sum_of_subsets
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_N = 10;

int n, target, solutions = 0;
int weight[MAX_N];
bool chosen[MAX_N];

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



// i = next item to decide, currentSum = sum of chosen items, remaining = sum of items i..n-1
void findSubsets(int i, int currentSum, int remaining) {
    if (currentSum == target) {                     // solution: print items 0..i-1 that are chosen
        cout << "{ ";
        for (int j = 0; j < i; j++)
            if (chosen[j]) cout << weight[j] << " ";
        cout << "}\n";
        solutions++;
        return;
    }
    if (i == n || currentSum > target || currentSum + remaining < target) return;   // prune

    chosen[i] = true;                               // branch 1: take item i
    findSubsets(i + 1, currentSum + weight[i], remaining - weight[i]);
    chosen[i] = false;                              // branch 2: skip item i
    findSubsets(i + 1, currentSum, remaining - weight[i]);
}

int main() {
    n = readInt("Enter number of items (1-10): ", 1, MAX_N);
    cout << "Enter " << n << " positive weights: ";
    int total = 0;
    for (int i = 0; i < n; i++) { weight[i] = readInt("", 1, 100); total += weight[i]; }
    target = readInt("Enter target sum (1-1000): ", 1, 1000);

    cout << "\nSubsets with sum " << target << ":\n";
    findSubsets(0, 0, total);
    if (solutions == 0) cout << "No subset has this sum.\n";
    return 0;
}
