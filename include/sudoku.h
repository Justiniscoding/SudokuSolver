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

bool SolveSudoku(Sudoku *sudoku);
bool IsPlacementValid(Sudoku *sudoku, int row, int column, int value);

Sudoku CloneSudoku(Sudoku *sodoku);

#endif
