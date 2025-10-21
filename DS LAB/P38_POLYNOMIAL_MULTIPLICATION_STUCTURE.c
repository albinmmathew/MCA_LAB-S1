/* PROGRAM 38: POLYNOMIAL MULTIPLICATION USING STRUCTURE ARRAY
@ALBIN MAMMEN MATHEW
Roll No: 08
15/10/2025
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int coeff;
	int expo;
} poly;

poly a[10], b[10], prod[20];	// increased size for product terms
int n1, n2, nr;

// Function to display a polynomial
void display(poly p[], int *n) {
	int i;
	for (i = 0; i < *n; i++) {
		int c = p[i].coeff;
		int e = p[i].expo;

		if (c == 0)
			continue;	// skip zero coeff

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

		int ab = abs(c);

		// Coefficient & exponent printing
		if (e == 0) {
			printf("%d", ab);
		} else if (e == 1) {
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

// Function to read polynomials
void read() {
	int i;
	printf("Enter the number of terms of first polynomial: ");
	scanf("%d", &n1);

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

// Function to multiply polynomials
void multiplication() {
	int i, j, l, k = 0;

	// Multiply each term of a with each term of b
	for (i = 0; i < n1; i++) {
		for (j = 0; j < n2; j++) {
			prod[k].coeff = a[i].coeff * b[j].coeff;
			prod[k].expo  = a[i].expo + b[j].expo;
			k++;
		}
	}
	nr = k;

	// Combine like terms (same exponent)
	for (i = 0; i < nr; i++) {
		for (j = i + 1; j < nr; j++) {
			if (prod[i].expo == prod[j].expo) {
				prod[i].coeff += prod[j].coeff;

				// shift left
				for (l = j; l < nr - 1; l++) {
					prod[l] = prod[l + 1];
				}
				nr--;
				j--;	// recheck same index
			}
		}
	}

	// Sort terms in descending order of exponent
	for (i = 0; i < nr - 1; i++) {
		for (j = i + 1; j < nr; j++) {
			if (prod[i].expo < prod[j].expo) {
				poly temp = prod[i];
				prod[i] = prod[j];
				prod[j] = temp;
			}
		}
	}

	printf("\nResultant Polynomial after Multiplication: ");
	display(prod, &nr);
}

// Main function
int main() {
	read();
	multiplication();
	return 0;
}
