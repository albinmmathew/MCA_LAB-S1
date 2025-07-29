/* PROGRAM-11 DETERMINANT OF A MATRIX
@ALBIN MAMMEN MATHEW
29/07/2025
*/

#include <stdio.h>

int main() {
    int size,a[3][3],i,j;
    float det;
    printf("Enter the size of the square matrix (2 or 3): ");
    scanf("%d",&size);

    if (size!=2 && size!=3) {
        printf("Only 2x2 and 3x3 matrices are supported.\n");
        return 1;
    }

    printf("Enter the elements of the matrix:\n"); 
    for (i=0;i<size;i++) {
        for (j =0;j<size;j++) {
            printf("a[%d][%d]: ",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    printf("The matrix is:\n"); 
    for (i=0;i<size;i++) {
        for (j=0;j<size;j++) {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }

    if (size==2) {
        det=a[0][0]*a[1][1] - a[0][1]*a[1][0]; // For 2x2: |A| = ad - bc
    } else if (size==3) {
        det =  a[0][0]*(a[1][1]*a[2][2] - a[1][2]*a[2][1]) //expansion of  formula
             - a[0][1]*(a[1][0]*a[2][2] - a[1][2]*a[2][0])
             + a[0][2]*(a[1][0]*a[2][1] - a[1][1]*a[2][0]);
    }

    printf("Determinant of the matrix = %.2f\n", det);

    return 0;
}

