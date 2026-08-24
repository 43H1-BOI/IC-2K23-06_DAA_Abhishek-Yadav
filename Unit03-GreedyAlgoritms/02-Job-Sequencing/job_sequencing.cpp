// Job Sequencing with deadlines (greedy): consider jobs by decreasing profit and
// put each one in the latest free time slot on or before its deadline.
// Compile: g++ job_sequencing.cpp -o job_sequencing
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_N = 10;

struct Job {
    int id;
    int deadline;
    int profit;
};

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

int main() {
    Job jobs[MAX_N];
    int n = readInt("Enter number of jobs (1-10): ", 1, MAX_N);
    for (int i = 0; i < n; i++) {
        cout << "Job " << i + 1 << " - deadline and profit: ";
        jobs[i].id = i + 1;
        jobs[i].deadline = readInt("", 1, MAX_N);
        jobs[i].profit = readInt("", 1, 1000);
    }

    // sort by profit, highest first
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (jobs[j].profit < jobs[j + 1].profit) {
                Job t = jobs[j]; jobs[j] = jobs[j + 1]; jobs[j + 1] = t;
            }

    int slot[MAX_N + 1] = {0};                      // slot[t] = job id, 0 means free
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int t = jobs[i].deadline; t >= 1; t--) // latest free slot <= deadline
            if (slot[t] == 0) {
                slot[t] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
    }

    cout << "\nSchedule (time slot -> job): ";
    for (int t = 1; t <= MAX_N; t++)
        if (slot[t] != 0) cout << "[" << t << ": J" << slot[t] << "] ";
    cout << "\nTotal profit = " << totalProfit << "\n";
    return 0;
}
