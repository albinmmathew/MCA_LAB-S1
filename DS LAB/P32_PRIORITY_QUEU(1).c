/*Program 32 PRIORITY QUEUE
@ALBIN MAMMEN MATHEW
Roll No: 08
Date: 10/08/2025
*/


#include <stdio.h>
#define MAX 100

int heap[MAX], size = 0;

void swap(int i, int j)
{
	int temp = heap[i];
	heap[i] = heap[j];
	heap[j] = temp;
}

void heapify(int i, int n)
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

// Insert element into the priority queue
void insert(int value)
{
	if (size == MAX) {
		printf("Priority Queue is Full\n");
		return;
	}

	heap[size] = value;
	int i = size;
	size++;

	// Percolate up to maintain max-heap
	while (i != 0 && heap[(i - 1) / 2] < heap[i])
	{
		swap(i, (i - 1) / 2);
		i = (i - 1) / 2;
	}

	printf("Inserted: %d\n", value);
}

// Delete the element with highest priority (root)
void deleteMax()
{
	if (size <= 0) {
		printf("Priority Queue is Empty\n");
		return;
	}

	int max = heap[0];
	heap[0] = heap[size - 1];
	size--;
	heapify(0, size);

	printf("Deleted: %d\n", max);
}

// Display elements in the heap (priority queue)
void display()
{
	if (size == 0) {
		printf("Priority Queue is Empty\n");
		return;
	}
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", heap[i]);
	printf("\n");
}

int main()
{
	int choice, value;

	do
	{
		printf("\n--- Priority Queue Menu ---\n");
		printf("1. Insert\n2. Delete Max\n3. Display\n4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("Enter element to insert: ");
				scanf("%d", &value);
				insert(value);
				break;
			case 2:
				deleteMax();
				break;
			case 3:
				printf("Priority Queue: ");
				display();
				break;
			case 4:
				printf("Exiting...\n");
				break;
			default:
				printf("Invalid choice\n");
		}

	} while(choice != 4);
	return 0;
}
