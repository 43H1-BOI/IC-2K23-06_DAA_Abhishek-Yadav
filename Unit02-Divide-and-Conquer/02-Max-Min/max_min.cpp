// Max-Min by divide and conquer: split the array, find max/min of each half,
// then combine with 2 comparisons. Uses about 3n/2 - 2 comparisons.
// Compile: g++ max_min.cpp -o max_min
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_N = 100;
int comparisons = 0;   // counts element comparisons

int readInt(const char* prompt, int lo, int hi) {
    int x;
    cout << prompt;
    while (!(cin >> x) || x < lo || x > hi) {
        if (cin.eof()) exit(1);
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid! Enter a value between " << lo << " and " << hi << ": ";
    }
    return x;
}

// Finds the maximum and minimum of arr[lo..hi] and stores them in mx and mn.
void maxMin(const int arr[], int lo, int hi, int& mx, int& mn) {
    if (lo == hi) {                                 // one element
        mx = mn = arr[lo];
    } else if (hi == lo + 1) {                      // two elements: 1 comparison
        comparisons++;
        if (arr[lo] > arr[hi]) { mx = arr[lo]; mn = arr[hi]; }
        else                   { mx = arr[hi]; mn = arr[lo]; }
    } else {                                        // divide, solve, combine
        int mid = (lo + hi) / 2, mx1, mn1, mx2, mn2;
        maxMin(arr, lo, mid, mx1, mn1);
        maxMin(arr, mid + 1, hi, mx2, mn2);
        comparisons += 2;
        mx = (mx1 > mx2) ? mx1 : mx2;
        mn = (mn1 < mn2) ? mn1 : mn2;
    }
}

int main() {
    int arr[MAX_N];
    int n = readInt("Enter number of elements (1-100): ", 1, MAX_N);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) arr[i] = readInt("", -100000, 100000);

    int mx, mn;
    maxMin(arr, 0, n - 1, mx, mn);
    cout << "Maximum = " << mx << ", Minimum = " << mn << "\n";
    cout << "Comparisons used: " << comparisons
         << " (simple scan would use " << 2 * (n - 1) << ")\n";
    return 0;
}
