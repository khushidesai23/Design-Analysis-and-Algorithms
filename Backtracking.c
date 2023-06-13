//Khushi Desai
//21BCP264

#include <stdio.h>
#include <stdbool.h>

bool isSafe(int board[][100], int n, int row, int col) {
    int i, j;
    
    // Check this row on the left side
    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }
    
    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }
    
    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }
    
    // If no conflicts, return true
    return true;
}

bool solveNQueens(int board[][100], int n, int col) {
    // Base case: all queens have been placed
    if (col >= n) {
        return true;
    }
    
    // Try placing a queen in each row in this column
    for (int i = 0; i < n; i++) {
        if (isSafe(board, n, i, col)) {
            board[i][col] = 1;
            
            // Recursively place queens in the next column
            if (solveNQueens(board, n, col + 1)) {
                return true;
            }
            
            // If placing the queen in this row doesn't work, backtrack and try the next row
            board[i][col] = 0;
        }
    }
    
    // If we've tried all rows and none work, return false
    return false;
}

void printBoard(int board[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the board size: ");
    scanf("%d", &n);
    
    int board[100][100] = {0};
    
    if (solveNQueens(board, n, 0)) {
        printf("Solution found:\n");
        printBoard(board, n);
    } else {
        printf("No solution found.\n");
    }
    
    return 0;
}
