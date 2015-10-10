#include <stdio.h>
#include <time.h>

#define MAX 20

#define BASE 10

void radixsort(int *arr, int n)
{
    int i, temp_arr[MAX], max=arr[0], exp=1;

    for(i=1; i<n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
}

int main()
{
    int arr[MAX] ;

    int i, n;

    for(i = 0; i < MAX; i++) {
        arr[i] = rand();
        print("%d\t", arr[i]);
    }

    radixsort(arr, MAX);

    puts();
    for(i = 0; i < MAX; i++) {
        printf("%d\t", arr[i]);
    }

    return 0;
}
