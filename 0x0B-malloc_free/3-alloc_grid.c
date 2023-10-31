#include <stdio.h>
#include <stdlib.h>

/**
 * alloc_grid - Entry point
 *
 *  * @width: the width of the 2 dimensional array
 *  * @height: the height of the 2 dimensional array
 *
 * Description: Function that returns a pointer to a 2 dimensional
 * array of integers.
 *
 * Prototype: int **alloc_grid(int width, int height);
 *
 * Each element of the grid should be initialized to 0
 *
 * Returns NULL if str = NULL
 *
 * The function should return NULL on failure
 *
 * If width or height is 0 or negative, return NULL
 *
 * Return: A pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 *
 */

int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = malloc(height * sizeof(int *));

	if (grid == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(width * sizeof(int));

		if (grid[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(grid[j]);

			free(grid);
			return (NULL);

		}
	}

	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			grid[i][j] = 0;

	return (grid);
}

