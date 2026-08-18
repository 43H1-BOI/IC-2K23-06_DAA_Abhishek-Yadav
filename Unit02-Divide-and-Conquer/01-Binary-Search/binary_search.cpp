// Binary Search (divide and conquer): compare with the middle element and
// discard the half that cannot contain the key. The array must be sorted.
// Compile: g++ binary_search.cpp -o binary_search
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

// Searches key in the sorted range arr[lo..hi]; returns its index or -1.
int binarySearch(const int arr[], int lo, int hi, int key) {
    if (lo > hi) return -1;                         // empty range: not found
    int mid = lo + (hi - lo) / 2;                   // avoids overflow of (lo+hi)
    cout << "  checking index " << mid << " (value " << arr[mid] << ")\n";
    if (arr[mid] == key) return mid;
    if (key < arr[mid])  return binarySearch(arr, lo, mid - 1, key);
    return binarySearch(arr, mid + 1, hi, key);
}

int main() {
    int arr[MAX_N];
    int n = readInt("Enter number of elements (1-100): ", 1, MAX_N);
    cout << "Enter " << n << " elements in ascending order: ";
    int prev = -100000;
    for (int i = 0; i < n; i++) {                   // each value must be >= previous
        arr[i] = readInt("", prev, 100000);
        prev = arr[i];
    }
    int key = readInt("Enter key to search: ", -100000, 100000);

    int pos = binarySearch(arr, 0, n - 1, key);
    if (pos == -1) cout << "Key " << key << " not found.\n";
    else           cout << "Key " << key << " found at index " << pos << ".\n";
    return 0;
}
