#include<stdio.h>
//Function declaration
void SelectionSort(int arr[],int n);         //Declare Seelection sort fuction
int main()
{
	int arr[100],n,i;                        //Declare
//Input the numer of elements 
	printf("Enter the number of elements\n"); 
	scanf("%d", &n);                         //Read an interger and store in 'n'
//Input the array elements
	printf("Enter %d numbers\n",n); 
	for(i=0;i<n;i++)
		scanf("%d", &arr[i]);                //Read an integers and store in 'arr'
//Call the Selection sort function to sort the array
		SelectionSort(arr,n);               //Call the sorting function
	return 0;
}
//Selection sort function to sort an array using selection sort algorithm
void SelectionSort(int arr[], int n)           //Declare
{
	int i,j,position,swap;
//Iterate through array
	for(i=0; i<(n-1); i++)                    //Outer loop for selecting the min element
	{
		position=i;                          //Initialize 'position' as current index
//Find the minimum element in unsorted portion of array
		for(j=i+1; j<n; j++)                 //Inner loop to find min
		{
			if(arr[position]>arr[j])         // Compare current min with current element
				position=j;                 // Update 'position' if a smaller element is found
		}
//Swap the min element with the first element of the unsorted portion
		if(position != i)                   // Check if swapping is needed
		{
			swap = arr[i];                 //store the current element in swap
			arr[i] = arr[position];        //Replace current element with min
			arr[position] = swap;          // Put the stored element in the minimum position
		}
	}
// Print the sorted array
	printf("--------SELECTION SORT--------\n"); 
	printf("\n");
	printf("Sorted List using Selection Sort is:\n");
	for(i=0;i<n;i++)                       // Loop to print each element
		printf("%d\n", arr[i]);           //Print current element
}
