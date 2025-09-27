#include <stddef.h>              /* for NULL */
#include "variadic_functions.h"

int main(void)
{
	print_strings(", ", 2, "Jay", "Django");
	print_strings(" | ", 5, "Hello", NULL, "School", "", "OK");
	print_strings(NULL, 3, "A", "B", "C");
	return (0);
}
