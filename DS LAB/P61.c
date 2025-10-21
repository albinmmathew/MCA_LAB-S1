/*PROGRAM 61 BINARY SEARCH TREE INSERTION AND DISPLAY TRAVERSAL USING INORDER WITHOUT RECURSION
@ALBIN MAMMEN MATHEW
Roll No: 08
17/10/2025
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the BST
struct Node {
	int data;
	struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// Function to insert a node into BST
struct Node* insert(struct Node* root, int value) {
	if (root == NULL)
		return createNode(value);
	if (value < root->data)
		root->left = insert(root->left, value);
	else if (value > root->data)
		root->right = insert(root->right, value);
	return root;
}

// Inorder traversal without recursion using stack
void inorderNonRecursive(struct Node* root) {
	struct Node* stack[100];
	int top = -1;
	struct Node* current = root;

	while (current != NULL || top != -1) {
		while (current != NULL) {
			stack[++top] = current;
			current = current->left;
		}
		current = stack[top--];
		printf("%d ", current->data);
		current = current->right;
	}
}

int main() {
	struct Node* root = NULL;
	int n, value;

	printf("Enter number of nodes: ");
	scanf("%d", &n);

	printf("Enter %d values:\n", n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &value);
		root = insert(root, value);
	}

	printf("\nInorder Traversal (Without Recursion): ");
	inorderNonRecursive(root);

	printf("\n");
	return 0;
}
