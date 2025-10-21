/*PROGRAM 66 ADJACENCY MATRIX USING LINKED LISTS
@ALBIN MAMMEN MATHEW
Roll No: 08
18/10/2025
*/

#include <stdio.h>
#include <stdlib.h>

// Structure Definition
struct Node {
	int data;
	struct Node* right;  // pointer to next column node
	struct Node* down;   // pointer to next row node
};

// Function Prototypes
struct Node* newNode(int data);
struct Node* createLinkedMatrix(int mat[][10], int n);
void displayMatrix(struct Node* head);
void freeMatrix(struct Node* head);

// Function Implementations

// Create a new node
struct Node* newNode(int data) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->right = NULL;
	temp->down = NULL;
	return temp;
}

// Create linked matrix representation from a 2D array
struct Node* createLinkedMatrix(int mat[][10], int n) {
	struct Node* head = NULL;
	struct Node* prevRowStart = NULL; // first node of previous row
	struct Node* currRowStart = NULL; // first node of current row
	struct Node* prev = NULL;

	for (int i = 0; i < n; i++) {
		prev = NULL;
		for (int j = 0; j < n; j++) {
			// Create new node
			struct Node* newnode = newNode(mat[i][j]);

			if (head == NULL)
				head = newnode; // first node of matrix

			if (prev == NULL)
				currRowStart = newnode;
			else
				prev->right = newnode; // link nodes in the same row

			// Link vertically with previous row
			if (prevRowStart != NULL) {
				struct Node* temp = prevRowStart;
				for (int k = 0; k < j; k++)
					temp = temp->right;
				temp->down = newnode;
			}

			prev = newnode;
		}
		prevRowStart = currRowStart;
	}
	return head;
}

// Display the linked matrix
void displayMatrix(struct Node* head) {
	struct Node* row = head;
	while (row != NULL) {
		struct Node* col = row;
		while (col != NULL) {
			printf("%d ", col->data);
			col = col->right;
		}
		printf("\n");
		row = row->down;
	}
}

// Free the allocated memory
void freeMatrix(struct Node* head) {
	struct Node* row = head;
	while (row != NULL) {
		struct Node* col = row;
		struct Node* nextRow = row->down;
		while (col != NULL) {
			struct Node* temp = col;
			col = col->right;
			free(temp);
		}
		row = nextRow;
	}
}

int main() {
	int n;
	int mat[10][10];

	printf("Enter number of vertices: ");
	scanf("%d", &n);

	printf("Enter adjacency matrix (%d x %d):\n", n, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &mat[i][j]);
		}
	}

	struct Node* head = createLinkedMatrix(mat, n);

	printf("\nAdjacency Matrix represented using Linked Lists:\n");
	displayMatrix(head);

	freeMatrix(head);
	return 0;
}
