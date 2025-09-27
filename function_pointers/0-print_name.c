#include "function_pointers.h"

/**
 * print_name - calls a function to print a name
 * @name: the string to print
 * @f: pointer to a function that takes a char * and prints it
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}
