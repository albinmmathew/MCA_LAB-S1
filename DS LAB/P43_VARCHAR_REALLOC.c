/* PROGRAM 43: IMPLEMENTING VARCHAR USING REALLOC
@ALBIN MAMMEN MATHEW
Roll No: 08
03/10/2025
*/

#include <stdio.h>
#include <stdlib.h>

void read() {
	char *ptr;
	int size = 10;   // default initial size
	int len = 0;

	ptr = (char *)malloc(size * sizeof(char));

	char ch;
	printf("Enter the String: ");

	// Read characters until newline
	while ((ch = getchar()) != '\n') {
		ptr[len++] = ch;

		// If memory is full, double the size
		if (len == size) {
			size *= 2;
			char *temp = (char *)realloc(ptr, size * sizeof(char));
			if (temp == NULL) {
				printf("Memory reallocation failed!\n");
				free(ptr);
				exit(1);
			}
			ptr = temp;
		}
	}

	// Null-terminate the string
	ptr[len] = '\0';

	printf("You entered: %s\n", ptr);

	free(ptr);
}

int main() {
	printf("----- Dynamic Input Using Realloc -----\n");
	read();
	return 0;
}
