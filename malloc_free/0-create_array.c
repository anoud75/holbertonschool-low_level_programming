#include <stdlib.h>
#include "main.h"

/**
 * create_array - Allocate an array of chars and initialize it with a char
 * @size: number of bytes to allocate
 * @c: char used to initialize the array
 *
 * Return: pointer to the new array, or NULL on failure or if size == 0
 */
char *create_array(unsigned int size, char c)
{
	char *arr;
	unsigned int i;

	if (size == 0)
		return (NULL);

	arr = malloc(size * sizeof(char));
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		arr[i] = c;

	return (arr);
}
