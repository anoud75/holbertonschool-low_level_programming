#include <stdlib.h>
#include "main.h"

/**
 * _calloc - allocate zero-initialized array
 * @nmemb: elements count
 * @size:  element size in bytes
 *
 * Return: pointer to zeroed memory, or NULL on failure/invalid input
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i, total;
	unsigned char *p;

	if (nmemb == 0 || size == 0)
		return (NULL);

	total = nmemb * size;
	/* (Optionally guard overflow: if size != 0 && total/size != nmemb) */

	p = malloc(total);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < total; i++)
		p[i] = 0;

	return ((void *)p);
}
