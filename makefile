main:
	gcc -I ./include -o SudokuSolver ./src/main.c $(filter-out ./src/main.c,$(wildcard ./src/*.c)) -O3 -ffast-math
	./SudokuSolver

debug:
	gcc -I ./include -o SudokuSolver ./src/main.c $(filter-out ./src/main.c,$(wildcard ./src/*.c)) -gdwarf-4 -g
	lldb SudokuSolver
