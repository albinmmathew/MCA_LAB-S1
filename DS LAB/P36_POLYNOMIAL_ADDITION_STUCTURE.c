/* PROGRAM 36: POLYNOMIAL ADDITION USING STRUCTURE ARRAY
@ALBIN MAMMEN MATHEW
15/10/2025
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int coeff;
	int expo;
} poly;

poly a[10], b[10], add[10];
int n1, n2, nr;

// Function to display a polynomial
void display(poly p[], int *n) {
	int i;
	for (i = 0; i < *n; i++) {
		int c = p[i].coeff;
		int e = p[i].expo;

		if (c == 0)
			continue; // Skip zero coefficient terms

		// Sign printing
		if (i != 0) {
			if (c > 0)
				printf("+");
			else
				printf("-");
		} else {
			if (c < 0)
				printf("-");
		}

		int ab = abs(c); // Absolute value for printing

		// Coefficient & exponent printing
		if (e == 0)
			printf("%d", ab);
		else if (e == 1) {
			if (ab == 1)
				printf("x");
			else
				printf("%dx", ab);
		} else {
			if (ab == 1)
				printf("x^%d", e);
			else
				printf("%dx^%d", ab, e);
		}
	}
	printf("\n");
}

// Function to read the polynomials
void read() {
	printf("Enter the number of terms of first polynomial: ");
	scanf("%d", &n1);
	int i;
	for (i = 0; i < n1; i++) {
		printf("Term %d (coeff exponent): ", i + 1);
		scanf("%d %d", &a[i].coeff, &a[i].expo);
	}

	printf("First Polynomial: ");
	display(a, &n1);

	printf("\nEnter the number of terms of second polynomial: ");
	scanf("%d", &n2);
	for (i = 0; i < n2; i++) {
		printf("Term %d (coeff exponent): ", i + 1);
		scanf("%d %d", &b[i].coeff, &b[i].expo);
	}

	printf("Second Polynomial: ");
	display(b, &n2);
}

// Function to add two polynomials
void addpoly() {
	int i = 0, j = 0, k = 0;

	while (i < n1 && j < n2) {
		if (a[i].expo > b[j].expo)
			add[k++] = a[i++];
		else if (a[i].expo < b[j].expo)
			add[k++] = b[j++];
		else {
			add[k].coeff = a[i].coeff + b[j].coeff;
			add[k].expo = a[i].expo;
			k++;
			i++;
			j++;
		}
	}

	// Copy remaining terms
	while (i < n1)
		add[k++] = a[i++];
	while (j < n2)
		add[k++] = b[j++];

	nr = k;

	printf("\nResultant Polynomial after Addition: ");
	display(add, &nr);
}

int main() {
	read();
	addpoly();
	return 0;
}
