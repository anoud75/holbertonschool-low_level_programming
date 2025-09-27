#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything according to a format string
 * @format: list of types: 'c' char, 'i' int, 'f' float, 's' char*
 *
 * Rules: no for/goto/else/do..while/?:; at most 2 if (we use 1); at most 2 while (we use 1)
 * Unknown specifiers are ignored. Separator printed only between valid items.
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0;
	int printed = 0;                 /* 0 before first valid item, 1 after */
	const char *sep[2] = {"", ", "}; /* choose sep[printed] */
	char *s;

	va_start(ap, format);

	while (format && format[i])
	{
		switch (format[i])
		{
		case 'c':
			printf("%s%c", sep[printed], (char)va_arg(ap, int));
			printed = 1;
			break;
		case 'i':
			printf("%s%d", sep[printed], va_arg(ap, int));
			printed = 1;
			break;
		case 'f':
			printf("%s%f", sep[printed], va_arg(ap, double));
			printed = 1;
			break;
		case 's':
			s = va_arg(ap, char *);
			printf("%s", sep[printed]);
			if (s == NULL)              /* only IF we use */
				printf("(nil)");
			else
				printf("%s", s);
			printed = 1;
			break;
		default:
			/* ignore unknown specifier */
			break;
		}
		i++;
	}

	printf("\n");
	va_end(ap);
}
