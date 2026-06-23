# Sudoku Solver in C

This is a simple Sudoku solver written in C.  
It uses a backtracking algorithm to solve a 9x9 Sudoku puzzle.

## How it works

- The program reads a hardcoded Sudoku board
- It finds empty cells (represented by 0)
- It tries numbers from 1 to 9
- If a number is valid, it places it and continues
- If it gets stuck, it backtracks

## How to run

Compile:

gcc sudoku.c -o sudoku


Run:


./sudoku


(On Windows:)


sudoku.exe


## Example output

The program prints:
- The original puzzle
- The solved puzzle (if a solution exists)

## What I learned

- Backtracking algorithm
- 2D arrays in C
- Function decomposition
- Basic problem solving in C

## Notes

This is a beginner project and uses a simple approach without optimization.
