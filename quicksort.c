#include <stdio.h>

void print_array(int *nums, int length);

int quicksort(int *nums, int low, int high) {
    if(low < high) {
        int key = nums[low];
        int left = low;
        int right = high;

        while(left < right) {
            while(left < right && key <= nums[right]) 
                right--;
            nums[left] = nums[right];

            while(left < right && key >= nums[left])
                left++;
            nums[right] = nums[left];
            print_array(nums, 10);
        }
        nums[left] = key;
        quicksort(nums, low, left-1);
        quicksort(nums, left+1, high);
    }
}

void print_array(int *nums, int length) {
    int i = 0;
    for(i = 0; i < length; i++)
        printf("%d ", nums[i]);
    printf("\n");
}

int main(int argc, char *argv[]) {
    int nums[10] = {2,1,5,6,1,2,9,7,5,2};
    int i = 0;

    print_array(nums, 10);

    quicksort(nums, 0, 9);

    print_array(nums, 10);
}
