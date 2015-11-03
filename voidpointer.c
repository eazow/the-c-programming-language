#include <stdio.h>
void *test(void *a);

int main()
{

    int i = 0;
    int *b = &i;

    test(b);

    return 1;
}

void *test(void *a) {
    return a;
}
