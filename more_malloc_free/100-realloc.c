#include <stdlib.h>
#include "main.h"

/**
 * _realloc - reallocate memory block
 * @ptr:      old block (may be NULL)
 * @old_size: size of old block in bytes
 * @new_size: desired size in bytes
 *
 * Return: pointer to new block, or NULL (rules mimic realloc)
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i, min;
	unsigned char *newp, *oldp;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	newp = malloc(new_size);
	if (newp == NULL)
		return (NULL);

	oldp = (unsigned char *)ptr;
	min = (new_size < old_size) ? new_size : old_size;

	for (i = 0; i < min; i++)
		newp[i] = oldp[i];

	free(ptr);
	return ((void *)newp);
}
