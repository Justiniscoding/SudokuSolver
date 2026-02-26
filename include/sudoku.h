#ifndef SUDOKUSOLVER_SUDOKU
#define SUDOKUSOLVER_SUDOKU

#include <stdbool.h>

struct _Sudoku {
	int grid[9][9];
};

typedef struct _Sudoku Sudoku;

void InitializeSudoku(Sudoku *sudoku);
void PrintSudoku(Sudoku *sudoku);
void GetFirstEmptyIndex(Sudoku *sudoku, int *indicies);
void GenerateRandomSudoku(Sudoku *sudoku);
void RemoveSudokuSquares(Sudoku *sudoku);

bool SolveSudoku(Sudoku *sudoku);
bool IsSudokuSolved(Sudoku *sudoku);
bool IsPlacementValid(Sudoku *sudoku, int row, int column, int value);
bool FillSudokuRandomly(Sudoku *sudoku);

Sudoku CloneSudoku(Sudoku *sudoku);

#endif
