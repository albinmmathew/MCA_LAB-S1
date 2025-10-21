/* PROGRAM 44: LINKED LIST CREATION AND DISPLAY
@ALBIN MAMMEN MATHEW
Roll No: 08
18/09/2025
*/

#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
	int data;
	struct Node *next;
};

// Function to create a linked list of n nodes
struct Node* createLinkedList(int n) {
	struct Node *head = NULL, *temp = NULL, *newNode = NULL;
	int value;

	for (int i = 0; i < n; i++) {
		newNode = (struct Node *)malloc(sizeof(struct Node));
		if (newNode == NULL) {
			printf("Memory not allocated.\n");
			exit(1);
		}

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

// Function to free memory of linked list
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
	struct Node *head;

	printf("Enter number of nodes: ");
	scanf("%d", &n);

	head = createLinkedList(n);		// Step 1: Create linked list
	displayLinkedList(head);		// Step 2: Display linked list
	freeLinkedList(head);			// Step 3: Free memory

	return 0;
}
