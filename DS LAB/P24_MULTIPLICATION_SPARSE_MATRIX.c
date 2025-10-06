
/*Program 24 SPARSE MATRIX MULTIPLICATION
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
	return k; // Return number of rows in sparse (including header)
}

// Function to display sparse matrix
void printsparse(int k, int s[k][3]) {
	int i;
	printf("Sparse Matrix Representation (row, column, value):\n");
	for (i = 0; i < k; i++) {
		printf("%d %d %d\n", s[i][0], s[i][1], s[i][2]);
	}
}

// Function to multiply two sparse matrices (new format)
void multiplySparse(int s1_rows, int sp1[s1_rows][3], int s2_rows, int sp2[s2_rows][3], int result[sp1[0][0] * sp2[0][1] + 1][3], int *res_rows) {
	int i, j, r = 1;
	int x1 = sp1[0][0], y1 = sp1[0][1], x2 = sp2[0][0], y2 = sp2[0][1];
	// Set header for result
	result[0][0] = x1;
	result[0][1] = y2;
	// Matrix multiplication
	for (i = 0; i < x1; i++) {
		for (j = 0; j < y2; j++) {
			int sum = 0;
			int a, b;
			for (a = 1; a < s1_rows; a++) {
				if (sp1[a][0] == i) {
					for (b = 1; b < s2_rows; b++) {
						if (sp2[b][0] == sp1[a][1] && sp2[b][1] == j) {
							sum += sp1[a][2] * sp2[b][2];
						}
					}
				}
			}
			if (sum != 0) {
				result[r][0] = i;
				result[r][1] = j;
				result[r][2] = sum;
				r++;
			}
		}
	}
	result[0][2] = r - 1; // non-zero count
	*res_rows = r;
	printf("Multiplication of Sparse Matrices Result:\n");
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
	if (x2 != y1) {
		printf("Error: Matrices must have the same dimensions for multiplication.\n");
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

	int result[x1 * y2 + 1][3], k3;
	multiplySparse(k1, sp1, k2, sp2, result, &k3);

	return 0;
}
