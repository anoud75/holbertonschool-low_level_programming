#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, *a = array_range(5, 10);
	if (!a) return (1);
	for (i = 0; i < 6; i++) printf("%d ", a[i]);
	printf("\n");
	free(a);
	return (0);
}
