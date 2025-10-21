/* PROGRAM 37: POLYNOMIAL SUBTRACTION USING STRUCTURE ARRAY
@ALBIN MAMMEN MATHEW
Roll No: 08
15/10/2025
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int coeff;
	int expo;
} term;

term a[10], b[10], diff[10];
int n1, n2;

// Function to display a polynomial
void display(term p[], int *n) {
	int i;
	for (i = 0; i < *n; i++) {
		int c = p[i].coeff;
		int e = p[i].expo;

		if (c == 0)
			continue; // Skip zero coefficient terms

		int ab = abs(c);

		// Print sign
		if (i != 0) {
			if (c > 0)
				printf("+");
			else
				printf("-");
		} else {
			if (c < 0)
				printf("-");
		}

		// Print coefficient and exponent
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

// Function to read two polynomials
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

// Function to perform polynomial subtraction
void subtraction() {
	term negative[10];
	int i, j, k = 0;

	// Negate coefficients of second polynomial
	for (i = 0; i < n2; i++) {
		negative[i].coeff = -b[i].coeff;
		negative[i].expo = b[i].expo;
	}

	i = 0;
	j = 0;

	// Subtract like terms (similar to addition)
	while (i < n1 && j < n2) {
		if (a[i].expo > negative[j].expo)
			diff[k++] = a[i++];
		else if (a[i].expo < negative[j].expo)
			diff[k++] = negative[j++];
		else {
			diff[k].coeff = a[i].coeff + negative[j].coeff;
			diff[k].expo = a[i].expo;
			i++;
			j++;
			k++;
		}
	}

	// Add remaining terms
	while (i < n1)
		diff[k++] = a[i++];
	while (j < n2)
		diff[k++] = negative[j++];

	printf("\nResultant Polynomial after Subtraction: ");
	display(diff, &k);
}

// Main function
int main() {
	read();
	subtraction();
	return 0;
}
