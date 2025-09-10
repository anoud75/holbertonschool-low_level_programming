#include "main.h"

/* helper (no static): recursively test divisors starting at 2 */
int prime_check(int n, int d);

/**
 * is_prime_number - returns 1 if n is a prime, otherwise 0
 * @n: integer to test
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (prime_check(n, 2));
}

/**
 * prime_check - recursive divisor test up to sqrt(n)
 * @n: number being tested
 * @d: current divisor guess (>= 2)
 *
 * Return: 1 if no divisor found (prime), 0 if divisible
 */
int prime_check(int n, int d)
{
	if (d * d > n)   /* past sqrt(n): n is prime */
		return (1);
	if (n % d == 0) /* found a divisor */
		return (0);
	return (prime_check(n, d + 1));
}
