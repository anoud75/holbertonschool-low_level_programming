#include "function_pointers.h"

/**
 * int_index - searches an array for the first element matching cmp
 * @array: array of integers
 * @size: number of elements in @array
 * @cmp: pointer to a function that tests each element (non-zero = match)
 *
 * Return: index of first match; -1 if no match or on invalid input/size <= 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == 0 || cmp == 0 || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
		if (cmp(array[i]))
			return (i);

	return (-1);
}
