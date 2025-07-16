#include<stdio.h>	//declaring variable positionof top element 
int insert(int e,int stack[5],int top){		//Function to insert element into stack
	if(top+1==5){
		printf("Error : Stack is Full");
	}
	else{
		stack[++top]=e; 
	}
	return top;
}
int erase(int top,int stack[5]) //function to delete top element
{
	if (top==-1){
		printf("Error: Stack is empty");
	}
	else{
		printf("\n %d",stack[top--]);
	}
	return top;
}
void display(int top,int stack[5]){ //function to display the elements in stack
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
void search(int stack[5],int top,int b){
	int isfound=0;
	if (top==-1)
		printf("Empty Stack");
	int i;
	for(i=0;i<=top;i++){
		if (b==stack[i]){
			isfound=1;
			printf("Element found at [%d] position.\n",i);
		}
	}
	if (isfound=0){
		printf("Element not found.");
	}
}
int menu(){ //function for menu
	int ch;
	printf("\n INSERT-1 \n DELETE-2 \n DISPLAY-3 \n SEARCH-4 \n EXIT -5 \n Enter your choice : ");
	scanf("%d",&ch);
	return ch;
}
void processStack(int stack[5]){ //working of menu
	int ch;
	int b;
	int top=-1;
	for (ch=menu();ch!=5;ch=menu()){
		switch(ch){
			case 1: //insert 
				printf("Enter the value to insert : ");
				scanf("%d",&ch);
				insert(ch,stack,top);
				break;
			case 2: //delete
				erase(top,stack);
				break;
			case 3: //display
				display(top,stack);
				break;
			case 4: //search
				printf("Enter the value to search : ");
				scanf("%d",&b);
				search(stack,top,b);
				break;
			default://any other options
				printf("Error: Wrong Choice");
				break;	
		}
	}
}
int main() {
	int a[5];
	processStack(a);
	return 0;
}
