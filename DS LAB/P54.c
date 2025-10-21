/*PROGRAM 54 OPERATIONS ON CIRCULAR LINKED QUEUE
@ALBIN MAMMEN MATHEW
Roll No: 08
01/10/2025
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Function to insert (enqueue) an element
void enqueue(int value) {
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = NULL;

	if (front == NULL) {
		front = rear = newNode;
		rear->next = front; // circular link
	} else {
		rear->next = newNode;
		rear = newNode;
		rear->next = front;
	}
	printf("%d inserted into Circular Queue.\n", value);
}

// Function to delete (dequeue) an element
void dequeue() {
	if (front == NULL) {
		printf("Queue Underflow!\n");
		return;
	}

	struct Node *temp = front;
	int value = temp->data;

	// Single element case
	if (front == rear) {
		front = rear = NULL;
	} else {
		front = front->next;
		rear->next = front;
	}

	free(temp);
	printf("%d deleted from Circular Queue.\n", value);
}

// Function to display the circular queue
void display() {
	if (front == NULL) {
		printf("Queue is empty.\n");
		return;
	}

	struct Node *temp = front;
	printf("Circular Queue elements: ");
	do {
		printf("%d ", temp->data);
		temp = temp->next;
	} while (temp != front);
	printf("\n");
}

// Function to display menu and return choice
int menu() {
	int choice;
	printf("\n--- Circular Linked Queue Operations ---\n");
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Display\n");
	printf("4. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	return choice;
}

// Function to process circular queue operations
void processCircularQueue() {
	int choice, value;
	while (1) {
		choice = menu();
		switch (choice) {
			case 1:
				printf("Enter value to insert: ");
				scanf("%d", &value);
				enqueue(value);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Exiting program.\n");
				exit(0);
			default:
				printf("Invalid choice! Try again.\n");
		}
	}
}

int main() {
	processCircularQueue();
	return 0;
}
