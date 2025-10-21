/*PROGRAM 55 OPERATIONS ON DOUBLY LINKED LIST
@ALBIN MAMMEN MATHEW
Roll No: 08
01/10/2025
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *prev;
	struct Node *next;
};

struct Node *head = NULL;

// Function to insert at the beginning
void insertBegin(int value) {
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->prev = NULL;
	newNode->next = head;

	if (head != NULL)
		head->prev = newNode;
	head = newNode;

	printf("%d inserted at the beginning.\n", value);
}

// Function to insert at the end
void insertEnd(int value) {
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = NULL;

	if (head == NULL) {
		newNode->prev = NULL;
		head = newNode;
	} else {
		struct Node *temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newNode;
		newNode->prev = temp;
	}

	printf("%d inserted at the end.\n", value);
}

// Function to delete a node by value
void deleteNode(int value) {
	if (head == NULL) {
		printf("List is empty!\n");
		return;
	}

	struct Node *temp = head;

	while (temp != NULL && temp->data != value)
		temp = temp->next;

	if (temp == NULL) {
		printf("%d not found in the list.\n", value);
		return;
	}

	if (temp->prev != NULL)
		temp->prev->next = temp->next;
	else
		head = temp->next;

	if (temp->next != NULL)
		temp->next->prev = temp->prev;

	free(temp);
	printf("%d deleted from the list.\n", value);
}

// Function to display list from beginning
void displayForward() {
	if (head == NULL) {
		printf("List is empty.\n");
		return;
	}

	struct Node *temp = head;
	printf("Doubly Linked List (Forward): ");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

// Function to display list in reverse order
void displayBackward() {
	if (head == NULL) {
		printf("List is empty.\n");
		return;
	}

	struct Node *temp = head;
	while (temp->next != NULL)
		temp = temp->next;

	printf("Doubly Linked List (Backward): ");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

// Function to display menu and return choice
int menu() {
	int choice;
	printf("\n--- Doubly Linked List Operations ---\n");
	printf("1. Insert at Beginning\n");
	printf("2. Insert at End\n");
	printf("3. Delete\n");
	printf("4. Display Forward\n");
	printf("5. Display Backward\n");
	printf("6. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	return choice;
}

// Function to process doubly linked list operations
void processDoublyLinkedList() {
	int choice, value;
	while (1) {
		choice = menu();
		switch (choice) {
			case 1:
				printf("Enter value: ");
				scanf("%d", &value);
				insertBegin(value);
				break;
			case 2:
				printf("Enter value: ");
				scanf("%d", &value);
				insertEnd(value);
				break;
			case 3:
				printf("Enter value to delete: ");
				scanf("%d", &value);
				deleteNode(value);
				break;
			case 4:
				displayForward();
				break;
			case 5:
				displayBackward();
				break;
			case 6:
				printf("Exiting program.\n");
				exit(0);
			default:
				printf("Invalid choice! Try again.\n");
		}
	}
}

int main() {
	processDoublyLinkedList();
	return 0;
}
