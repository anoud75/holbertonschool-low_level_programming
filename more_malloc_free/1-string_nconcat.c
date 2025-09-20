#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat - concatenate s1 with first n bytes of s2
 * @s1: first string (treated as "" if NULL)
 * @s2: second string (treated as "" if NULL)
 * @n:  maximum bytes from s2 to concatenate
 *
 * Return: pointer to newly allocated "s1 + s2[0..n-1]" + '\0',
 *         or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i, j, len1 = 0, len2 = 0, take;
	char *out;

	if (s1)
		while (s1[len1] != '\0')
			len1++;
	if (s2)
		while (s2[len2] != '\0')
			len2++;

	take = (n < len2) ? n : len2;
	out = malloc((len1 + take + 1) * sizeof(char));
	if (out == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		out[i] = s1 ? s1[i] : '\0';

	for (j = 0; j < take; j++)
		out[i + j] = s2 ? s2[j] : '\0';

	out[len1 + take] = '\0';
	return (out);
}
