<<<<<<< HEAD

=======
#include <stdio.h>
/**
 * main - prints the alphabet in lowercase except e and q
 * Return: 0
 */
int main(void)
{
    char ch;

    for (ch = 'a'; ch <= 'z'; ch++)
        if (ch != 'e' && ch != 'q')
            putchar(ch);

    putchar('\n');
    return (0);
}
>>>>>>> c4b3d23 (variables_if_else_while: 4-print_alphabt (skip e and q))
