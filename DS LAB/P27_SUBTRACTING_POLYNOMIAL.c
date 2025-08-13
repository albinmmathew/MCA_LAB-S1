/*Program 27 SUBTRACTING POLYNOMIAL
@ALBIN MAMMEN MATHEW
Roll No: 08
Date: 08/08/2025
*/

#include<stdio.h>
#define size 10

void read(int poly[],int deg){
	int i;
	for(i=deg;i>=0;i--){
		printf("Enter the coefficient of x^ %d : ",i);
		scanf("%d",&poly[i]);
	}
}

void print(int poly[],int deg){
	int i;
	for(i=deg;i!=-1;i--){
		if(poly[i]==0)
			continue;
		if(i!=deg){
			if(poly[i]!=0){
				printf(" + ");
			}
		}
		if(i==0){
			printf("%d",poly[i]);
		}else if(i==1){
			printf("%dx",poly[i]);
		}else{
			printf("%dx^%d",poly[i],i);
		}
	}
}
void diff(int poly1[],int poly2[],int diff[],int deg1,int deg2){
	int i,deg=deg1;
	if(deg1<deg2)
		deg=deg2;
	for(i=0;i<=deg;i++){
		diff[i]=0;
		diff[i]=poly1[i]-poly2[i];
	}
	print(diff,deg);
}
int main(){
	int poly1[size],poly2[size],d[size],deg1,deg2;
	int i;
	for(i = 0; i < size; i++) {
    	poly1[i] = 0;
    	poly2[i] = 0;
    	d[i] = 0;
	}
	printf("Enter the degree of polynomial 1: ");
	scanf("%d",&deg1);
	read(poly1,deg1);
	printf("Enter the degree of polynomial 2: ");
	scanf("%d",&deg2);
	read(poly2,deg2);
	diff(poly1,poly2,d,deg1,deg2);
	return 0;
}	
