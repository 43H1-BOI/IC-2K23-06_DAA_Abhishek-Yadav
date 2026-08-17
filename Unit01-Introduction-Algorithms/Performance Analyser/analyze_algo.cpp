/*
Lab Activity :-> Develop an Algorithm Performance Analyzer comparing 
theoretical and experimental complexity.

- Analyze best, average, and worst-case complexity
- Measure execution time for different input sizes
- Store experimental results in a file and generate performance graphs
for different algorithms
*/

#include<bits/stdc++.h>
#include "../Searching/BinarySearch.h"
#include<chrono> // For HD Time Rec.

using namespace chrono; // For HD Time Rec.
using namespace std;

// 
template <typename Function>
double measureTime(Function f){
    auto start = chrono::high_resolution_clock::now();
    f();
    auto end = chrono::high_resolution_clock::now();

    duration<double,milli> time = end - start;

    return time.count();
}