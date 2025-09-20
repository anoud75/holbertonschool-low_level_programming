#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, *a = _calloc(5, sizeof(int));
	if (!a) return (1);
	for (i = 0; i < 5; i++) printf("%d ", a[i]);
	printf("\n");
	free(a);
	return (0);
}
