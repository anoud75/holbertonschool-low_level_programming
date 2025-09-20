#include <stdlib.h>
#include "main.h"

/**
 * str_concat - concatenates two strings into newly allocated memory
 * @s1: first string (treated as "" if NULL)
 * @s2: second string (treated as "" if NULL)
 *
 * Return: pointer to the new "s1 + s2" string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *out;
	unsigned int len1 = 0, len2 = 0, i, j;

	if (s1)
		while (s1[len1] != '\0')
			len1++;
	if (s2)
		while (s2[len2] != '\0')
			len2++;

	out = malloc((len1 + len2 + 1) * sizeof(char));
	if (out == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		out[i] = s1[i];
	for (j = 0; j < len2; j++)
		out[i + j] = s2[j];

	out[len1 + len2] = '\0';
	return (out);
}
