#include <stdio.h>

#include "sudoku.h"

int main() {
	Sudoku sudoku;
	InitializeSudoku(&sudoku);

	/* for (int i = 0; i < 9; i++) { */
	/* 	char c; */
	/* 	for (int j = 0; j < 9; j++) { */
	/* 		scanf("%c", &c); */
	/**/
	/* 		int number; */
	/**/
	/* 		if (c == ' ') { */
	/* 			number = 0; */
	/* 		} else { */
	/* 			number = (int)c; */
	/* 		} */
	/* 		sudoku.grid[i][j] = c; */
	/* 	} */
	/* 	scanf("%c", &c); */
	/* } */

	PrintSudoku(&sudoku);
	SolveSudoku(&sudoku);

	return 0;
}
