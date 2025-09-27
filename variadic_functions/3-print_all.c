#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * p_char - print a char with current separator and update it
 * @sep: pointer to current separator string
 * @c: character (as int) to print
 */
static void p_char(const char **sep, int c)
{
	printf("%s%c", *sep, (char)c);
	*sep = ", ";
}

/**
 * p_int - print an int with separator and update it
 * @sep: pointer to current separator string
 * @n: integer to print
 */
static void p_int(const char **sep, int n)
{
	printf("%s%d", *sep, n);
	*sep = ", ";
}

/**
 * p_float - print a double with separator and update it
 * @sep: pointer to current separator string
 * @d: double to print
 */
static void p_float(const char **sep, double d)
{
	printf("%s%f", *sep, d);
	*sep = ", ";
}

/**
 * p_str - print a string (or "(nil)") with separator and update it
 * @sep: pointer to current separator string
 * @s: string to print (may be NULL)
 */
static void p_str(const char **sep, char *s)
{
	if (s == NULL)
		s = "(nil)";
	printf("%s%s", *sep, s);
	*sep = ", ";
}

/**
 * print_all - prints anything according to a format string
 * @format: list of types: 'c' char, 'i' int, 'f' float, 's' char *
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
			p_char(&sep, va_arg(ap, int));
			break;
		case 'i':
			p_int(&sep, va_arg(ap, int));
			break;
		case 'f':
			p_float(&sep, va_arg(ap, double));
			break;
		case 's':
			p_str(&sep, va_arg(ap, char *));
			break;
		default:
			break;
		}
		i++;
	}
	printf("\n");
	va_end(ap);
}
