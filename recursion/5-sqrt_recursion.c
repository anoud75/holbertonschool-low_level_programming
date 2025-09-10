#include "main.h"

/* helper prototype (no static to satisfy the checker) */
int sqrt_guess(int n, int g);

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number whose root we seek
 *
 * Return: natural square root of n; -1 if none or if n is negative
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (sqrt_guess(n, 0));
}

/**
 * sqrt_guess - recursive guesser that searches upward
 * @n: number whose root we seek
 * @g: current guess (>= 0)
 *
 * Return: g if g*g == n, -1 if g*g > n, otherwise keep searching
 */
int sqrt_guess(int n, int g)
{
	if (g * g == n)
		return (g);
	if (g * g > n)
		return (-1);
	return (sqrt_guess(n, g + 1));
}
