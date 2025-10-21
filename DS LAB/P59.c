/*PROGRAM 59 BINARY SEARCH TREE IN ARRAY OF STRINGS
@ALBIN MAMMEN MATHEW
Roll No: 08
05/10/2025
*/

#include <stdio.h>
#include <string.h>

// Function to perform binary search on strings
int binarySearchString(char arr[][50], int n, char key[]) {
	int low = 0, high = n - 1;

	while (low <= high) {
		int mid = (low + high) / 2;

		int cmp = strcmp(arr[mid], key);
		if (cmp == 0)
			return mid;			// String found
		else if (cmp < 0)
			low = mid + 1;		// Search right half
		else
			high = mid - 1;	// Search left half
	}

	return -1;					// Not found
}

int main() {
	int n;
	char key[50];

	printf("Enter number of strings: ");
	scanf("%d", &n);

	char arr[n][50];
	printf("Enter %d strings in sorted order:\n", n);
	for (int i = 0; i < n; i++)
		scanf("%s", arr[i]);

	printf("Enter string to search: ");
	scanf("%s", key);

	int pos = binarySearchString(arr, n, key);

	if (pos != -1)
		printf("String '%s' found at position %d\n", key, pos + 1);
	else
		printf("String '%s' not found.\n", key);

	return 0;
}
