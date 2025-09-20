#include <stdlib.h>
#include "main.h"

/**
 * array_range - create an int array from min to max inclusive
 * @min: start
 * @max: end
 *
 * Return: pointer to array [min..max], or NULL on failure/invalid range
 */
int *array_range(int min, int max)
{
	int *a;
	int i, len;

	if (min > max)
		return (NULL);

	len = max - min + 1;
	a = malloc((unsigned int)len * sizeof(int));
	if (a == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		a[i] = min + i;

	return (a);
}
