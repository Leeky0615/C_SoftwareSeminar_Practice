#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

void quick_sort(int* arr, int start, int end);
void printArr(int arr[]);

int main(void)
{   
    int arr[MAX_SIZE] = {7,5,9,0,3,1,6,2,4,8};

    quick_sort(arr, 0, MAX_SIZE - 1);
    printArr(arr);
    return 0;
}

void quick_sort(int* arr, int start, int end) {
    int temp = 0;
    if (start >= end) {
        return;
    }

    int pivot = start;
    int left = start + 1;
    int right = end;

    while (left <= right) {
        while (left <= end && arr[left] <= arr[pivot]) {
            left++;
        }
        while (right > start && arr[right] >= arr[pivot]) {
            right--;
        }
        if (left > right) {
            temp = arr[pivot];
            arr[pivot] = arr[right];
            arr[right] = temp;
        }
        else {
            temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
        }
    }
    quick_sort(arr, start, right - 1);
    quick_sort(arr, right + 1, end);
}

void printArr(int arr[]) {
    for (size_t i = 0; i < MAX_SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}