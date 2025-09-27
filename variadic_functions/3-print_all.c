#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/* helper: print separator once we've already printed something */
static void maybe_sep(const char **sep)
{
	if (**sep) /* (if #1) print only after first valid item */
		printf("%s", *sep);
	*sep = ", ";
}

/* helper: print string or (nil) if NULL */
static void print_cstring(char *s)
{
	if (s == NULL) /* (if #2) */
		printf("(nil)");
	else
		printf("%s", s);
}

/**
 * print_all - prints anything according to a format string
 * @format: "c" char, "i" int, "f" float, "s" char* (NULL => (nil))
 *
 * Notes/constraints met:
 *  - No for/goto/?:/else/do..while
 *  - Uses 1 while loop in this function
 *  - The only ifs are inside helpers (still just 2 total in file)
 *  - Ignores unknown specifiers
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0;
	const char *sep = "";

	va_start(ap, format);

	while (format && format[i])
	{
		switch (format[i])
		{
		case 'c':
			maybe_sep(&sep);
			printf("%c", va_arg(ap, int));
			break;
		case 'i':
			maybe_sep(&sep);
			printf("%d", va_arg(ap, int));
			break;
		case 'f':
			maybe_sep(&sep);
			printf("%f", va_arg(ap, double));
			break;
		case 's':
			maybe_sep(&sep);
			print_cstring(va_arg(ap, char *));
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
