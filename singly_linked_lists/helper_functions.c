#include "lists.h"

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
unsigned int _strlen(const char *s)
{
	unsigned int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: string to duplicate
 *
 * Return: pointer to the duplicated string, or NULL if it fails
 */
char *_strdup(const char *str)
{
	char *dup;
	unsigned int i, len;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);
	dup = malloc(sizeof(char) * (len + 1));

	if (dup == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		dup[i] = str[i];

	return (dup);
}
