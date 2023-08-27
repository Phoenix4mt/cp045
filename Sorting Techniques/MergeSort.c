#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int *leftArr = (int *)malloc(n1 * sizeof(int));
    int *rightArr = (int *)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[middle + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    free(leftArr);
    free(rightArr);
}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}
int main() {
    int arrSize;
    printf("Enter the number of elements: ");
    scanf("%d", &arrSize);
    int *arr = (int *)malloc(arrSize * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter %d elements:\n", arrSize);
    for (int i = 0; i < arrSize; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Unsorted array: ");
    for (int i = 0; i < arrSize; i++)
        printf("%d ", arr[i]);
    printf("\n");
    mergeSort(arr, 0, arrSize - 1);
    printf("Sorted array: ");
    for (int i = 0; i < arrSize; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    return 0;
}
