/*PROGRAM-7 DISPLAY ARRAY INN REVERSE USING RECURSIVE FUNCTION
@ALBIN MAMMEN MATHEW
23/07/2025
*/

#include<stdio.h>
int j=10,arr[10];
void display(){ //function to display elements in reverese order using recursive function
	if(j>0){
		j--;
		printf("%d\t",arr[j]);
		display();
	if(j==0)
		j=10;
	}
}

int main(){
	int i=0;
	for(i=0;i<10;i++){ 
		printf("Enter the value for %d :",i);
		scanf("%d",&arr[i]);
	}
	display();
	return 0;
}
