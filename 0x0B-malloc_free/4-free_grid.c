#include <stdio.h>
#include <stdlib.h>

/**
 * free_grid - Entry point
 *
 *  * @grid: 2 dimensional array
 *  * @height: the length of the 2 dimensional array
 *
 * Description: Function that frees a 2 dimensional grid
 * previously created by your alloc_grid function.
 *
 * Prototype: void free_grid(int **grid, int height);
 *
 * Note that we will compile with your alloc_grid.c file.
 * Make sure it compiles.
 *
 *
 * Return: void (nothing)
 *
 */

void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]);

	free(grid);
}

