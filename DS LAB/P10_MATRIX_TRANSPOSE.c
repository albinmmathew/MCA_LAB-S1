/*PROGRAM-10 MATRIX TRANSPOSE
@ALBIN MAMMEN MATHEW
29/07/2025
*/

#include<stdio.h>
int a[10][10],t[10][10];
void print(int e[10][10],int m,int n){ //function to print the matrix.
	int i,j;
	for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d\t",e[i][j]);
        }
    	printf("\n");
    }
}
void transpose(int m,int n){ //function to find transpose of matrix
	int i,j;
	for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            t[j][i] = a[i][j];
        }
    }
    printf("The Transpose of the matrix is : \n");
    print(t,n,m);
}

int main(){
	int m,n;
	printf("Enter the dimensions of the Matrix :");
	scanf("%d%d",&m,&n);
	int i,j;
	for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("Enter the value of [%d] [%d] : ",i,j);
		    scanf("%d",&a[i][j]);
        }
    }
    printf("The matrix is : \n");
    print(a,m,n);
    transpose(m,n);
    return 0;
}
