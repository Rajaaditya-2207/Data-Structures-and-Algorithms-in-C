#include <stdio.h>

int linearSearch(int arr[], int index, int size, int key) {
    if (index >= size)
        return -1;
    if (arr[index] == key)
        return index;
    return linearSearch(arr, index + 1, size, key);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    int arr[size], key;
    for(int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int result = linearSearch(arr, 0, size, key);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");
    return 0;
}