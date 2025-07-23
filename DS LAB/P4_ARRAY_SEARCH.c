//PROGRAM-4 ARRAY SEARCH

#include<stdio.h>

/*
void search(int b,int a[5],int c[5]){
	int j=0,isfound=0;
	for(int i=0;i<5;i++){
		if (b==a[i]){
			isfound=1;
			c[j]=i;
			j++;
		}
	}
	if (isfound){
		for (int k=0;k<j;k++){
			printf("the element found at [%d] position.\n",c[k]);
		}
	}
	else
		printf("not found");
}
int main(){
	int a[5],ch,c[5];
	for (int i=0;i<5;i++){
		printf("Enter the [%d] element : ",i);
		scanf("%d",&a[i]);
	}
	for (int i=0;i<5;i++){
		printf("%d \t",a[i]);
	}
	printf("\n");
	printf("Enter the element to search: ");
	scanf("%d",&ch);
	search(ch,a,c);
	return 0;
}
*/

//LOGIC 2

void search(int b,int a[5]){
	int isfound=0,i;
	for (i=0;i<5;i++){
		if(b==a[i]){
			isfound=1;
			printf("Element found at [%d] position. \n",i);
		}
	}
	if(isfound=0)
		printf("element not found");
}
int main(){
	int a[5],ch,i;
	for (i=0;i<5;i++){
		printf("Enter the [%d] element : ",i);
		scanf("%d",&a[i]);
	}
	for (i=0;i<5;i++){
		printf("%d \t",a[i]);
	}
	printf("\n");
	printf("Enter the element to search: ");
	scanf("%d",&ch);
	search(ch,a);
	return 0;
}
