/*PROGRAM-2 A MENU FOR ARRAY OPERATIONS(INSERT,DELETE,DISPLAY,SEARCH,SORT) USING GLOBAL VARIABLE
@ALBIN MAMMEN MATHEW
16/07/2025
*/

#include<stdio.h>
int stack[5];	//declaring stack
int top=-1; 	//declaring variable positionof top element 
int insert(int e){		//Function to insert element into stack
	if(top+1==5){
		printf("Error : Stack is Full");
	}
	else{
		stack[++top]=e;  
	}
	return top;
}
int erase() //function to delete top element
{
	if (top==-1){
		printf("Error: Stack is empty");
	}
	else{
		printf("\n %d",stack[top--]);
	}
	return top;
}
void search(int b,int a[5],int top){ //function to search elements
	int isfound=0,i;
	for (i=0;i<=top;i++){
		if(b==a[i]){
			isfound=1;
			printf("Element found at [%d] position. \n",i);
		}
	}
	if(isfound==0)
		printf("element not found");
}
	
void display(){ //function to display the elements in stack
	if (top==-1)
		printf("Empty Stack");
	else{
		int i;
		for(i=0;i<=top;i++){
			printf("%d \t",stack[i]);
		}
		printf("\n");
	}
}

void sort(){	//function to sort the stack
	int i,j,temp;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(stack[i]<stack[j]){
				temp=stack[i];
				stack[i]=stack[j];
				stack[j]=temp;
			}
		}
	}
}

int menu(){ //function for menu
	int ch;
	printf("\n INSERT-1 \n DELETE-2 \n DISPLAY-3 \n SEARCH-4 \n SORT-5 \n EXIT -6 \n Enter your choice : ");
	scanf("%d",&ch);
	return ch;
}
void processStack(){ //working of menu
	int ch,b;
	for (ch=menu();ch!=6;ch=menu()){
		switch(ch){
			case 1: //insert 
				printf("Enter the value to insert : ");
				scanf("%d",&ch);
				insert(ch);
				break;
			case 2: //delete
				erase();
				break;
			case 3: //display
				display();
				break;
			case 4: //search
				printf("Enter the value to search : ");
				scanf("%d",&b);
				search(b,stack,top);
				break;
			case 5:// sort
				sort();
				break;
			default://any other options
				printf("Error: Wrong Choice");
				break;	
		}
	}
}
int main() {
	processStack();
	return 0;
}
