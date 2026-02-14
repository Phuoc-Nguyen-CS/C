#include <iostream>
#include <vector>

enum Piece { Empty = 0, X = 1, O = 2};

int hasWon(std::vector<std::vector<int>>& board) {

    int n = board.size(); 
    if (n == 0) return Empty;

    // Checking Rows
    for (int i = 0; i < n; ++i) {
        int first = board[i][0];
        // If the first in the board is empty. No winner
        if (first == Empty) continue;
        bool rowWin = true;
        // We can go through the row now
        for (int j = 0; j < n; ++j) {
            if (board[i][j] != first) {
                rowWin = false;
                break;
            }
        }
        
        if (rowWin) {
            return first;
        }
    }

    // Checking Columns
    for (int j = 0; j < n; ++j) {
        int first = board[0][j];
        
        if (first == Empty) continue;
        bool colWin = true;
        // Go through the columns
        for (int i = 1; i < n; ++i) {
            if (board[i][j] != first) {
                colWin = false;
                break;
            }
        }

        if (colWin){
            return first;
        }
    }

    // Checking Left->Right Diagonal
    int prev = board[0][0];
    bool diagonalWin = true;
    for (int i = 0, j = 0; i < n; ++i, ++j) {
        if (prev == Empty || board[i][j] != prev) {
            diagonalWin = false;
            break;
        }
    }
    if (diagonalWin) {
        return prev;
    }

    // Checking Right -> Left Diagonal
    prev = board[0][2];
    diagonalWin = true;
    for (int i = 1, j = 1; i < n; ++i, --j) {
        if (prev == Empty || board[i][j] != prev) {
            diagonalWin = false;
            break;
        }
    }

    if (diagonalWin) {
        return prev;
    }

    return Empty;
}

int main(){
    
    std::vector<std::vector<int>> board = {
        {X,     Empty, O},
        {Empty, O,     O},
        {O,     Empty, }};
    
    int winner = hasWon(board);

    if (winner != 0) {
        std::cout << "Player " << (winner == X ? "X": "O") << " has won!" << std::endl;
    } else {
        std::cout << "No winner or draw." << std::endl;
    }

    return 0;
}