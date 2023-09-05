#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define CONFIG_FILE "sorting_config.txt"
// Function to read the sorting configuration from the text file
void readSortingConfig(bool *bubbleSort, bool *quickSort, bool *mergeSort, bool *insertionSort, bool *selectionSort)
{
    FILE *file = fopen(CONFIG_FILE, "r");
    if (file != NULL)
    {
        char techniqueName[50];
        int status;
        // Initialize with default values
        *bubbleSort = true;
        *quickSort = true;
        *mergeSort = true;
        *insertionSort = true;
        *selectionSort = true;
        // Read and update settings from the file
        while (fscanf(file, "%s %d", techniqueName, &status) == 2)
        {
            if (strcmp(techniqueName, "[B]BubbleSort") == 0)
            {
                *bubbleSort = (status == 1);
            }
            else if (strcmp(techniqueName, "[Q]QuickSort") == 0)
            {
                *quickSort = (status == 1);
            }
            else if (strcmp(techniqueName, "[M]MergeSort") == 0)
            {
                *mergeSort = (status == 1);
            }
            else if (strcmp(techniqueName, "[I]InsertionSort") == 0)
            {
                *insertionSort = (status == 1);
            }
            else if (strcmp(techniqueName, "[S]SelectioneSort") == 0)
            {
                *selectionSort = (status == 1);
            }
        }

        fclose(file);
    }
    else
    {
        // If the file doesn't exist, set defaults
        *bubbleSort = true;
        *quickSort = true;
        *mergeSort = true;
        *insertionSort = true;
        *selectionSort = true;
    }
}

// Function to write the sorting configuration to the text file
void writeSortingConfig(bool bubbleSort, bool quickSort, bool mergeSort, bool insertionSort, bool selectionSort)
{
    FILE *file = fopen(CONFIG_FILE, "w");
    if (file != NULL)
    {
        fprintf(file, "[B]BubbleSort %d\n", bubbleSort ? 1 : 0);
        fprintf(file, "[Q]QuickSort %d\n", quickSort ? 1 : 0);
        fprintf(file, "[M]MergeSort %d\n", mergeSort ? 1 : 0);
        fprintf(file, "[I]InsertionSort %d\n", insertionSort ? 1 : 0);
        fprintf(file, "[S]SelectionSort %d\n", selectionSort ? 1 : 0);
        fclose(file);
    }
}

int main()
{

    char adminPassword[] = "adminpass"; // Define the admin password

    char inputPassword[20]; // Buffer to store user input
    printf("Enter the admin password: ");
    scanf("%s", inputPassword);

    // Compare the entered password with the admin password
    if (strcmp(inputPassword, adminPassword) == 0)
    {
        printf("Admin mode activated!\n");
    }
    else
    {
        printf("Invalid password. Access denied.\n");
        return 0;
    }

    bool bubbleSort, quickSort, mergeSort, insertionSort, selectionSort;

    // Read the current sorting configuration
    readSortingConfig(&bubbleSort, &quickSort, &mergeSort, &insertionSort, &selectionSort);

    int choice;
    do
    {
        printf("Admin Menu:\n");
        printf("1. Bubble Sort [%s]\n", bubbleSort ? "Enabled" : "Disabled");
        printf("2. Quick Sort [%s]\n", quickSort ? "Enabled" : "Disabled");
        printf("3. Merge Sort [%s]\n", mergeSort ? "Enabled" : "Disabled");
        printf("4. Insertion Sort [%s]\n", insertionSort ? "Enabled" : "Disabled");
        printf("5. Selection Sort [%s]\n", selectionSort ? "Enabled" : "Disabled");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            bubbleSort = !bubbleSort;
            writeSortingConfig(bubbleSort, quickSort, mergeSort, insertionSort, selectionSort);
            printf("[B]Bubble Sort %s.\n", bubbleSort ? "enabled" : "disabled");
            break;
        case 2:
            quickSort = !quickSort;
            writeSortingConfig(bubbleSort, quickSort, mergeSort, insertionSort, selectionSort);
            printf("[Q]Quick Sort %s.\n", quickSort ? "enabled" : "disabled");
            break;
        case 3:
            mergeSort = !mergeSort;
            writeSortingConfig(bubbleSort, quickSort, mergeSort, insertionSort, selectionSort);
            printf("[M]Merge Sort %s.\n", mergeSort ? "enabled" : "disabled");
            break;
        case 4:
            insertionSort = !insertionSort;
            writeSortingConfig(bubbleSort, quickSort, mergeSort, insertionSort, selectionSort);
            printf("[I]Insertion Sort Sort %s.\n", insertionSort ? "enabled" : "disabled");
            break;
        case 5:
            selectionSort = !selectionSort;
            writeSortingConfig(bubbleSort, quickSort, mergeSort, insertionSort, selectionSort);
            printf("[S]Selection Sort %s.\n", selectionSort ? "enabled" : "disabled");
            break;
        case 6:
            printf("Exiting admin program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
