#include <stdio.h>
#include <string.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    printf("Input the array size:\n");
    int size = 0;
    scanf("%d", &size);
    if (size < 0) {
        printf("Invalid size");
        return 0;
    }
    int arr[size], swaped = 1;
    printf("Input the array elements separated by a space\n");
    for (int i = 0; i < size; ++i) {
        scanf("%d", arr + i);
    }
    while (swaped) {
        swaped = 0;
        for (int i = 1; i < size; ++i) {
            if (arr[i - 1] > arr[i]) {
                swap(arr + i - 1, arr + i);
                swaped = 1;
            }
        }
    }
    printf("Sorted array: \n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
}

