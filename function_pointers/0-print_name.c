#include "function_pointers.h"

/**
 * print_name - calls a function to print a name
 * @name: string to print
 * @f: function pointer taking a (char *) and printing it
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (f && name)
		f(name);
}
