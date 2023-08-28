#include <stdio.h>
#include <stdlib.h>

// Define the merge function to merge two subarrays
void merge(int arr[], int left, int middle, int right)
{
    // Calculate the sizes of the subarrays
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Allocate memory for left and right subarrays
    int *leftArr = (int *)malloc(n1 * sizeof(int));
    int *rightArr = (int *)malloc(n2 * sizeof(int));

    // Populate the left and right subarrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[middle + 1 + i];

    // Merge the subarrays back into the original array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    // Merge any remaining elements from the left and right subarrays
    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    // Free the memory allocated for subarrays
    free(leftArr);
    free(rightArr);
}

// Define the mergeSort function to recursively sort the array
void mergeSort(int arr[], int left, int right)
{
    // Check the base case
    if (left < right)
    {
        // Calculate the middle index
        int middle = left + (right - left) / 2;

        // Recursively sort the left and right halves
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Merge the sorted halves
        merge(arr, left, middle, right);
    }
}

int main()
{
    int arrSize;
    // Prompt the user to enter the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &arrSize);

    // Allocate memory for the array
    int *arr = (int *)malloc(arrSize * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Prompt the user to enter the array elements
    printf("Enter %d elements:\n", arrSize);
    for (int i = 0; i < arrSize; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Display the unsorted array
    printf("Unsorted array: ");
    for (int i = 0; i < arrSize; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Perform merge sort on the array
    mergeSort(arr, 0, arrSize - 1);

    // Display the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < arrSize; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Free the memory allocated for the array
    free(arr);
    return 0;
}
