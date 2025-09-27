#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_strings - prints strings separated by a separator, then newline
 * @separator: string printed between strings (ignored if NULL)
 * @n: number of strings to print
 *
 * If a string argument is NULL, prints "(nil)" in its place.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;
	const char *s;

	va_start(ap, n);

	for (i = 0; i < n; i++)
	{
		s = va_arg(ap, const char *);
		if (s == NULL)
			printf("(nil)");
		else
			printf("%s", s);

		if (separator && i + 1 < n)
			printf("%s", separator);
	}
	printf("\n");

	va_end(ap);
}
