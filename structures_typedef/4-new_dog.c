#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - compute string length
 * @s: string
 *
 * Return: number of chars before null byte
 */
static int _strlen(char *s)
{
	int n = 0;

	if (s == 0)
		return (0);

	while (s[n] != '\0')
		n++;
	return (n);
}

/**
 * _strdup2 - duplicate a string using malloc
 * @src: source string
 *
 * Return: pointer to new copy, or NULL on failure
 */
static char *_strdup2(char *src)
{
	int n, i;
	char *p;

	if (src == 0)
		return (0);

	n = _strlen(src);
	p = malloc((n + 1) * sizeof(char));
	if (p == 0)
		return (0);

	for (i = 0; i < n; i++)
		p[i] = src[i];
	p[n] = '\0';

	return (p);
}

/**
 * new_dog - create a new dog (deep copy name and owner)
 * @name: dog's name
 * @age: dog's age
 * @owner: owner's name
 *
 * Return: pointer to new dog, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;
	char *ncopy, *ocopy;

	d = malloc(sizeof(*d));
	if (d == 0)
		return (0);

	ncopy = _strdup2(name);
	if (ncopy == 0)
	{
		free(d);
		return (0);
	}

	ocopy = _strdup2(owner);
	if (ocopy == 0)
	{
		free(ncopy);
		free(d);
		return (0);
	}

	d->name = ncopy;
	d->age = age;
	d->owner = ocopy;

	return (d);
}
