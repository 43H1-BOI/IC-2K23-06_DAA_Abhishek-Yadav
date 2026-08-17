#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;
using namespace std::chrono;

ofstream csv_file("benchmark.csv");

// ONE generic benchmark function for ANY algorithm
template <typename Func, typename TheoFunc>
void benchmark(string name, Func algo, TheoFunc theo_fn, vector<int> sizes) {
    double c = 0.0;

    for (size_t i = 0; i < sizes.size(); i++) {
        int n = sizes[i];

        // Generate test data
        vector<int> arr(n);
        for (int &x : arr) x = rand() % 100000;

        // Time the algorithm
        auto start = high_resolution_clock::now();
        algo(arr);
        auto end = high_resolution_clock::now();

        double elapsed = duration<double, micro>(end - start).count();

        // Calculate theoretical fit on first run: Time = c * f(n)
        if (i == 0) c = elapsed / theo_fn(n);
        double theo_time = c * theo_fn(n);

        // Save row: Algorithm, Size, Experimental, Theoretical
        csv_file << name << "," << n << "," << elapsed << "," << theo_time << "\n";
    }
}

int main() {
    csv_file << "Algorithm,Size,Time_us,Theoretical_Time_us\n";

    // 1. Benchmark Linear Sum -> O(N)
    benchmark("Linear_Sum", [](vector<int>& a) {
        volatile long long s = 0;
        for (int x : a) s += x;
    }, [](double n) { return n; }, {100000, 200000, 400000, 800000});

    // 2. Benchmark std::sort -> O(N log N)
    benchmark("Std_Sort", [](vector<int>& a) {
        sort(a.begin(), a.end());
    }, [](double n) { return n * log2(n); }, {50000, 100000, 200000, 400000});

    // 3. Benchmark Selection Sort -> O(N^2)
    benchmark("Selection_Sort", [](vector<int>& a) {
        int n = a.size();
        for (int i = 0; i < n - 1; i++) {
            int m = i;
            for (int j = i + 1; j < n; j++)
                if (a[j] < a[m]) m = j;
            swap(a[i], a[m]);
        }
    }, [](double n) { return n * n; }, {1000, 2000, 4000, 8000});

    csv_file.close();
    cout << "Benchmark complete. Results written to benchmark.csv\n";
    return 0;
}