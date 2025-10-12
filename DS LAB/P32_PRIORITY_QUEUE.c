/*Program 32 PRIORITY QUEUE
@ALBIN MAMMEN MATHEW
Roll No: 08
Date: 10/08/2025
*/

#include <stdio.h>
#define SIZE 5  // Maximum size of the queue

int values[SIZE];      // Array for values
int priorities[SIZE];  // Array for priorities
int count = 0;         // Number of elements in the queue

// Function to insert (enqueue) an element with priority
void enqueue(int value, int priority) {
	if (count == SIZE) {
		printf("Queue is Full! (Overflow)\n");
		return;
	}

	values[count] = value;
	priorities[count] = priority;
	count++;
	printf("Inserted value %d with priority %d\n", value, priority);
}

// Function to find index of highest priority element
int findHighestPriorityIndex() {
	int highest = 0;
	int i;
	for (i = 1; i < count; i++) {
		if (priorities[i] > priorities[highest]) {
			highest = i;
		}
		// If priorities are equal, the one inserted earlier stays first
	}
	return highest;
}

// Function to delete (dequeue) the highest priority element
void dequeue() {
	if (count == 0) {
		printf("Queue is Empty! (Underflow)\n");
		return;
	}

	int index = findHighestPriorityIndex();
	printf("Deleted value %d with priority %d\n", values[index], priorities[index]);

	// Shift remaining elements
	int i;
	for (i = index; i < count - 1; i++) {
		values[i] = values[i + 1];
		priorities[i] = priorities[i + 1];
	}
	count--;
}

// Function to display all elements in the queue
void display() {
	if (count == 0) {
		printf("Queue is Empty!\n");
		return;
	}

	printf("Priority Queue elements:\n");
	int i;
	for (i = 0; i < count; i++) {
		printf("Value: %d | Priority: %d\n", values[i], priorities[i]);
	}
}

int menu() {
	int ch;
	printf("\nMenu:\n");
	printf("1. Enqueue (Insert)\n");
	printf("2. Dequeue (Delete Highest Priority)\n");
	printf("3. Display\n");
	printf("4. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &ch);
	return ch;
}

void processQueue() {
	int ch, value, priority;
	for (ch = menu(); ch != 4; ch = menu()) {
		switch (ch) {
			case 1:
				printf("Enter value: ");
				scanf("%d", &value);
				printf("Enter priority (higher number = higher priority): ");
				scanf("%d", &priority);
				enqueue(value, priority);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			default:
				printf("Invalid choice! Try again.\n");
		}
	}
}

int main() {
	printf("Priority Queue Implementation using Array\n");
	processQueue();
	return 0;
}
