/*PROGRAM 64 BINARY SEARCH TREE INSERTION USING NAMES AND DISPLAY USING INORDER
@ALBIN MAMMEN MATHEW
Roll No: 08
17/10/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node with a name
struct Node {
	char name[50];
	struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(char name[]) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	strcpy(newNode->name, name);
	newNode->left = newNode->right = NULL;
	return newNode;
}

// Function to insert a name into the BST
struct Node* insert(struct Node* root, char name[]) {
	if (root == NULL)
		return createNode(name);

	if (strcmp(name, root->name) < 0)
		root->left = insert(root->left, name);
	else if (strcmp(name, root->name) > 0)
		root->right = insert(root->right, name);

	return root;
}

// Inorder traversal to display names in ascending order
void inorder(struct Node* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%s\n", root->name);
		inorder(root->right);
	}
}

int main() {
	struct Node* root = NULL;
	int i, n;
	char name[50];

	printf("Enter number of names: ");
	scanf("%d", &n);

	printf("Enter %d names:\n", n);
	for (i = 0; i < n; i++) {
		scanf("%s", name);
		root = insert(root, name);
	}

	printf("\nNames in Ascending Order:\n");
	inorder(root);

	return 0;
}
