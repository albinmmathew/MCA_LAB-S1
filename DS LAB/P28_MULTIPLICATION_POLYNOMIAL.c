/*Program 28 MULTIPLYING POLYNOMIAL
@ALBIN MAMMEN MATHEW
Roll No: 08
Date: 13/08/2025
*/

#include<stdio.h>
#define size 10

void read(int poly[],int deg) {	// Function to read polynomial
	int i;
	for(i = deg; i >= 0; i--) {
		printf("Enter the coefficient of x^ %d : ", i);
		scanf("%d", &poly[i]);
	}
}

void print(int poly[], int deg) {	// Function to print polynomial
	int i;
	for(i = deg; i >= 0; i--) {
		if(poly[i] == 0)
			continue;
		if(i != deg){
			if(poly[i] > 0 ) {
				printf(" + ");
			} else if(poly[i] < 0) {
				printf(" - ");
			}
		} else if(poly[i] < 0) {
			printf("-");
		}
		int coeff = poly[i] < 0 ? -poly[i] : poly[i];
		if(i == 0){
			printf("%d", coeff);
		}else if(i == 1) {
			printf("%dx", coeff);
		}else {
			printf("%dx^%d", coeff, i);
		}
	}
}

// Function to multiply two polynomials
void multiply(int poly1[], int poly2[], int prod[], int deg1, int deg2) {
	int i, j;
	// Initialize product array to zero
	for(i = 0; i <= deg1 + deg2; i++) {
		prod[i] = 0;
	}
	// Multiply polynomials
	for(i = 0; i <= deg1; i++) {
		for(j = 0; j <= deg2; j++) {
			prod[i + j] += poly1[i] * poly2[j];
		}
	}
	printf("\nProduct of polynomial 1 and polynomial 2 is: \n");
	print(prod, deg1 + deg2);
}

int main() {
	int poly1[size], poly2[size], p[size * 2], deg1, deg2;
	int i;
	for(i = 0; i < size; i++) {
		poly1[i] = 0;
		poly2[i] = 0;
		p[i] = 0;
	}
	printf("Enter the degree of polynomial 1: ");
	scanf("%d", &deg1);
	read(poly1, deg1);
	printf("Enter the degree of polynomial 2: ");
	scanf("%d", &deg2);
	read(poly2, deg2);
	printf("\nPolynomial 1 is: \n");
	print(poly1, deg1);
	printf("\nPolynomial 2 is: \n");
	print(poly2, deg2);
	multiply(poly1, poly2, p, deg1, deg2);
	return 0;
}