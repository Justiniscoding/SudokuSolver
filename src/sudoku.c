#include "sudoku.h"
#include <stdbool.h>
#include <stdio.h>

void InitializeSudoku(Sudoku *sudoku) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			sudoku->grid[i][j] = 0;
		}
	}
	sudoku->grid[0][0] = 5;
	sudoku->grid[0][1] = 3;
	sudoku->grid[0][4] = 7;
	sudoku->grid[1][0] = 6;
	sudoku->grid[1][3] = 1;
	sudoku->grid[1][4] = 9;
	sudoku->grid[1][5] = 5;
	sudoku->grid[2][1] = 9;
	sudoku->grid[2][2] = 8;
	sudoku->grid[2][7] = 6;
	sudoku->grid[3][0] = 8;
	sudoku->grid[3][4] = 6;
	sudoku->grid[3][8] = 3;
	sudoku->grid[4][0] = 4;
	sudoku->grid[4][3] = 8;
	sudoku->grid[4][5] = 3;
	sudoku->grid[4][8] = 1;
	sudoku->grid[5][0] = 7;
	sudoku->grid[5][4] = 2;
	sudoku->grid[5][8] = 6;
	sudoku->grid[6][1] = 6;
	sudoku->grid[6][6] = 2;
	sudoku->grid[6][7] = 8;
	sudoku->grid[7][3] = 4;
	sudoku->grid[7][4] = 1;
	sudoku->grid[7][5] = 9;
	sudoku->grid[7][8] = 5;
	sudoku->grid[8][4] = 8;
	sudoku->grid[8][7] = 7;
	sudoku->grid[8][8] = 9;
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

bool SolveSudoku(Sudoku *sudoku) {
	int indicies[2] = {-1, -1};
	GetFirstEmptyIndex(sudoku, indicies);

	if (indicies[0] == -1) {
		printf("Sudoku has been solved!\n");
		PrintSudoku(sudoku);
		return true;
	}

	for (int i = 1; i < 10; i++) {
		if (IsPlacementValid(sudoku, indicies[0], indicies[1], i)) {
			Sudoku new = CloneSudoku(sudoku);
			new.grid[indicies[0]][indicies[1]] = i;
			if (SolveSudoku(&new)) {
				return true;
			}
		}
	}

	return false;
}

Sudoku CloneSudoku(Sudoku *sodoku) {
	Sudoku new;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			new.grid[i][j] = sodoku->grid[i][j];
		}
	}

	return new;
}
