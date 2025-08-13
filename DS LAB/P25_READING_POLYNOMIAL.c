/*Program 25 READING POLYNOMIAL
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
int main(){
	int poly[size],deg;
	printf("Enter the degree of polynomial: ");
	scanf("%d",&deg);
	read(poly,deg);
	print(poly,deg);
	return 0;
}	
