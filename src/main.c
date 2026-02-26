#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sudoku.h"

int main() {
	Sudoku sudoku;
	InitializeSudoku(&sudoku);

	srand(time(NULL));

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
	/* 			number = atoi(&c); */
	/* 		} */
	/* 		sudoku.grid[i][j] = number; */
	/* 	} */
	/* 	scanf("%c", &c); */
	/* } */

	clock_t start, end;
	start = clock();
	GenerateRandomSudoku(&sudoku);
	PrintSudoku(&sudoku);
	SolveSudoku(&sudoku);
	end = clock();
	printf("It took %f seconds to solve the sudoku!",
		   (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}
