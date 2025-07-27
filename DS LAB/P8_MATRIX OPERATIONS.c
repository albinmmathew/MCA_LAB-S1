/*PROGRAM-8 MATRIX ADDITION AND SUBTRACTION
@ALBIN MAMMEN MATHEW
23/07/2025
*/

#include<stdio.h>
int a[10][10],b[10][10],m,n;

void insert(int e[10][10],int m,int n){
	int i,j;
	for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("Enter the value of [%d] [%d] : ",i,j);
		    scanf("%d",&e[i][j]);
        }
    }	
}

void print(int p[10][10],int m,int n){
	int i,j;
	for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d\t",p[i][j]);
        }
    	printf("\n");
    }
}

void add(){
	int sum[10][10],i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            sum[i][j]=a[i][j]+b[i][j];
        }
    }
    print(sum,m,n);
}

void diffn(){
	int dif[10][10],i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            dif[i][j]=a[i][j]-b[i][j];
        }
    }
    print(dif,m,n);
}


int main(){
    printf("Enter the dimensions of the Matrix: ");
    scanf("%d%d",&m,&n);
    printf("Enter the First matrix :\n");
    insert(a,m,n);
    printf("Enter the Second matrix : \n");
    insert(b,m,n);
    printf("The first matrix is : \n");
    print(a,m,n);
    printf("The Second matrix is : \n");
    print(b,m,n);
    printf("The sum of matrices is : \n");
    add(m,n);
    printf("The difference of matrices is : \n");
    diffn(m,n);
    
}


