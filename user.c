#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "sortingLib.h"

#define CONFIG_FILE "sorting_config.txt"

// Function to display the names of enabled sorting techniques
void displayEnabledSortingTechniques()
{
    FILE *file = fopen(CONFIG_FILE, "r");
    if (file == NULL)
    {
        printf("Error: Unable to open the configuration file.\n");
        return;
    }

    char line[100]; // Assuming each line is at most 100 characters
                    // Initialize the serial number

    while (fgets(line, sizeof(line), file) != NULL)
    {
        char techniqueName[50];
        char status[10];

        // Extract technique name and status (enabled or disabled)
        if (sscanf(line, "%s %s", techniqueName, status) == 2)
        {
            if (strcmp(status, "1") == 0)
            {
                printf(" %s\n", techniqueName);
            }
        }
    }

    fclose(file);
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{

    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    printArray(arr, size);
    char choice;
    displayEnabledSortingTechniques();
    printf("Enter your choice of sorting technique: ");
    scanf(" %c", &choice);
    switch (choice)
    {
    case 'B':
        bubbleSort(arr, size);
        printf("Array after Bubble Sort: ");
        break;
    case 'S':
        selectionSort(arr, size);
        printf("Array after Selection Sort: ");
        break;
    case 'I':
        insertionSort(arr, size);
        printf("Array after Insertion Sort: ");
        break;
    case 'M':
        mergeSort(arr, 0, size - 1);
        printf("Array after Merge Sort: ");
        break;
    case 'Q':
        quickSort(arr, 0, size - 1);
        printf("Array after Quick Sort: ");
        break;
    default:
        printf("Invalid choice\n");
        return 1;
    }

    printArray(arr, size);

    return 0;
}
