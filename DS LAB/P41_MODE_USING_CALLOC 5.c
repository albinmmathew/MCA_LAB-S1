/* PROGRAM 41: MODE OF n NUMBERS USING CALLOC
@ALBIN MAMMEN MATHEW
Roll No: 08
03/10/2025
*/

#include <stdio.h>
#include <stdlib.h>

void mode() {
	int i,j,n;
	int max = 0, mode = 0;
	int *ptr;

	printf("Enter the number of terms: ");
	scanf("%d", &n);

	// Allocate memory dynamically using calloc
	ptr = (int *)calloc(n, sizeof(int));

	printf("\nEnter the numbers:\n");
	for (i = 0; i < n; i++) {
		scanf("%d", &ptr[i]);
	}

	// Find the mode
	for (i = 0; i < n; i++) {
		int count = 1;
		for (j = i + 1; j < n; j++) {
			if (ptr[i] == ptr[j]) {
				count++;
			}
		}
		if (count > max) {
			max = count;
			mode = ptr[i];
		}
	}

	printf("\nMode = %d (appears %d times)\n", mode, max);
	// Free the allocated memory
	free(ptr);
}

int main() {
	mode();
	return 0;
}
