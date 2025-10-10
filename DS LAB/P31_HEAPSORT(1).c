/*Program 29 HEAPSORT
@ALBIN MAMMEN MATHEW
Roll No: 08
Date: 09/08/2025
*/

#include <stdio.h>
#define MAX 100

int heap[MAX], size = 0;
void swap(int i, int j) //function to swap two elements
{
	int temp = heap[i];
	heap[i] = heap[j];
	heap[j] = temp;
}

void heapify(int i, int n) //function to maintain heap property
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && heap[left] > heap[largest])
		largest = left;
	if (right < n && heap[right] > heap[largest])
		largest = right;

	if (largest != i) {
		swap(i, largest);
		heapify(largest, n);
	}
}

void heapSort() //function to perform heap sort
{
	int i;
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(i, size);

	for (i = size - 1; i > 0; i--) {
		swap(0, i);
		heapify(0, i);
	}
}

void display() //function to display the array
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", heap[i]);
	printf("\n");
}

int main()
{
	printf("Enter number of elements: ");
	scanf("%d", &size);

	printf("Enter %d elements:\n", size);
	int i;
	for (i = 0; i < size; i++)
		scanf("%d", &heap[i]);

	printf("Before Heap Sort :\n");
	display();
	heapSort();

	printf("After Heap Sort:\n");
	display();

	return 0;
}

