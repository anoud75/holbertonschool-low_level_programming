#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything according to a format string
 * @format: types: 'c' char, 'i' int, 'f' float, 's' char*
 *
 * Unknown specifiers are ignored. Prints a newline at the end.
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
            printf("%s", sep);
            if (s == NULL)
                printf("(nil)");
            if (s != NULL)
                printf("%s", s);
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
