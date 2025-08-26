#include <stdio.h>

/**
 * main - prints all base 16 numbers in lowercase
 * Return: 0 on success
 */
int main(void)
{
	int d;
	char c;

	for (d = '0'; d <= '9'; d++)
		putchar(d);
	for (c = 'a'; c <= 'f'; c++)
		putchar(c);
	putchar('\n');

	return (0);
}
