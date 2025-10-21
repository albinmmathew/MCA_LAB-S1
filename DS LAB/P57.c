/*PROGRAM 57 LINEAR SEARCH
@ALBIN MAMMEN MATHEW
Roll No: 08
05/10/2025
*/

#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int key) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == key)
			return i;	// Return index if element found
	}
	return -1;	// Return -1 if not found
}

int main() {
	int n, key;

	printf("Enter number of elements: ");
	scanf("%d", &n);

	int arr[n];
	printf("Enter %d elements:\n", n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("Enter element to search: ");
	scanf("%d", &key);

	int pos = linearSearch(arr, n, key);

	if (pos != -1)
		printf("Element %d found at position %d\n", key, pos + 1);
	else
		printf("Element %d not found.\n", key);

	return 0;
}
