#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *s = string_nconcat("Best ", "School", 20);
	if (!s) return (1);
	printf("%s\n", s);
	free(s);
	return (0);
}
