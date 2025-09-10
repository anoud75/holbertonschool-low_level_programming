#include "main.h"

/**
 * wildcmp - compares two strings, s2 can contain the wildcard *
 * @s1: string
 * @s2: pattern (may contain *)
 * Return: 1 if identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		/* skip consecutive '*' */
		while (*s2 == '*')
			s2++;
		if (!*s2)
			return (1);        /* trailing * matches rest */
		/* try to match s2 after * at any position in s1 */
		return (*s1 && (wildcmp(s1 + 1, s2) || wildcmp(s1, s2)));
	}
	if (!*s1 || !*s2)
		return (*s1 == *s2);
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	return (0);
}
