#include <stdio.h>

// Function to perform insertion sort on an array of integers
void insertionSort(int arr[], int n)
{
    // Loop through the array, starting from the second element (index 1)
    for (int i = 1; i < n; i++)
    {
        int key = arr[i]; // Store the current element as the key
        int j = i - 1;    // Initialize the index of the previous element

        // Move elements of arr[0..i-1] that are greater than the key to one position ahead of their current position
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j]; // Shift the element to the right
            j--;                 // Move one position to the left
        }

        arr[j + 1] = key; // Place the key in its correct position
    }
}

// Main function
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Check if the input is valid
    if (n <= 0)
    {
        printf("Please enter a valid positive integer.\n");
        return 1; // Return an error code
    }

    int arr[n]; // Declare an array of integers with size n

    // Input elements from the user
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Display the original array
    printf("Original array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Call the insertionSort function to sort the array
    insertionSort(arr, n);

    // Display the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0; // Return 0 to indicate successful execution
}
