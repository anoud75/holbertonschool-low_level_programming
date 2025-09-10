#include "main.h"

static int _rsqrt(int n, int guess)
{
	if (guess * guess > n)
		return (-1);
	if (guess * guess == n)
		return (guess);
	return (_rsqrt(n, guess + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of n
 * @n: number
 * Return: sqrt(n) if natural; otherwise -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (_rsqrt(n, 0));
}
