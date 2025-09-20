#include "main.h"
#include <stdio.h>

int main(void)
{
	void *p = malloc_checked(10);

	printf("ok: %p\n", p);
	free(p);
	return (0);
}
