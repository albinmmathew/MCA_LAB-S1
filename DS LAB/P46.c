/* PROGRAM 46: LINKED LIST DELETION
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

// Function to delete from beginning
struct Node* deleteFromBeginning(struct Node *head) {
	if (head == NULL) {
		printf("List is empty.\n");
		return NULL;
	}
	struct Node *temp = head;
	head = head->next;
	free(temp);
	return head;
}

// Function to delete from end
struct Node* deleteFromEnd(struct Node *head) {
	if (head == NULL) {
		printf("List is empty.\n");
		return NULL;
	}
	if (head->next == NULL) {
		free(head);
		return NULL;
	}
	struct Node *temp = head;
	while (temp->next->next != NULL)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
	return head;
}

// Function to delete node with specified value
struct Node* deleteNodeWithValue(struct Node *head, int value) {
	if (head == NULL) {
		printf("List is empty.\n");
		return NULL;
	}

	if (head->data == value) {
		struct Node *temp = head;
		head = head->next;
		free(temp);
		return head;
	}

	struct Node *temp = head;
	while (temp->next != NULL && temp->next->data != value)
		temp = temp->next;

	if (temp->next == NULL) {
		printf("Element %d not found in the list.\n", value);
		return head;
	}

	struct Node *del = temp->next;
	temp->next = del->next;
	free(del);

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
	int n, value;
	struct Node *head = NULL;

	printf("Enter number of nodes to create initially: ");
	scanf("%d", &n);

	head = createLinkedList(n);
	displayLinkedList(head);

	// Delete from beginning
	printf("\nDeleting node from beginning...\n");
	head = deleteFromBeginning(head);
	displayLinkedList(head);

	// Delete from end
	printf("\nDeleting node from end...\n");
	head = deleteFromEnd(head);
	displayLinkedList(head);

	// Delete node with specified value
	printf("\nEnter value of node to delete: ");
	scanf("%d", &value);
	head = deleteNodeWithValue(head, value);
	displayLinkedList(head);

	freeLinkedList(head);

	return 0;
}
