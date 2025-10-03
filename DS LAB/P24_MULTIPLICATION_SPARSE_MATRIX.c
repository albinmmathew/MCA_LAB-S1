/*Program 23 ADDITION - SPARSE MATRIX ADDITION
@ALBIN MAMMEN MATHEW
Roll No: 08
Date: 20/09/2025
*/

#include <stdio.h>

void insert(int x, int y, int mat[x][y]) { // Function to insert elements into matrix
    int i, j;
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void display(int x, int y, int mat[x][y]) { // Function to display matrix
    int i, j;
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int toSparse(int x, int y, int mat[x][y], int sparse[x*y][3]) { // Function to convert matrix to sparse representation
    int i, j, k = 0;
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            if (mat[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }
        }
    }
    return k; // Return number of non-zero elements
}

void printsparse(int k, int sparse[k][3]) { // Function to display sparse matrix
    int i;
    printf("Sparse Matrix Representation (row, column, value):\n");
    for (i = 0; i < k; i++) {
        printf("%d %d %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}


void reverse(int k, int sparse[k][3]) { // Function to reverse sparse matrix
    int i, temp[3];
    for (i = 0; i < k / 2; i++) {
        temp[0] = sparse[i][0];
        temp[1] = sparse[i][1];
        temp[2] = sparse[i][2];
        sparse[i][0] = sparse[k - i - 1][0];
        sparse[i][1] = sparse[k - i - 1][1];
        sparse[i][2] = sparse[k - i - 1][2];
        sparse[k - i - 1][0] = temp[0];
        sparse[k - i - 1][1] = temp[1];
        sparse[k - i - 1][2] = temp[2];
    }
    printf("Reversed Sparse Matrix:\n");
    printsparse(k, sparse);
}

// Function to multiply two sparse matrices
void multiplySparse(int x1, int y1, int k1, int sparse1[k1][3], int x2, int y2, int k2, int sparse2[k2][3], int result[x1 * y2][3], int *k3) {
    int i, j, r = 0;
    // Convert sparse2 to column-major for faster access
    for (i = 0; i < x1; i++) {
        for (j = 0; j < y2; j++) {
            int sum = 0;
            int a, b;
            for (a = 0; a < k1; a++) {
                if (sparse1[a][0] == i) {
                    for (b = 0; b < k2; b++) {
                        if (sparse2[b][0] == sparse1[a][1] && sparse2[b][1] == j) {
                            sum += sparse1[a][2] * sparse2[b][2];
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
    *k3 = r;
    printf("Multiplication of Sparse Matrices Result:\n");
    printsparse(*k3, result);
    reverse(*k3, result);
}


int main() {
    int x1, y1, x2, y2;
    printf("Enter dimensions of first matrix (rows columns): ");
    scanf("%d %d", &x1, &y1);
    int mat1[x1][y1];
    insert(x1, y1, mat1);
    printf("First Matrix:\n");
    display(x1, y1, mat1);

    printf("Enter dimensions of second matrix (rows columns): ");
    scanf("%d %d", &x2, &y2);
    if (x2 != y1) {
        printf("Error: Matrices must have the same dimensions for multiplication.\n");
        return 1;
    }
    int mat2[x2][y2];
    insert(x2, y2, mat2);
    printf("Second Matrix:\n");
    display(x2, y2, mat2);

    int sparse1[x1 * y1][3], sparse2[x2 * y2][3];
    int k1 = toSparse(x1, y1, mat1, sparse1);
    int k2 = toSparse(x2, y2, mat2, sparse2);

    printf("Sparse Representation of First Matrix:\n");
    printsparse(k1, sparse1);
    printf("Sparse Representation of Second Matrix:\n");
    printsparse(k2, sparse2);

    int result[x1 * y2][3], k3;
    multiplySparse(x1, y1, k1, sparse1, x2, y2, k2, sparse2, result, &k3);

    return 0;
} 