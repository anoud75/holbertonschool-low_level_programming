#include "3-calc.h"

/**
 * op_add - add two integers
 */
int op_add(int a, int b) { return (a + b); }

/**
 * op_sub - subtract two integers
 */
int op_sub(int a, int b) { return (a - b); }

/**
 * op_mul - multiply two integers
 */
int op_mul(int a, int b) { return (a * b); }

/**
 * op_div - divide a by b (b != 0 guaranteed by main)
 */
int op_div(int a, int b) { return (a / b); }

/**
 * op_mod - modulo a by b (b != 0 guaranteed by main)
 */
int op_mod(int a, int b) { return (a % b); }
