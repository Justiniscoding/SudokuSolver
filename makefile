main:
	gcc -I ./include -o SudokuSolver ./src/main.c $(filter-out ./src/main.c,$(wildcard ./src/*.c))
	./SudokuSolver
