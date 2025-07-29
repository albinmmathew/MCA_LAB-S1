/*PROGRAM-9 MATRIX MULTIPLICATION
@ALBIN MAMMEN MATHEW
29/07/2025
*/

#include<stdio.h>
int a[10][10],b[10][10],m,n,p;

void insert(int e[10][10],int m,int n){ //function to insert values in the matrix
	int i,j;
	for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("Enter the value of [%d] [%d] : ",i,j);
		    scanf("%d",&e[i][j]);
        }
    }	
}

void print(int p[10][10],int m,int n){ //funtion to display the matrix
	int i,j;
	for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d\t",p[i][j]);
        }
    	printf("\n");
    }
}

void multi(){ //function to multipy two matrices
	int prod[10][10],i,j,k;
    for(i=0;i<m;i++){ //declaring intial value of elements of product to be zero
        for(j=0;j<p;j++){
            prod[i][j]=0;
    	}
    }
    
    for(i = 0; i < m; i++) {
        for(j = 0; j < p; j++) {
            for(k = 0; k < n; k++) {
                prod[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    print(prod,m,p);
}


int main(){
    printf("Enter the dimensions of first Matrix: ");
    scanf("%d%d",&m,&n);
    printf("Enter the First matrix :\n");
    insert(a,m,n);
    printf("Enter the number of columns for the Second Matrix: ");
    scanf("%d", &p);
    printf("Enter the Second matrix : \n");
    insert(b,n,p);
    printf("The first matrix is : \n");
    print(a,m,n);
    printf("The Second matrix is : \n");
    print(b,n,p);
    printf("The product of matrices is : \n");
    multi();

	return 0;
}


