#include <stdlib.h>
#include "main.h"

/**
 * alloc_grid - allocate a 2D grid of ints and initialize to 0
 * @width:  number of columns
 * @height: number of rows
 *
 * Return: pointer to height x width grid (all zero),
 *         or NULL on failure or if width/height <= 0
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = malloc(sizeof(*grid) * height);
	if (grid == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(sizeof(**grid) * width);
		if (grid[i] == NULL)
		{
			/* free rows already allocated, then the row pointer array */
			while (i--)
				free(grid[i]);
			free(grid);
			return (NULL);
		}
		/* initialize row to 0 */
		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}

	return (grid);
}
