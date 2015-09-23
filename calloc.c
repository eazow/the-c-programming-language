#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *p = calloc(1, sizeof(int));

	printf("%d", *p);

	free(p);

	return 0;

}
