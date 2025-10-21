/*PROGRAM 52 OPERATIONS ON LINKED QUEUE
@ALBIN MAMMEN MATHEW
Roll No: 08
27/09/2025
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

	if (rear == NULL) {
		front = rear = newNode;
	} else {
		rear->next = newNode;
		rear = newNode;
	}
	printf("%d inserted into queue.\n", value);
}

// Function to delete (dequeue) an element
void dequeue() {
	if (front == NULL) {
		printf("Queue Underflow!\n");
		return;
	}
	struct Node *temp = front;
	printf("Deleted element: %d\n", front->data);
	front = front->next;
	if (front == NULL)
		rear = NULL;
	free(temp);
}

// Function to display queue elements
void display() {
	if (front == NULL) {
		printf("Queue is empty.\n");
		return;
	}
	struct Node *temp = front;
	printf("Queue elements: ");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

// Function to display menu and return choice
int menu() {
	int choice;
	printf("\n--- Linked Queue Operations ---\n");
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Display\n");
	printf("4. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	return choice;
}

// Function to process queue operations
void processQueue() {
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
	processQueue();
	return 0;
}
