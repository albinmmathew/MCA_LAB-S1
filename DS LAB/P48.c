/* PROGRAM 48: LINKED LIST SORTING -> BY VALUES || BY ADDRESS
@ALBIN MAMMEN MATHEW
Roll No: 08
19/09/2025
*/

#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
	int data;
	struct Node *next;
};

// Function to create a linked list
struct Node* createList(int n) {
	struct Node *head = NULL, *temp, *newNode;
	int val;

	for (int i = 0; i < n; i++) {
		newNode = (struct Node*)malloc(sizeof(struct Node));
		printf("Enter value for node %d: ", i + 1);
		scanf("%d", &val);
		newNode->data = val;
		newNode->next = NULL;

		if (head == NULL)
			head = newNode;
		else {
			temp = head;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = newNode;
		}
	}
	return head;
}

// Function to display the linked list
void displayList(struct Node *head) {
	struct Node *temp = head;
	printf("List: ");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

// a) Sort by swapping values
void sortByValue(struct Node *head) {
	struct Node *i, *j;
	int temp;

	for (i = head; i != NULL; i = i->next) {
		for (j = i->next; j != NULL; j = j->next) {
			if (i->data > j->data) {
				temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
	}
}

// b) Sort by swapping links (addresses)
struct Node* sortByAddress(struct Node *head) {
	struct Node *i, *j, *prev, *temp;
	int swapped;

	if (head == NULL)
		return head;

	do {
		swapped = 0;
		i = head;
		prev = NULL;

		while (i->next != NULL) {
			j = i->next;
			if (i->data > j->data) {
				swapped = 1;
				// Swap the nodes (not just data)
				if (prev == NULL) {
					i->next = j->next;
					j->next = i;
					head = j;
					prev = j;
				} else {
					prev->next = j;
					i->next = j->next;
					j->next = i;
					prev = j;
				}
			} else {
				prev = i;
				i = i->next;
			}
		}
	} while (swapped);

	return head;
}

int main() {
	struct Node *head = NULL;
	int n;

	printf("Enter number of nodes: ");
	scanf("%d", &n);

	head = createList(n);
	printf("\nOriginal Linked List:\n");
	displayList(head);

	// Sorting by swapping values
	sortByValue(head);
	printf("\nLinked List after sorting by values:\n");
	displayList(head);

	// Sorting by swapping addresses
	head = sortByAddress(head);
	printf("\nLinked List after sorting by addresses:\n");
	displayList(head);

	// Free memory
	struct Node *temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
	printf("\nMemory freed successfully.\n");

	return 0;
}
