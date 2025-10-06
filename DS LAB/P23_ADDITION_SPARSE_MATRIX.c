
/*Program 23 SPARSE MATRIX ADDITION
@ALBIN MAMMEN MATHEW
Roll No: 08
Date: 20/09/2025
*/

#include <stdio.h>

// Function to insert elements into matrix
void insert(int x, int y, int mat[x][y]) {
	int i, j;
	printf("Enter elements of the matrix:\n");
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
}

// Function to convert matrix to sparse representation
int toSparse(int x, int y, int mat[x][y], int s[x * y + 1][3]) {
	int i, j, k = 1;
	s[0][0] = x;
	s[0][1] = y;
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			if (mat[i][j] != 0) {
				s[k][0] = i;
				s[k][1] = j;
				s[k][2] = mat[i][j];
				k++;
			}
		}
	}
	s[0][2] = k - 1;
	return k; // Return number of non-zero elements
}

// Function to display sparse matrix
void printsparse(int k, int s[k][3]) {
	int i;
	printf("Sparse Matrix Representation (row, column, value):\n");
	for (i = 0; i < k; i++) {
		printf("%d %d %d\n", s[i][0], s[i][1], s[i][2]);
	}
}

// Function to add two sparse matrices
void addSparse(int s1_rows, int sp1[s1_rows][3], int s2_rows, int sp2[s2_rows][3], int result[s1_rows + s2_rows][3], int *res_rows) {
	// Both sparse1 and sparse2 have header at index 0
	int i = 1, j = 1, r = 1;
	// Set header
	result[0][0] = sp1[0][0];
	result[0][1] = sp1[0][1];
	// Add non-zero elements
	while (i < s1_rows && j < s2_rows) {
		if (sp1[i][0] < sp2[j][0] || (sp1[i][0] == sp2[j][0] && sp1[i][1] < sp2[j][1])) {
			result[r][0] = sp1[i][0];
			result[r][1] = sp1[i][1];
			result[r][2] = sp1[i][2];
			i++;
			r++;
		} else if (sp1[i][0] > sp2[j][0] || (sp1[i][0] == sp2[j][0] && sp1[i][1] > sp2[j][1])) {
			result[r][0] = sp2[j][0];
			result[r][1] = sp2[j][1];
			result[r][2] = sp2[j][2];
			j++;
			r++;
		} else {
			result[r][0] = sp1[i][0];
			result[r][1] = sp1[i][1];
			result[r][2] = sp1[i][2] + sp2[j][2];
			i++;
			j++;
			r++;
		}
	}
	while (i < s1_rows) {
		result[r][0] = sp1[i][0];
		result[r][1] = sp1[i][1];
		result[r][2] = sp1[i][2];
		i++;
		r++;
	}
	while (j < s2_rows) {
		result[r][0] = sp2[j][0];
		result[r][1] = sp2[j][1];
		result[r][2] = sp2[j][2];
		j++;
		r++;
	}
	result[0][2] = r - 1; // Update non-zero count in header
	*res_rows = r; // Total rows in result sparse
	printf("Addition of Sparse Matrices Result:\n");
	printsparse(*res_rows, result);
}

int main() {
	int x1, y1, x2, y2;
	printf("Enter dimensions of first matrix (rows columns): ");
	scanf("%d %d", &x1, &y1);
	int mat1[x1][y1];
	insert(x1, y1, mat1);

	printf("Enter dimensions of second matrix (rows columns): ");
	scanf("%d %d", &x2, &y2);
	if (x1 != x2 || y1 != y2) {
		printf("Error: Matrices must have the same dimensions for addition.\n");
		return 1;
	}
	int mat2[x2][y2];
	insert(x2, y2, mat2);

	int sp1[x1 * y1 + 1][3], sp2[x2 * y2 + 1][3];
	int k1 = toSparse(x1, y1, mat1, sp1);
	int k2 = toSparse(x2, y2, mat2, sp2);

	printf("Sparse Representation of First Matrix:\n");
	printsparse(k1, sp1);
	printf("Sparse Representation of Second Matrix:\n");
	printsparse(k2, sp2);

	int result[k1 + k2][3], k3;
	addSparse(k1, sp1, k2, sp2, result, &k3);

	return 0;
}
