/* PROGRAM 49: POLYNOMIAL ADDITION AND MULTIPLICATION USING LINKED LIST
@ALBIN MAMMEN MATHEW
Roll No: 08
19/09/2025
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a polynomial term
struct Node {
	int coeff;				// coefficient
	int power;				// power of x
	struct Node *next;
};

// Function to create a new node
struct Node* createNode(int coeff, int power) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->coeff = coeff;
	newNode->power = power;
	newNode->next = NULL;
	return newNode;
}

// Function to insert a node into the polynomial (sorted by power)
struct Node* insertNode(struct Node* head, int coeff, int power) {
	struct Node* newNode = createNode(coeff, power);

	if (head == NULL || head->power < power) {
		newNode->next = head;
		return newNode;
	}

	struct Node* temp = head;
	while (temp->next != NULL && temp->next->power >= power)
		temp = temp->next;

	if (temp->power == power) {
		temp->coeff += coeff; // Combine like terms
		free(newNode);
	} else {
		newNode->next = temp->next;
		temp->next = newNode;
	}

	return head;
}

// Function to display a polynomial
void display(struct Node* head) {
	if (head == NULL) {
		printf("0");
		return;
	}

	struct Node* temp = head;
	while (temp != NULL) {
		printf("%dx^%d", temp->coeff, temp->power);
		if (temp->next != NULL && temp->next->coeff >= 0)
			printf(" + ");
		temp = temp->next;
	}
	printf("\n");
}

// Function to add two polynomials
struct Node* addPoly(struct Node* p1, struct Node* p2) {
	struct Node* result = NULL;

	while (p1 != NULL || p2 != NULL) {
		if (p1 == NULL) {
			result = insertNode(result, p2->coeff, p2->power);
			p2 = p2->next;
		} else if (p2 == NULL) {
			result = insertNode(result, p1->coeff, p1->power);
			p1 = p1->next;
		} else if (p1->power > p2->power) {
			result = insertNode(result, p1->coeff, p1->power);
			p1 = p1->next;
		} else if (p1->power < p2->power) {
			result = insertNode(result, p2->coeff, p2->power);
			p2 = p2->next;
		} else {
			result = insertNode(result, p1->coeff + p2->coeff, p1->power);
			p1 = p1->next;
			p2 = p2->next;
		}
	}

	return result;
}

// Function to multiply two polynomials
struct Node* multiplyPoly(struct Node* p1, struct Node* p2) {
	struct Node* result = NULL;

	for (struct Node* i = p1; i != NULL; i = i->next) {
		for (struct Node* j = p2; j != NULL; j = j->next) {
			int coeff = i->coeff * j->coeff;
			int power = i->power + j->power;
			result = insertNode(result, coeff, power);
		}
	}

	return result;
}

// Function to free the linked list
void freePoly(struct Node* head) {
	struct Node* temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
}

int main() {
	struct Node *poly1 = NULL, *poly2 = NULL, *sum = NULL, *product = NULL;
	int n, coeff, power;

	printf("Enter number of terms in 1st polynomial: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("Enter coefficient and power: ");
		scanf("%d %d", &coeff, &power);
		poly1 = insertNode(poly1, coeff, power);
	}

	printf("Enter number of terms in 2nd polynomial: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("Enter coefficient and power: ");
		scanf("%d %d", &coeff, &power);
		poly2 = insertNode(poly2, coeff, power);
	}

	printf("\nFirst Polynomial: ");
	display(poly1);
	printf("Second Polynomial: ");
	display(poly2);

	// Addition
	sum = addPoly(poly1, poly2);
	printf("\nSum = ");
	display(sum);

	// Multiplication
	product = multiplyPoly(poly1, poly2);
	printf("Product = ");
	display(product);

	// Free memory
	freePoly(poly1);
	freePoly(poly2);
	freePoly(sum);
	freePoly(product);

	printf("\nMemory freed successfully.\n");

	return 0;
}
