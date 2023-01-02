#include <stdlib.h>
#include <stdio.h>

int binary_search(int arr[], int target, int length) {
    int min = 0;
    int max = length;
    int mid = (min + max) / 2;

    //printf("%d\n", mid);


    while(arr[mid] != target) {
        mid = (min + max) / 2;
        
        if(min > max) {
            return -1;
        }

        if(arr[mid] < target) {
            min = mid + 1;
        } else if(arr[mid] > target) {
            max = mid - 1;
        }
    }
    return mid;
}

int main() {
    int array[5];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;
    printf("Index is: %d\n", binary_search(array, 6, 5));
    return 0;
}