/*PROGRAM 51 OPERATIONS ON LINKED STACK
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

struct Node *top = NULL;

// Function to push element onto the stack
void push(int value) {
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = top;
	top = newNode;
	printf("Pushed %d onto stack.\n", value);
}

// Function to pop element from the stack
void pop() {
	if (top == NULL)
		printf("Stack Underflow!\n");
	else {
		struct Node *temp = top;
		printf("Popped %d from stack.\n", top->data);
		top = top->next;
		free(temp);
	}
}

// Function to display stack elements
void display() {
	if (top == NULL)
		printf("Stack is empty.\n");
	else {
		struct Node *temp = top;
		printf("Stack elements: ");
		while (temp != NULL) {
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

// Function to display menu and get user choice
int menu() {
	int choice;
	printf("\n--- Linked Stack Operations ---\n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Display\n");
	printf("4. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	return choice;
}

// Function to process stack operations
void processStack() {
	int choice, value;
	while (1) {
		choice = menu();
		switch (choice) {
			case 1:
				printf("Enter value to push: ");
				scanf("%d", &value);
				push(value);
				break;
			case 2:
				pop();
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
	processStack();
	return 0;
}
