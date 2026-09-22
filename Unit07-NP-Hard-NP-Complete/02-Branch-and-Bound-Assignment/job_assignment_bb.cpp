// Branch and Bound - Job Assignment: give each worker exactly one job so that
// the total cost is minimum. A partial assignment is dropped when its cost plus
// an optimistic estimate of the rest cannot beat the best complete answer.
// Compile: g++ job_assignment_bb.cpp -o job_assignment_bb
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_N = 8;
const int INF = 1000000000;

int n, cost[MAX_N][MAX_N];
bool taken[MAX_N];                 // taken[j] = job j already given to a worker
int current[MAX_N], best[MAX_N];
int bestCost = INF;
long long nodes = 0;               // partial assignments explored

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



// Lower bound: every remaining worker gets his cheapest still-free job.
int lowerBound(int fromWorker) {
    int bound = 0;
    for (int w = fromWorker; w < n; w++) {
        int cheapest = INF;
        for (int j = 0; j < n; j++)
            if (!taken[j] && cost[w][j] < cheapest) cheapest = cost[w][j];
        bound += cheapest;
    }
    return bound;
}

void assign(int worker, int costSoFar) {
    nodes++;
    if (worker == n) {                              // complete assignment
        if (costSoFar < bestCost) {
            bestCost = costSoFar;
            for (int i = 0; i < n; i++) best[i] = current[i];
        }
        return;
    }
    for (int job = 0; job < n; job++) {
        if (taken[job]) continue;
        taken[job] = true;
        int newCost = costSoFar + cost[worker][job];
        if (newCost + lowerBound(worker + 1) < bestCost) {   // otherwise prune
            current[worker] = job;
            assign(worker + 1, newCost);
        }
        taken[job] = false;
    }
}

int main() {
    n = readInt("Enter number of workers = jobs (1-8): ", 1, MAX_N);
    cout << "Enter cost[worker][job] (1-99), one row per worker:\n";
    for (int i = 0; i < n; i++) {
        cout << "Worker " << i << ": ";
        for (int j = 0; j < n; j++) cost[i][j] = readInt("", 1, 99);
    }

    assign(0, 0);
    cout << "\nMinimum total cost = " << bestCost << "\n";
    for (int i = 0; i < n; i++) cout << "Worker " << i << " -> Job " << best[i] << "\n";
    cout << "Nodes explored: " << nodes << "\n";
    return 0;
}
