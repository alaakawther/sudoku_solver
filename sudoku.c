#include <stdio.h>

#define SIZE 9

void printBoard(int board[SIZE][SIZE]);
int findEmpty(int board[SIZE][SIZE], int *row, int *col);
int isValid(int board[SIZE][SIZE], int row, int col, int num);
int solveSudoku(int board[SIZE][SIZE]);

void printBoard(int board[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        if (row % 3 == 0 && row != 0)
            printf("------+-------+------\n");

        for (int col = 0; col < SIZE; col++) {
            if (col % 3 == 0 && col != 0)
                printf(" |");

            printf(" %d", board[row][col]);
        }
        printf("\n");
    }
}

int findEmpty(int board[SIZE][SIZE], int *row, int *col) {
    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (board[*row][*col] == 0)
                return 1;
        }
    }
    return 0;
}

int isValid(int board[SIZE][SIZE], int row, int col, int num) {
    for (int c = 0; c < SIZE; c++) {
        if (board[row][c] == num)
            return 0;
    }

    for (int r = 0; r < SIZE; r++) {
        if (board[r][col] == num)
            return 0;
    }

    int boxRow = row - (row % 3);
    int boxCol = col - (col % 3);

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (board[boxRow + r][boxCol + c] == num)
                return 0;
        }
    }

    return 1;
}

int solveSudoku(int board[SIZE][SIZE]) {
    int row, col;

    if (!findEmpty(board, &row, &col))
        return 1;

    for (int num = 1; num <= 9; num++) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;

            if (solveSudoku(board))
                return 1;

            board[row][col] = 0;
        }
    }

    return 0;
}

int main() {
    int board[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    printf("=== Sudoku Solver in C ===\n\n");

    printf("Original Puzzle:\n");
    printBoard(board);

    printf("\n");

    if (solveSudoku(board)) {
        printf("Solved Puzzle:\n");
        printBoard(board);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}