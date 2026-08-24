// Fractional Knapsack (greedy): take items in decreasing value/weight order;
// the last item may be taken partially.
// Compile: g++ fractional_knapsack.cpp -o fractional_knapsack
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int MAX_N = 20;

struct Item {
    int id;
    int weight;
    int value;
    double ratio;   // value per unit weight
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


// Sorts items by ratio in decreasing order (simple selection sort).
void sortByRatio(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int best = i;
        for (int j = i + 1; j < n; j++)
            if (items[j].ratio > items[best].ratio) best = j;
        Item t = items[i]; items[i] = items[best]; items[best] = t;
    }
}

int main() {
    Item items[MAX_N];
    int n = readInt("Enter number of items (1-20): ", 1, MAX_N);
    int capacity = readInt("Enter knapsack capacity (1-1000): ", 1, 1000);
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " - weight and value: ";
        items[i].id = i + 1;
        items[i].weight = readInt("", 1, 1000);
        items[i].value = readInt("", 1, 1000);
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    sortByRatio(items, n);
    double remaining = capacity, totalValue = 0;
    cout << left << "\nItem  Weight  Value  Ratio  Taken\n";
    for (int i = 0; i < n && remaining > 0; i++) {
        double fraction = (items[i].weight <= remaining) ? 1.0 : remaining / items[i].weight;
        remaining -= fraction * items[i].weight;
        totalValue += fraction * items[i].value;
        cout << setw(6) << items[i].id << setw(8) << items[i].weight << setw(7) << items[i].value
             << setw(7) << items[i].ratio << fraction * 100 << "%\n";
    }
    cout << "Maximum value = " << totalValue << "\n";
    return 0;
}
