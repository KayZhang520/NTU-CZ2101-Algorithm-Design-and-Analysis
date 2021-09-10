#include <stdio.h>

void swap(int arr[], int i, int largest){
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left child
	int r = 2 * i + 2; // right child

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr, i, largest); //swap the child's value with that of i's

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
	//n/2 - 1 gives exactly the index of the parent of the rightmost leaf.
	for (int i = n/2 - 1; i >= 0; i--)
    {
        printf("calling heapify on index: %i\n", i);
		heapify(arr, n, i);
    }
	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--) {
		// Move current root to end
		swap(arr, 0, i);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		printf("%i ", arr[i]);
}

int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 , 10, 9, 8, 4, 3, 2, 1000};
	int n = 13;

	heapSort(arr, n);
	printArray(arr, n);
}
