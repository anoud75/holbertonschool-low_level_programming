#include "variadic_functions.h"

/**
 * print_number - prints a number recursively
 * @n: number to print
 */
void print_number(unsigned int n)
{
	if (n / 10)
		print_number(n / 10);
	_putchar((n % 10) + '0');
}

/**
 * print_all - prints anything based on format string
 * @format: list of types of arguments passed to the function
 *
 * Description: Prints arguments according to format specifiers
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i, j, n;
	char *sep, *s;
	float f;

	va_start(args, format);
	i = 0;
	sep = "";
	while (format && format[i])
	{
		if (format[i] == 'c' || format[i] == 'i' || format[i] == 'f' || format[i] == 's')
		{
			j = 0;
			while (sep[j])
				_putchar(sep[j++]);
			sep = ", ";
		}
		if (format[i] == 'c')
			_putchar(va_arg(args, int));
		if (format[i] == 'i')
		{
			n = va_arg(args, int);
			if (n < 0)
			{
				_putchar('-');
				n = -n;
			}
			print_number(n);
		}
		if (format[i] == 'f')
		{
			f = va_arg(args, double);
			if (f != f)
			{
				_putchar('n');
				_putchar('a');
				_putchar('n');
			}
		}
		if (format[i] == 's')
		{
			s = va_arg(args, char *);
			if (s == 0)
				s = "(nil)";
			j = 0;
			while (s[j])
				_putchar(s[j++]);
		}
		i++;
	}
	va_end(args);
	_putchar('\n');
}
