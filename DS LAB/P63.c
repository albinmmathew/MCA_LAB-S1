/*PROGRAM 63 BINARY SEARCH TREE INSERTION AND DISPLAY TRAVERSAL USING POSTORDER WITHOUT RECURSION
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

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int value) {
	if (root == NULL)
		return createNode(value);
	if (value < root->data)
		root->left = insert(root->left, value);
	else if (value > root->data)
		root->right = insert(root->right, value);
	return root;
}

// Postorder traversal without recursion using two stacks
void postorderNonRecursive(struct Node* root) {
	if (root == NULL)
		return;

	struct Node* stack1[100];
	struct Node* stack2[100];
	int top1 = -1, top2 = -1;

	stack1[++top1] = root;

	while (top1 != -1) {
		struct Node* current = stack1[top1--];
		stack2[++top2] = current;

		if (current->left)
			stack1[++top1] = current->left;
		if (current->right)
			stack1[++top1] = current->right;
	}

	while (top2 != -1)
		printf("%d ", stack2[top2--]->data);
}

int main() {
	struct Node* root = NULL;
	int n, i, value;

	printf("Enter number of nodes: ");
	scanf("%d", &n);

	printf("Enter %d values:\n", n);
	for (i = 0; i < n; i++) {
		scanf("%d", &value);
		root = insert(root, value);
	}

	printf("\nPostorder Traversal (Without Recursion): ");
	postorderNonRecursive(root);

	printf("\n");
	return 0;
}
