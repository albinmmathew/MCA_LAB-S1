/*PROGRAM 53 OPERATIONS ON CIRCULAR LINKED LIST
@ALBIN MAMMEN MATHEW
Roll No: 08 
30/09/2025
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node *last = NULL;

// Function to insert at the end
void insertEnd(int value) {
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = value;

	if (last == NULL) {
		newNode->next = newNode;
		last = newNode;
	} else {
		newNode->next = last->next;
		last->next = newNode;
		last = newNode;
	}
	printf("%d inserted at the end.\n", value);
}

// Function to insert at the beginning
void insertBegin(int value) {
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = value;

	if (last == NULL) {
		newNode->next = newNode;
		last = newNode;
	} else {
		newNode->next = last->next;
		last->next = newNode;
	}
	printf("%d inserted at the beginning.\n", value);
}

// Function to delete a node
void deleteNode(int value) {
	if (last == NULL) {
		printf("List is empty!\n");
		return;
	}

	struct Node *temp = last->next;
	struct Node *prev = last;

	// Single node case
	if (last == last->next && last->data == value) {
		free(last);
		last = NULL;
		printf("%d deleted.\n", value);
		return;
	}

	// Traverse to find node
	do {
		if (temp->data == value) {
			prev->next = temp->next;
			if (temp == last)
				last = prev;
			free(temp);
			printf("%d deleted.\n", value);
			return;
		}
		prev = temp;
		temp = temp->next;
	} while (temp != last->next);

	printf("Element %d not found!\n", value);
}

// Function to display the circular linked list
void display() {
	if (last == NULL) {
		printf("List is empty.\n");
		return;
	}

	struct Node *temp = last->next;
	printf("Circular Linked List: ");
	do {
		printf("%d ", temp->data);
		temp = temp->next;
	} while (temp != last->next);
	printf("\n");
}

// Function to display menu and return choice
int menu() {
	int choice;
	printf("\n--- Circular Linked List Operations ---\n");
	printf("1. Insert at Beginning\n");
	printf("2. Insert at End\n");
	printf("3. Delete\n");
	printf("4. Display\n");
	printf("5. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	return choice;
}

// Function to process circular linked list operations
void processCircularList() {
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
				display();
				break;
			case 5:
				printf("Exiting program.\n");
				exit(0);
			default:
				printf("Invalid choice! Try again.\n");
		}
	}
}

int main() {
	processCircularList();
	return 0;
}
