/*Program 22 SPARSE MATRIX ADDITION
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

int toSparse(int x, int y, int mat[x][y], int s[x*y][3]) { // Function to convert matrix to sparse representation
    int i, j, k = 0;
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
    return k; // Return number of non-zero elements
}

void printsparse(int k, int s[k][3]) { // Function to display sparse matrix
    int i;
    printf("Sparse Matrix Representation (row, column, value):\n");
    for (i = 0; i < k; i++) {
        printf("%d %d %d\n", s[i][0], s[i][1], s[i][2]);
    }
}

int main() {
    int x, y;
    printf("Enter dimensions of matrix (rows columns): ");
    scanf("%d %d", &x, &y);
    int mat[x][y];
    insert(x, y, mat);
    printf("Matrix:\n");
    display(x, y, mat);
    
    int sparse[x * y][3];
    int k = toSparse(x, y, mat, sparse);

    printf("Sparse Representation of First Matrix:\n");
    printsparse(k, sparse);

    return 0;
}