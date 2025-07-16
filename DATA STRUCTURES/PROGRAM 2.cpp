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
void display(){ //function to display the elements in stack
	if (top==-1)
		printf("Empty Stack");
	else{
		for(int i=0;i<=top;i++){
			printf("%d \t",stack[i]);
		}
		printf("\n");
	}
}
void search(int b){
	int isfound=0;
	if (top==-1)
		printf("Empty Stack");
	for(int i=0;i<=top;i++){
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
	printf("\n INSERT-1 \n DELETE-2 \n DISPLAY-3 \n SEARCH-4 \n EXIT-5 \n Enter your choice : ");
	scanf("%d",&ch);
	return ch;
}
void processStack(){ //working of menu
	int ch;
	for (ch=menu();ch!=5;ch=menu()){
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
				int b;
				printf("Enter the number to search: ");
				scanf("%d",&b);
				search(b);
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
