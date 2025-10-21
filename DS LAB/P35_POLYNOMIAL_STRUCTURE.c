/* PROGRAM 35: READ AND DISPLAY POLYNOMIAL USING STRUCTURE
@ALBIN MAMMEN MATHEW
Roll No: 08
15/10/2025
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in the polynomial
typedef struct poly {
	int coeff;     // Coefficient of the term
	int exponen;   // Exponent of the term
} term;

term a[10];         // Array to store polynomial terms
int n;              // Number of terms in the polynomial

// Function to read polynomial terms from user
void read() {
	int i;
	printf("\nEnter the number of terms: ");
	scanf("%d", &n);
	printf("Enter the polynomial terms:\n");
	for (i = 0; i < n; i++) {
		printf("Term %d:\n", i + 1);
		printf("\tCoefficient: ");
		scanf("%d", &a[i].coeff);
		printf("\tExponent: ");
		scanf("%d", &a[i].exponen);
	}
}

// Function to print the polynomial in readable format
void print() {
	int c, e;
	printf("\nPolynomial: ");
	int i;
	for (i = 0; i < n; i++) {
		c = a[i].coeff;    // Get coefficient
		e = a[i].exponen;  // Get exponent

		if (c == 0)        // Skip terms with zero coefficient
			continue;

		int abs_c = abs(c);  // Absolute value of coefficient

		// Print sign for terms except the first
		if (i != 0) {
			if (c > 0)
				printf("+");
			else
				printf("-");
		} else {
			if (c < 0)
				printf("-");
		}

		// Print term based on exponent value
		if (e == 0) {
			printf("%d", abs_c);               // Constant term
		} else if (e == 1) {
			if (abs_c == 1)
				printf("x");                   // x term with coefficient 1
			else
				printf("%dx", abs_c);          // x term with coefficient not 1
		} else {
			if (abs_c == 1)
				printf("x^%d", e);             // x^e term with coefficient 1
			else
				printf("%dx^%d", abs_c, e);    // x^e term with coefficient not 1
		}
	}
	printf("\n");
}

// Main function
int main() {
	read();    // Read polynomial from user
	print();   // Print the polynomial
	return 0;
}
