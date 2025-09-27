#include "variadic_functions.h"

/**
 * print_all - prints anything based on format string
 * @format: list of types of arguments passed to the function
 *
 * Description: Prints arguments according to format specifiers
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i;
	char *s;
	char *sep;

	va_start(args, format);
	i = 0;
	sep = "";
	while (format && format[i])
	{
		if (format[i] == 'c')
		{
			printf("%s%c", sep, va_arg(args, int));
			sep = ", ";
		}
		if (format[i] == 'i')
		{
			printf("%s%d", sep, va_arg(args, int));
			sep = ", ";
		}
		if (format[i] == 'f')
		{
			printf("%s%f", sep, va_arg(args, double));
			sep = ", ";
		}
		if (format[i] == 's')
		{
			s = va_arg(args, char *);
			printf("%s%s", sep, s ? s : "(nil)");
			sep = ", ";
		}
		i++;
	}
	printf("\n");
	va_end(args);
}
