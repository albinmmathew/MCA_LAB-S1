/* PROGRAM 39: DYNAMIC MEMORY ALLOCATION FUNCTIONS
@ALBIN MAMMEN MATHEW
Roll No: 08
03/10/2025
*/

#include <stdio.h>
#include <stdlib.h>

void implement() {
	int *ptr;
	int i,n;

	printf("\nEnter the number of allocations you need: ");
	scanf("%d", &n);

	// Allocating memory using malloc
	ptr = (int *)malloc(n * sizeof(int));

	printf("\nEnter the elements:\n");
	for (i = 0; i < n; i++) {
		scanf("%d", &ptr[i]);
	}

	printf("\nPrinting the elements (implementation of malloc):\n");
	for (i = 0; i < n; i++) {
		printf("%d\t", ptr[i]);
	}
	free(ptr);	// Used to free the memory

	// Allocating memory using calloc
	ptr = (int *)calloc(n, sizeof(int));

	printf("\n\nPrinting initial elements in memory (after allocating using calloc):\n");
	for (i = 0; i < n; i++) {
		printf("%d\t", ptr[i]);
	}
	free(ptr);	// Free the memory
}

int main() {
	implement();
	return 0;
}
