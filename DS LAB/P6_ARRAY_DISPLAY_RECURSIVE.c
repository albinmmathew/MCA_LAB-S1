/*PROGRAM-6 DISPLAY ARRAY USING RECURSIVE FUNCTION
@ALBIN MAMMEN MATHEW
23/07/2025
*/


#include<stdio.h>
int j=0,arr[10];
void display(){ //display function as a recursive function
	if(j<10){
		printf("%d\t",arr[j]);
		j++;
		display();
	}
	if(j==10)
		j=0;
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
