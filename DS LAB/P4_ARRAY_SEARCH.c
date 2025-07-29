/*PROGRAM-4 ARRAY SEARCH
@ALBIN MAMMEN MATHEW
16/07/2025
*/

#include<stdio.h>

void search(int b,int a[5]){ //funtion for search function
	int isfound=0,i;
	for (i=0;i<5;i++){
		if(b==a[i]){
			isfound=1;
			printf("Element found at [%d] position. \n",i); //displays index
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
