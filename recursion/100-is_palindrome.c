#include "main.h"

static int _len(char *s){ return (*s ? 1 + _len(s + 1) : 0); }

static int _pal(char *s, int l, int r)
{
	if (l >= r)
		return (1);
	if (s[l] != s[r])
		return (0);
	return (_pal(s, l + 1, r - 1));
}

/**
 * is_palindrome - returns 1 if a string is a palindrome, 0 otherwise
 * @s: string
 */
int is_palindrome(char *s)
{
	return (_pal(s, 0, _len(s) - 1));
}
