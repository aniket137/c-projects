#include <iostream>
#include <vector>
using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(const vector<vector<char>>& board) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

// Function to check if there is a win
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

// Function to check if the board is full (tie)
bool checkTie(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') return false; // Empty space found, game not over
        }
    }
    return true; // Board is full
}

// Function to handle player's move
bool makeMove(vector<vector<char>>& board, int row, int col, char player) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        cout << "Invalid move. Please enter valid coordinates." << endl;
        return false;
    }
    if (board[row][col] != ' ') {
        cout << "Cell already occupied. Please choose another cell." << endl;
        return false;
    }
    board[row][col] = player;
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize empty board

    char currentPlayer = 'X'; // X starts the game

    bool gameOver = false;

    while (!gameOver) {
        displayBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (makeMove(board, row, col, currentPlayer)) {
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins! Congratulations!" << endl;
                gameOver = true;
            } else if (checkTie(board)) {
                displayBoard(board);
                cout << "It's a tie!" << endl;
                gameOver = true;
            } else {
                // Switch player
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
    }

    return 0;
}

