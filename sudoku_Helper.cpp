#include <iostream>
#include <unordered_set>
#include <vector>


#define UNASSIGNED 0
#define N 9

using namespace std;

bool isValidSudoku(const vector<vector<int>>& board) {
    // Check rows
    for (int i = 0; i < 9; i++) {
        unordered_set<int> rowSet;
        for (int j = 0; j < 9; j++) {
            int num = board[i][j];
            if (num != 0) { // Skip empty cells
                if (rowSet.find(num) != rowSet.end()) {
                    return false;
                }
                rowSet.insert(num);
            }
        }
    }

    // Check columns
    for (int j = 0; j < 9; j++) {
        unordered_set<int> colSet;
        for (int i = 0; i < 9; i++) {
            int num = board[i][j];
            if (num != 0) { // Skip empty cells
                if (colSet.find(num) != colSet.end()) {
                    return false;
                }
                colSet.insert(num);
            }
        }
    }

    // Check 3x3 subgrids
    for (int startRow = 0; startRow < 9; startRow += 3) {
        for (int startCol = 0; startCol < 9; startCol += 3) {
            unordered_set<int> boxSet;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int num = board[startRow + i][startCol + j];
                    if (num != 0) { // Skip empty cells
                        if (boxSet.find(num) != boxSet.end()) {
                            return false;
                        }
                        boxSet.insert(num);
                    }
                }
            }
        }
    }

    return true;
}



bool isSafe(vector<vector<int>>& grid, int row, int col, int num) {
    // Check if 'num' is not in the current row, column, and 3x3 subgrid
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num ||
            grid[row - row % 3 + x / 3][col - col % 3 + x % 3] == num) {
            return false;
        }
    }
    return true;
}

bool solveSudoku(vector<vector<int>>& grid) {
    int row, col;
    bool isEmpty = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == UNASSIGNED) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) break;
    }

    // If no empty space is left
    if (!isEmpty) return true;

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) return true;
            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}

void printGrid(const vector<vector<int>>& grid) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

void inputGrid(vector<vector<int>>& grid) {
    cout << "Enter the Sudoku grid (use 0 for empty cells):\n";
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> grid[row][col];
        }
    }
}

int main() {
    vector<vector<int>> grid(N, vector<int>(N, 0));

    inputGrid(grid);
cout<< " _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<endl;
    cout << "Input Sudoku grid:\n";
    
    printGrid(grid);
    cout<< " _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<endl;
    if (isValidSudoku(grid)) {
        cout << "The Sudoku board is valid." << endl;
    

    if (solveSudoku(grid)) {
        cout << "Solved Sudoku grid:\n";
        printGrid(grid);
    }
    }
    
     else {
        cout << "The Sudoku board is invalid." << endl;
    }

    return 0;
}

