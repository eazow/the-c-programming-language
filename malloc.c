#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *p = malloc(1*sizeof(int));

	printf("%c", *p);

	free(p);

	return 0;

}
