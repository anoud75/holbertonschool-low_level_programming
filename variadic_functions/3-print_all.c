#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything according to a format string
 * @format: list of types: 'c' char, 'i' int, 'f' float, 's' char *
 *
 * Unknown specifiers are ignored. Always prints a trailing newline.
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0;
	const char *sep = "";
	char *s;

	va_start(ap, format);

	while (format && format[i])
	{
		switch (format[i])
		{
		case 'c':
			printf("%s%c", sep, (char)va_arg(ap, int));
			sep = ", ";
			break;
		case 'i':
			printf("%s%d", sep, va_arg(ap, int));
			sep = ", ";
			break;
		case 'f':
			printf("%s%f", sep, va_arg(ap, double));
			sep = ", ";
			break;
		case 's':
			s = va_arg(ap, char *);
			if (!s) s = "(nil)"; /* only IF in the file */
			printf("%s%s", sep, s);
			sep = ", ";
			break;
		default:
			break;
		}
		i++;
	}
	printf("\n");
	va_end(ap);
}
