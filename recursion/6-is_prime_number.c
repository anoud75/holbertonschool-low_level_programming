#include "main.h"

static int _prime_test(int n, int d)
{
	if (n < 2)
		return (0);
	if (d * d > n)
		return (1);
	if (n % d == 0)
		return (0);
	return (_prime_test(n, d + 1));
}

/**
 * is_prime_number - checks if n is a prime number
 * @n: number
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	return (_prime_test(n, 2));
}
