/* PROGRAM 47: LINKED LIST - REVERSE
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

// Function to create linked list
struct Node* createLinkedList(int n) {
	struct Node *head = NULL, *temp = NULL, *newNode = NULL;
	int value;

	for (int i = 0; i < n; i++) {
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

// Function to display linked list in forward order
void displayLinkedList(struct Node *head) {
	struct Node *temp = head;
	printf("\nLinked List: ");
	while (temp != NULL) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

// Function to display linked list in reverse order using recursion
void displayReverse(struct Node *head) {
	if (head == NULL)
		return;
	displayReverse(head->next);
	printf("%d -> ", head->data);
}

// Function to free linked list
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
	int n;
	struct Node *head = NULL;

	printf("Enter number of nodes: ");
	scanf("%d", &n);

	head = createLinkedList(n);
	displayLinkedList(head);

	printf("\nLinked List in Reverse Order: ");
	displayReverse(head);
	printf("NULL\n");

	freeLinkedList(head);

	return 0;
}
