<script lang="ts">
	import { onMount } from "svelte";

	const validKeys = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"];

	var gameGrid: number[][] = $state([]);
	var hasError: boolean[][] = $state([]);
	var focused = $state([-1, -1]);

	for (let i = 0; i < 9; i++) {
		gameGrid.push([1, 0, 2, 0, 3, 0, 4, 0, 5]);
		hasError.push(new Array(9).fill(false));
	}

	function focusGridItem(rowIndex: number, colIndex: number) {
		focused[0] = rowIndex;
		focused[1] = colIndex;
	}

	onMount(() => {
		document.addEventListener("keydown", (e) => {
			if (!validKeys.includes(e.key)) {
				return;
			}

			if (focused[0] != -1 && focused[1] != -1) {
				let number = parseInt(e.key);

				let focusedRow = focused[0];
				let focusedCol = focused[1];

				gameGrid[focusedRow][focusedCol] = number;
				hasError[focusedRow][focusedCol] = false;

				for (let i = 0; i < 9; i++) {
					if (i != focused[0]) {
						if (gameGrid[i][focusedCol] == number) {
							hasError[focusedRow][focusedCol] = true;
						}
					}
					if (i != focusedCol) {
						if (gameGrid[focusedRow][i] == number) {
							hasError[focusedRow][focusedCol] = true;
						}
					}
				}

				let clumpRow = Math.floor(focusedRow / 3) * 3;
				let clumpCol = Math.floor(focusedCol / 3) * 3;

				let inClump = new Set();

				for (let i = clumpRow; i < clumpRow + 3; i++) {
					for (let j = clumpCol; j < clumpCol + 3; j++) {
						if (i != focusedRow && i != focusedCol) {
							inClump.add(gameGrid[clumpRow][clumpCol]);
						}
					}
				}

				if (inClump.has(number)) {
					hasError[focusedRow][focusedCol] = true;
				}
			}
		});
	});
</script>

<div class="sudoku">
	{#each gameGrid as gridRow, indexRow}
		<div class="gridRow">
			{#each gridRow as gridItem, indexCol}
				<button
					class="sudokuButton"
					onclick={() => focusGridItem(indexRow, indexCol)}
					class:selected={focused[0] == indexRow &&
						focused[1] == indexCol}
					class:error={hasError[indexRow][indexCol]}
					>{gridItem == 0 ? " " : gridItem}</button
				>
			{/each}
		</div>
	{/each}
</div>

<style>
	.sudoku {
		border: 2px solid gray;
		display: flex;
		flex-direction: column;
		align-items: center;
		justify-content: center;

		width: 60vh;
		height: 60vh;
	}

	.gridRow {
		display: flex;
		flex-direction: row;
		align-items: center;
		justify-content: center;
	}

	.sudokuButton {
		width: 6vh;
		height: 6vh;
		border: 1px solid black;
		font-size: 3vw;
		font-family: "Trebuchet MS", "Lucida Sans Unicode", "Lucida Grande",
			"Lucida Sans", Arial, sans-serif;
		display: flex;
		align-items: center;
		justify-content: center;
	}

	.selected {
		border: 4px solid dodgerblue;
	}

	.error {
		border: 4px solid red;
	}
</style>
