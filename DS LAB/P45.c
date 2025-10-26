/* PROGRAM 45: LINKED LIST INSERTION
@ALBIN MAMMEN MATHEW
Roll No: 08
18/09/2025
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
	int data;
	struct Node *next;
};

// Function to create initial linked list with n nodes
struct Node* createLinkedList(int n) {
	struct Node *head = NULL, *temp = NULL, *newNode = NULL;
	int value,i;

	for (i = 0; i < n; i++) {
		newNode = (struct Node *)malloc(sizeof(struct Node));
		printf("Enter value for node %d: ", i + 1);
		scanf("%d", &value);
		newNode->data = value;
		newNode->next = NULL;

		if (head == NULL) {
			head = newNode;
			temp = head;
		} else {
			temp->next = newNode;
			temp = newNode;
		}
	}

	return head;
}

// Function to insert at beginning
struct Node* insertAtBeginning(struct Node *head, int value) {
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = head;
	head = newNode;
	return head;
}

// Function to insert at end
struct Node* insertAtEnd(struct Node *head, int value) {
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = NULL;

	if (head == NULL) {
		return newNode;
	}

	struct Node *temp = head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = newNode;
	return head;
}

// Function to insert after a specified element
struct Node* insertAfterElement(struct Node *head, int element, int value) {
	struct Node *temp = head;

	while (temp != NULL && temp->data != element)
		temp = temp->next;

	if (temp == NULL) {
		printf("Element %d not found in the list.\n", element);
		return head;
	}

	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = temp->next;
	temp->next = newNode;

	return head;
}

// Function to display linked list
void displayLinkedList(struct Node *head) {
	struct Node *temp = head;
	printf("\nLinked List: ");
	while (temp != NULL) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

// Function to free linked list memory
void freeLinkedList(struct Node *head) {
	struct Node *temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
	printf("Memory freed successfully.\n");
}

int main() {
	int n, value, element;
	struct Node *head = NULL;

	printf("Enter number of nodes to create initially: ");
	scanf("%d", &n);

	head = createLinkedList(n);
	displayLinkedList(head);

	// Insert at beginning
	printf("\nEnter value to insert at beginning: ");
	scanf("%d", &value);
	head = insertAtBeginning(head, value);
	displayLinkedList(head);

	// Insert at end
	printf("\nEnter value to insert at end: ");
	scanf("%d", &value);
	head = insertAtEnd(head, value);
	displayLinkedList(head);

	// Insert after a specified element
	printf("\nEnter element after which to insert: ");
	scanf("%d", &element);
	printf("Enter value to insert after %d: ", element);
	scanf("%d", &value);
	head = insertAfterElement(head, element, value);
	displayLinkedList(head);

	freeLinkedList(head);

	return 0;
}
