#include <stdio.h>

/**
 * main - prints the alphabet in lowercase, then uppercase, then a newline
 * Return: 0 on success
 */
int main(void)
{
	char ch;

	for (ch = 'a'; ch <= 'z'; ch++)
		putchar(ch);
	for (ch = 'A'; ch <= 'Z'; ch++)
		putchar(ch);
	putchar('\n');

	return (0);
}
