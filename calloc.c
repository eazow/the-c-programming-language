#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *p = calloc(1, sizeof(int));
	*p = 100;

	int **pi = calloc(1, sizeof(int *));
	*pi = p;

	printf("%d", *p);
	printf("%d", **pi);

	free(p);
	free(pi);

	return 0;

}
