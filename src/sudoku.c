#include "sudoku.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void InitializeSudoku(Sudoku *sudoku) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			sudoku->grid[i][j] = 0;
		}
	}
}

void PrintSudoku(Sudoku *sudoku) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int number = sudoku->grid[i][j];

			if (number == 0) {
				printf(".");
			} else {
				printf("%d", number);
			}

			printf(" ");

			if (j == 2 || j == 5) {
				printf("| ");
			}
		}
		printf("\n");

		if (i == 2 || i == 5) {
			printf("------+-------+------\n");
		}
	}
}

bool IsPlacementValid(Sudoku *sudoku, int row, int column, int value) {
	for (int i = 0; i < 9; i++) {
		if (sudoku->grid[row][i] == value) {
			return false;
		}
	}
	for (int i = 0; i < 9; i++) {
		if (sudoku->grid[i][column] == value) {
			return false;
		}
	}

	int clumpRow = (row / 3) * 3;
	int clumpCol = (column / 3) * 3;

	for (int i = clumpRow; i < clumpRow + 3; i++) {
		for (int j = clumpCol; j < clumpCol + 3; j++) {
			if (sudoku->grid[i][j] == value) {
				return false;
			}
		}
	}

	return true;
}

void GetFirstEmptyIndex(Sudoku *sudoku, int *indicies) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudoku->grid[i][j] == 0) {
				indicies[0] = i;
				indicies[1] = j;
				return;
			}
		}
	}
}

bool IsSudokuSolved(Sudoku *sudoku) {
	for (int i = 0; i < 9; i++) {
		bool encounteredInRow[9];
		bool encounteredInColumn[9];

		for (int j = 0; j < 9; j++) {
			encounteredInRow[j] = false;
			encounteredInColumn[j] = false;
		}

		for (int j = 0; j < 9; j++) {
			int rowValue = sudoku->grid[i][j] - 1;
			int columnValue = sudoku->grid[j][i] - 1;

			if (rowValue == -1 || columnValue == -1) {
				return false;
			}

			if (encounteredInRow[rowValue] == true) {
				return false;
			}
			if (encounteredInColumn[columnValue] == true) {
				return false;
			}
			encounteredInRow[rowValue] = true;
			encounteredInColumn[columnValue] = true;
		}
	}

	for (int i = 0; i < 9; i += 3) {
		for (int j = 0; j < 9; j += 3) {
			bool encounteredInClump[9];

			for (int k = 0; k < 9; k++) {
				encounteredInClump[k] = false;
			}

			for (int k = i; k < i + 3; k++) {
				for (int l = j; l < j + 3; l++) {
					int value = sudoku->grid[k][l] - 1;

					if (encounteredInClump[value] == true) {
						return false;
					}

					encounteredInClump[value] = true;
				}
			}
		}
	}

	return true;
}

bool SolveSudoku(Sudoku *sudoku) {
	int indicies[2] = {-1, -1};
	GetFirstEmptyIndex(sudoku, indicies);

	if (indicies[0] == -1) {
		if (IsSudokuSolved(sudoku)) {
			PrintSudoku(sudoku);
			return true;
		} else {
			return false;
		}
	}

	for (int i = 1; i < 10; i++) {
		if (IsPlacementValid(sudoku, indicies[0], indicies[1], i)) {
			sudoku->grid[indicies[0]][indicies[1]] = i;
			if (SolveSudoku(sudoku)) {
				return true;
			}
		}
	}

	sudoku->grid[indicies[0]][indicies[1]] = 0;

	return false;
}

void GenerateRandomSudoku(Sudoku *sudoku) {
	FillSudokuRandomly(sudoku);
	RemoveSudokuSquares(sudoku);
}

void RemoveSudokuSquares(Sudoku *sudoku) {
	for (int i = 0; i < 75; i++) {
		int row = rand() % 9;
		int column = rand() % 9;

		sudoku->grid[row][column] = 0;
	}
}

bool FillSudokuRandomly(Sudoku *sudoku) {
	int indicies[2] = {-1, -1};
	GetFirstEmptyIndex(sudoku, indicies);

	if (indicies[0] == -1) {
		return true;
	}

	int numberOrder[9];

	for (int i = 0; i < 9; i++) {
		numberOrder[i] = i + 1;
	}

	for (int i = 0; i < 8; i++) {
		int j = i + rand() / (RAND_MAX / (9 - i) + 1);
		int temp = numberOrder[j];
		numberOrder[j] = numberOrder[i];
		numberOrder[i] = temp;
	}

	for (int i = 0; i < 9; i++) {
		if (IsPlacementValid(sudoku, indicies[0], indicies[1],
							 numberOrder[i])) {
			sudoku->grid[indicies[0]][indicies[1]] = numberOrder[i];
			if (FillSudokuRandomly(sudoku)) {
				return true;
			}
		}
	}

	sudoku->grid[indicies[0]][indicies[1]] = 0;
	return false;
}

Sudoku CloneSudoku(Sudoku *sudoku) {
	Sudoku new;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			new.grid[i][j] = sudoku->grid[i][j];
		}
	}

	return new;
}
