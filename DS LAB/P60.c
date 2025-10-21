/*PROGRAM 60 BINARY SEARCH TREE INSERTION AND DISPLAY TRAVERSAL USING INORDER, PREORDER, POSTORDER WITH RECURSION
@ALBIN MAMMEN MATHEW
Roll No: 08
17/10/2025
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
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

// Recursive inorder traversal
void inorder(struct Node* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

// Recursive preorder traversal
void preorder(struct Node* root) {
	if (root != NULL) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

// Recursive postorder traversal
void postorder(struct Node* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
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

	printf("\nInorder Traversal: ");
	inorder(root);

	printf("\nPreorder Traversal: ");
	preorder(root);

	printf("\nPostorder Traversal: ");
	postorder(root);

	printf("\n");
	return 0;
}
