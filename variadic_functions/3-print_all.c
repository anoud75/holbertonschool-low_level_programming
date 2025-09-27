#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - print values based on a format: c,i,f,s
 * @format: characters describing the arguments to print
 *
 * Rules: no for/goto/else/do..while/?:; <=2 if; <=2 while.
 * Unknown specifiers are ignored. Separator only between items.
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0;
	int printed = 0;
	const char *sep[2] = {"", ", "};
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
			printf("%s", sep[printed]);
			s = va_arg(ap, char *);
			if (s == NULL)
				printf("(nil)");
			if (s != NULL)
				printf("%s", s);
			printed = 1;
			break;
		default:
			break;
		}
		i++;
	}

	printf("\n");
	va_end(ap);
}
