#include<stdio.h>	//declaring variable positionof top element 
void insert(int e,int s[5],int top){		//Function to insert element into stack
	if(top+1==5){
		printf("Error : Stack is Full");
	}
	else{
		s[++top]=e; 
	}
}
void erase(int top,int s[5]) //function to delete top element
{
	if (top==-1){
		printf("Error: Stack is empty");
	}
	else{
		printf("\n %d",s[top--]);
	}
}
void display(int top,int s[5]){ //function to display the elements in stack
	if (top==-1)
		printf("Empty Stack");
	else{
		for(int i=0;i<=top;i++){
			printf("%d \t",s[i]);
		}
		printf("\n");
	}
}
int menu(){ //function for menu
	int ch;
	printf("\n INSERT-1 \n DELETE-2 \n DISPLAY-3 \n EXIT -4 \n Enter your choice : ");
	scanf("%d",&ch);
	return ch;
}
void processStack(int s[5]){ //working of menu
	int ch;
	int top=-1;
	for (ch=menu();ch!=4;ch=menu()){
		switch(ch){
			case 1: //insert 
				printf("Enter the value to insert : ");
				scanf("%d",&ch);
				insert(ch,s,top);
				break;
			case 2: //delete
				erase(top,s);
				break;
			case 3: //display
				display(top,s);
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
