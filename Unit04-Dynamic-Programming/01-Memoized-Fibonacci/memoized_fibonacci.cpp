// Memoized Fibonacci (dynamic programming): store each fib(i) the first time it
// is computed so it is never recomputed. Compared with plain recursion.
// Compile: g++ memoized_fibonacci.cpp -o memoized_fibonacci
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_N = 90;                // fib(90) is the largest that fits in long long
long long memo[MAX_N + 1];
long long naiveCalls = 0, memoCalls = 0;

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


long long fibNaive(int n) {
    naiveCalls++;
    if (n < 2) return n;
    return fibNaive(n - 1) + fibNaive(n - 2);
}

long long fibMemo(int n) {
    memoCalls++;
    if (n < 2) return n;
    if (memo[n] != -1) return memo[n];              // already solved
    return memo[n] = fibMemo(n - 1) + fibMemo(n - 2);
}

int main() {
    int n = readInt("Enter n (0-90): ", 0, MAX_N);
    for (int i = 0; i <= MAX_N; i++) memo[i] = -1;  // -1 = not computed yet

    cout << "Memoized  : fib(" << n << ") = " << fibMemo(n) << ", calls = " << memoCalls << "\n";
    if (n <= 35)
        cout << "Plain     : fib(" << n << ") = " << fibNaive(n) << ", calls = " << naiveCalls << "\n";
    else
        cout << "Plain recursion skipped (n > 35 would take too long).\n";
    return 0;
}
