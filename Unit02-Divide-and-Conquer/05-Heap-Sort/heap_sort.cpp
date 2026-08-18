// Heap Sort: build a max-heap, then repeatedly move the root (largest) to the
// end of the array and restore the heap on the remaining elements.
// Compile: g++ heap_sort.cpp -o heap_sort
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

// Sinks arr[i] down until the subtree rooted at i is a max-heap (heap size n).
void heapify(int arr[], int n, int i) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])   largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swapValues(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);   // build max-heap
    for (int end = n - 1; end > 0; end--) {
        swapValues(arr[0], arr[end]);                           // largest to the end
        heapify(arr, end, 0);                                   // fix the smaller heap
    }
}

int main() {
    int arr[MAX_N];
    int n = readInt("Enter number of elements (1-100): ", 1, MAX_N);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) arr[i] = readInt("", -100000, 100000);

    heapSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
    return 0;
}
