/* PROGRAM 42: BOOK MANAGEMENT - STRUCTURE ARRAY - READ AND DISPLAY USING POINTERS
@ALBIN MAMMEN MATHEW
Roll No: 08
03/10/2025
*/
#include <stdio.h>
#include <stdlib.h>

struct Book {
	char bname[50];
	char aname[50];
	float price;
};

// Function to read n books
void readBooks(struct Book *b, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("\nEnter details of Book %d\n", i + 1);
		printf("Book Name: ");
		scanf("%s", (b + i)->bname);
		printf("Author Name: ");
		scanf("%s", (b + i)->aname);
		printf("Price: ");
		scanf("%f", &(b + i)->price);
	}
}

// Function to display n books
void displayBooks(struct Book *b, int n) {
	int i;
	printf("\n--- Book Details ---\n");
	for (i = 0; i < n; i++) {
		printf("\nBook %d\n", i + 1);
		printf("Book Name: %s\n", (b + i)->bname);
		printf("Author Name: %s\n", (b + i)->aname);
		printf("Price: %.2f\n", (b + i)->price);
	}
}

int main() {
	struct Book *b;
	int n;

	printf("----- Struct Pointer Variable -----\n");
	printf("Enter number of books: ");
	scanf("%d", &n);

	// Dynamically allocate memory for n books
	b = (struct Book *)malloc(n * sizeof(struct Book));
	if (b == NULL) {
		printf("Memory allocation failed!\n");
		return 0;
	}

	// Read and display
	readBooks(b, n);
	displayBooks(b, n);

	// Free memory
	free(b);
	return 0;
}
