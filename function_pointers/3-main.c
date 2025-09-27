#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - simple calculator
 * @argc: arg count
 * @argv: arg vector
 * Return: 0 on success; exits 98/99/100 on errors
 */
int main(int argc, char *argv[])
{
	int a, b, result;
	int (*f)(int, int);
	char *op;

	if (argc != 4)            /* wrong arg count */
	{ printf("Error\n"); exit(98); }

	op = argv[2];
	f = get_op_func(op);
	if (!f || op[1] != '\0')  /* invalid operator or not single char */
	{ printf("Error\n"); exit(99); }

	a = atoi(argv[1]);
	b = atoi(argv[3]);
	if ((op[0] == '/' || op[0] == '%') && b == 0) /* div/mod by zero */
	{ printf("Error\n"); exit(100); }

	result = f(a, b);
	printf("%d\n", result);
	return (0);
}
