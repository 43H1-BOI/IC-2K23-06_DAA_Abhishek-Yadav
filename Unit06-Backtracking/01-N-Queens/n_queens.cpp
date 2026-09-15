// N-Queens (backtracking): place one queen per row; if a column is attacked,
// skip it; if no column works, go back and move the previous queen.
// Compile: g++ n_queens.cpp -o n_queens
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_N = 10;

int n;
int col[MAX_N];                 // col[r] = column of the queen in row r
int solutions = 0;
int firstSolution[MAX_N];

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



// Can a queen go to (row, c) without being attacked by the queens above?
bool isSafe(int row, int c) {
    for (int r = 0; r < row; r++)
        if (col[r] == c || abs(col[r] - c) == row - r) return false;   // same column / diagonal
    return true;
}

void placeQueens(int row) {
    if (row == n) {                                 // all queens placed
        if (solutions == 0)
            for (int r = 0; r < n; r++) firstSolution[r] = col[r];
        solutions++;
        return;
    }
    for (int c = 0; c < n; c++)
        if (isSafe(row, c)) {
            col[row] = c;
            placeQueens(row + 1);                   // returning here = backtrack
        }
}

int main() {
    n = readInt("Enter board size N (1-10): ", 1, MAX_N);
    placeQueens(0);

    cout << "Total solutions for " << n << " queens: " << solutions << "\n";
    if (solutions > 0) {
        cout << "First solution:\n";
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) cout << (firstSolution[r] == c ? "Q " : ". ");
            cout << "\n";
        }
    }
    return 0;
}
