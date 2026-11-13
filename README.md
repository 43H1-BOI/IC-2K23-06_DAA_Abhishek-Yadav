# Abhi_DAA - Design and Analysis of Algorithms Laboratory

Simple C++ implementations of the algorithms of the DAA lab, 7 units, 29 programs. Every program is small, self-contained (only the standard headers it needs, no extra files), validates its input, and was verified against brute-force or known answers.

| Unit folder | Topic | Programs |
|---|---|---|
| [Unit01-Introduction-Algorithms](Unit01-Introduction-Algorithms/README.md) | Introduction to Algorithms & Performance Analysis | Linear Search, Complexity Analysis, Performance Measurement |
| [Unit02-Divide-and-Conquer](Unit02-Divide-and-Conquer/README.md) | Divide and Conquer | Binary Search, Max-Min, Merge Sort, Quick Sort, Heap Sort, Performance Measurement |
| [Unit03-Greedy-Method](Unit03-Greedy-Method/README.md) | Greedy Method | Fractional Knapsack, Job Sequencing with Deadlines, Prim's Minimum Spanning Tree, Kruskal's Minimum Spanning Tree |
| [Unit04-Dynamic-Programming](Unit04-Dynamic-Programming/README.md) | Dynamic Programming | Memoized Fibonacci, 0/1 Knapsack, Multistage Graph, Floyd-Warshall, Single-Source Shortest Path, Travelling Salesman Problem |
| [Unit05-Traversal-and-Search](Unit05-Traversal-and-Search/README.md) | Traversal & Search Techniques | Binary Tree Traversals, Graph Representation, Breadth First Search, Depth First Search |
| [Unit06-Backtracking](Unit06-Backtracking/README.md) | Backtracking | N-Queens, Sum of Subsets |
| [Unit07-NP-Hard-NP-Complete](Unit07-NP-Hard-NP-Complete/README.md) | NP-Hard and NP-Complete Problems | Exhaustive Search, Branch and Bound, 0/1 Knapsack by Branch and Bound, TSP by Branch and Bound |

## Repository layout
```text
Abhi_DAA/
├── README.md              this file
├── CONCEPTS.md            C++ and algorithm concepts explained in simple words
├── Unit01-Introduction-Algorithms/
│          ├── README.md
│          ├── 01-Linear-Search/
│          ├── 02-Complexity-Analysis/   
│          ├── 03-Performance-Measurement/ 
├── Unit02-Divide-and-Conquer/
│          ├── README.md
│          ├── 01-Binary-Search/ 
│          ├── 02-Max-Min/ 
│          ├── 03-Merge-Sort/ 
│          ├── 04-Quick-Sort/ 
│          ├── 05-Heap-Sort/ 
├── Unit03-Greedy-Method/
│          ├── README.md
│          ├── 01-Fractional-Knapsack/ 
│          ├── 02-Job-Sequencing/ 
│          ├── 03-Prims-MST/ 
│          ├── 04-Kruskals-MST/ 
├── Unit04-Dynamic-Programming/
│          ├── README.md
│          ├── 01-Memoized-Fibonacci/ 
│          ├── 02-Knapsack-0-1/ 
│          ├── 03-Multistage-Graph/ 
│          ├── 04-Floyd-Warshall/ 
│          ├── 05-Shortest-Path-Bellman-Ford/ 
│          ├── 06-TSP/ 
├── Unit05-Traversal-and-Search/
│          ├── README.md
│          ├── 01-Binary-Tree-Traversals/ 
│          ├── 02-Graph-Representation/ 
│          ├── 03-BFS/ 
│          ├── 04-DFS/ 
├── Unit06-Backtracking/
│          ├── README.md
│          ├── 01-N-Queens/ 
│          ├── 02-Sum-of-Subsets/ 
├── Unit07-NP-Hard-NP-Complete/
│          ├── README.md
│          ├── 01-Exhaustive-Search/ 
│          ├── 02-Branch-and-Bound-Assignment/ 
│          ├── 03-Knapsack-Branch-and-Bound/ 
│          ├── 04-TSP-Branch-and-Bound/ 
└── docs/
    ├── algorithm-flowcharts/    Mermaid flowcharts, one file per unit
    ├── algorithm-pseudocode/    pseudocode, one file per unit
    ├── complexity-analysis/     theory table, measured CSV data and graphs
    ├── diagrams/                PlantUML diagrams (.puml)
    ├── screenshots/             PowerShell-style terminal screenshots of every program
    ├── performance-analysis.pdf
    └── final-report.pdf
```

## Compile and run
Any C++ compiler works (g++ shown). Open PowerShell in a program folder:
```powershell
g++ linear_search.cpp -o linear_search
.\linear_search.exe
```
Performance programs should be compiled with optimisation: `g++ -O2 sort_performance.cpp -o sort_performance`.

## What every program folder contains
- `<name>.cpp` - the program (algorithm kept simple; measurement code lives in separate performance programs)
- `<name>.txt` - short code explanation (same file name)
- `README.md` - problem statement, approach, pseudocode, flowchart, dry run, complexity, sample run, learning outcomes
