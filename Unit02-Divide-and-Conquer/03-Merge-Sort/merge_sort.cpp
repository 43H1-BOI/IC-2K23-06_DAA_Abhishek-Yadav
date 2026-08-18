// Merge Sort: split in half, sort each half recursively, merge the sorted halves.
// Compile: g++ merge_sort.cpp -o merge_sort
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_N = 100;
int temp[MAX_N];   // helper array used while merging

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

// Merges the sorted halves arr[lo..mid] and arr[mid+1..hi].
void merge(int arr[], int lo, int mid, int hi) {
    int i = lo, j = mid + 1, k = lo;
    while (i <= mid && j <= hi)
        temp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];   // <= keeps it stable
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= hi)  temp[k++] = arr[j++];
    for (k = lo; k <= hi; k++) arr[k] = temp[k];                // copy back
}

void mergeSort(int arr[], int lo, int hi) {
    if (lo >= hi) return;                           // 0 or 1 element is sorted
    int mid = lo + (hi - lo) / 2;
    mergeSort(arr, lo, mid);
    mergeSort(arr, mid + 1, hi);
    merge(arr, lo, mid, hi);
}

int main() {
    int arr[MAX_N];
    int n = readInt("Enter number of elements (1-100): ", 1, MAX_N);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) arr[i] = readInt("", -100000, 100000);

    mergeSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
    return 0;
}
