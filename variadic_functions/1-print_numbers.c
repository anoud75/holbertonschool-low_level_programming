#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_numbers - prints numbers separated by a string, then newline
 * @separator: string printed between numbers (ignored if NULL)
 * @n: how many integers follow
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;

	va_start(ap, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(ap, int));
		if (separator && i + 1 < n)
			printf("%s", separator);
	}
	printf("\n");

	va_end(ap);
}
