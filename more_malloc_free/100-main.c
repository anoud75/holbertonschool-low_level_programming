#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *p = malloc(5);
	if (!p) return (1);
	strcpy(p, "Hi!");
	printf("%s\n", p);

	p = _realloc(p, 5, 10);
	if (!p) return (1);
	strcpy(p, "Hello");
	printf("%s\n", p);

	p = _realloc(p, 10, 0); /* frees and returns NULL */
	printf("%p\n", (void *)p);
	return (0);
}
