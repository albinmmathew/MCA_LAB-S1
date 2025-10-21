/* PROGRAM 40: MEAN OF n NUMBERS USING MALLOC
@ALBIN MAMMEN MATHEW
Roll No: 08
03/10/2025
*/

#include <stdio.h>
#include <stdlib.h>

void mean() {
	int i,n;
	float sum = 0;
	float mean = 0;
	int *ptr;

	printf("Enter the number of terms: ");
	scanf("%d", &n);

	// Allocate memory dynamically
	ptr = (int *)malloc(n * sizeof(int));

	printf("\nEnter the numbers:\n");
	for (i = 0; i < n; i++) {
		scanf("%d", &ptr[i]);
	}

	// Calculate sum
	for (i = 0; i < n; i++) {
		sum += ptr[i];
	}

	// Calculate mean
	mean = sum / n;

	printf("\nThe mean is: %.2f\n", mean);

	// Free the allocated memory
	free(ptr);
}

int main() {
	mean();
	return 0;
}
