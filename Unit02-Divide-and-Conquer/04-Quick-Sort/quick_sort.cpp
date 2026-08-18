// Quick Sort: pick a pivot, put smaller elements on its left and larger on its
// right (partition), then sort both sides recursively. Pivot = last element.
// Compile: g++ quick_sort.cpp -o quick_sort
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_N = 100;

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

void swapValues(int& a, int& b) { int t = a; a = b; b = t; }

// Lomuto partition: places the pivot at its final position and returns it.
int partition(int arr[], int lo, int hi) {
    int pivot = arr[hi];
    int i = lo - 1;                                 // end of the "smaller" region
    for (int j = lo; j < hi; j++)
        if (arr[j] <= pivot) swapValues(arr[++i], arr[j]);
    swapValues(arr[i + 1], arr[hi]);
    return i + 1;
}

void quickSort(int arr[], int lo, int hi) {
    if (lo >= hi) return;
    int p = partition(arr, lo, hi);
    quickSort(arr, lo, p - 1);
    quickSort(arr, p + 1, hi);
}

int main() {
    int arr[MAX_N];
    int n = readInt("Enter number of elements (1-100): ", 1, MAX_N);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) arr[i] = readInt("", -100000, 100000);

    quickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
    return 0;
}
