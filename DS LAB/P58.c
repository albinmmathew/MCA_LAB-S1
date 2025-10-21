/*PROGRAM 58 BINARY SEARCH TREE IN ARRAY OF INTEGERS
@ALBIN MAMMEN MATHEW
Roll No: 08
05/10/2025
*/

#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int n, int key) {
	int low = 0, high = n - 1;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (arr[mid] == key)
			return mid;		// Element found
		else if (arr[mid] < key)
			low = mid + 1;	// Search right half
		else
			high = mid - 1;	// Search left half
	}

	return -1;				// Element not found
}

int main() {
	int n, key;

	printf("Enter number of elements: ");
	scanf("%d", &n);

	int arr[n];
	printf("Enter %d sorted elements:\n", n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("Enter element to search: ");
	scanf("%d", &key);

	int pos = binarySearch(arr, n, key);

	if (pos != -1)
		printf("Element %d found at position %d\n", key, pos + 1);
	else
		printf("Element %d not found.\n", key);

	return 0;
}
