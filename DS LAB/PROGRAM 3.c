#include<stdio.h>	//declaring variable positionof top element 
int insert(int e,int s[5],int top){		//Function to insert element into stack
	if(top+1==5){
		printf("Error : Stack is Full\n");
	}
	else{
		s[++top]=e; 
	}
	return top;
}
int erase(int top,int s[5]) //function to delete top element
{
	if (top==-1){
		printf("Error: Stack is empty\n");
	}
	else{
		printf(" %d \n",s[top--]);
	}
	return top;
}
void display(int top,int s[5]){ //function to display the elements in stack
	int i;
	if (top==-1)
		printf("Empty Stack");
	else{
		for(int i=0;i<=top;i++){
			printf("%d \t",s[i]);
		}
		printf("\n");
	}
}
void search(int b,int s[5],int top){
	int isfound=0;
	for (i=0;i<=top;i++){
		if(b==s[i]){
			isfound=1;
			printf("Element found at [%d] position. \n",i);
		}
	}
	if(isfound==0)
		printf("element not found");
}
void sort(){
}
int menu(){ //function for menu
	int ch;
	printf("\n INSERT-1 \n DELETE-2 \n DISPLAY-3 \n SEARCH-4 \n SORT-5 \n EXIT -6 \n Enter your choice : ");
	scanf("%d",&ch);
	return ch;
}
void processStack(){ //working of menu
	int ch;
	int s[5],top=-1,b;
	for (ch=menu();ch!=6;ch=menu()){
		switch(ch){
			case 1: //insert 
				printf("Enter the value to insert : ");
				scanf("%d",&b);
				top=insert(b,s,top);
				break;
			case 2: //delete
				top=erase(top,s);
				break;
			case 3: //display
				display(top,s);
				break;
			case 4:
            	int f;
            	printf("Enter the element to search: ");
            	scanf("%d",&f);
            	search(f,s,top);
            	break;
            case 5:
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
