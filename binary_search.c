#include <stdio.h>

int binary_search(int arr[], int arr_len, int num);

int main(void)
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int arr_len = sizeof(arr) / sizeof(int);

    printf("Index of %d is %d.\n", 1, binary_search(arr, arr_len, 1));
    printf("Index of %d is %d.\n", 9, binary_search(arr, arr_len, 9));
    
    printf("Index of %d is %d.\n", 2, binary_search(arr, arr_len, 2));
    printf("Index of %d is %d.\n", 8, binary_search(arr, arr_len, 8));
    
    printf("Index of %d is %d.\n", 10, binary_search(arr, arr_len, 10));
    printf("Index of %d is %d.\n", 0, binary_search(arr, arr_len, 0));
    return 0;
}

int binary_search(int arr[], int arr_len, int num)
{
    int steps = 0;
    int index = -1;
    int left = 0;
    int right = --arr_len;
    
    while (left <= right) { 
        int mid = (right + left) / 2; 
        printf("Step=%d left=%d mid=%d right=%d\n", ++steps, left, mid, right);

        if (arr[mid] == num) return mid;
        else if (num < arr[mid]) right = --mid;    
        else if (num > arr[mid]) left = ++mid;
    }

    return index;
}
