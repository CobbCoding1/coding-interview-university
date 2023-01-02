#include <stdlib.h>
#include <stdio.h>

int binary_search(int arr[], int target, int min, int max) {
    int mid = (min + max) / 2;

    //printf("%d\n", mid);


    mid = (min + max) / 2;
        
    if(min > max) {
        return -1;
    }

    if(arr[mid] == target) {
        return mid;
    }

    if(arr[mid] < target) {
        return(binary_search(arr, target, mid + 1, max));
    } else if(arr[mid] > target) {
        return(binary_search(arr, target, min, mid - 1));
    }
}

int main() {
    int array[5];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;
    printf("Index is: %d\n", binary_search(array, 3, 0, 5));
    return 0;
}