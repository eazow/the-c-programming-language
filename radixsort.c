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

    while(max / exp > 0) {

        int bucket[BASE] = {0};

        for(i=0; i<n; i++) {
            bucket[(arr[i]/exp)%BASE]++;
        }

        for(i=1; i<BASE; i++) {
            bucket[i] +=bucket[i-1];
        }
/**
        for(i=0; i<n; i++) {
            temp_arr[--bucket[(arr[i]/exp)%BASE]] = arr[i];
        }
*/
        for(i=n-1; i>=0; i--) {
            temp_arr[--bucket[(arr[i]/exp)%BASE]] = arr[i];
        }

        for(i=0; i<n; i++) {
            arr[i] = temp_arr[i];
        }

        exp *= BASE;
    }
}

int main()
{
    int arr[MAX];

    int i, n;

    for(i = 0; i < MAX; i++) {
        arr[i] = rand();
    }
    
    radixsort(&arr[0], MAX);

    for(i = 0; i < MAX; i++) {
        printf("%d\n", arr[i]);
    }
    printf("\n");

    return 0;
}
