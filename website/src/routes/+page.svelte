<script>
	import SudokuGame from "$lib/SudokuGame.svelte";
</script>

<h1>Sudoku</h1>
<div class="sudokuContainer">
	<SudokuGame />
</div>

<style>
	h1 {
		text-align: center;
	}

	.sudokuContainer {
		display: flex;
		width: 100vw;
		justify-content: center;
	}
</style>
