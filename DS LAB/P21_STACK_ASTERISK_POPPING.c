/*Program 21  
@ALBIN MAMMEN MATHEW
Roll No: 08
Date: 10/9/2025
*/

#include<stdio.h>
#define size 100
char expr[size];
int top=-1;

void push(char a) {
	if (top + 1 == size)
		printf("Stack is Full");
	else {
		expr[++top] = a;
	}
}
//EAS*Y*QUE***ST***IO*N***

char pop() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return '\0';  
    } else {
    	printf("%c ",expr[top--]);
        return expr[top];
    }
}

char peek() {
	if (top == -1){
		printf("Stack is Empty");
		return '\0';
	}
	else{
		printf("Top element: %c",expr[top]);
		return expr[top];
	}
}

void check(char e){
	if (e == '*' ){
		pop();
	}
	else
		push(e);
}

int main(){
	int i;
	printf("Enter the String:");
	scanf("%s",expr);
	for (i = 0;expr[i] != '\0'; i++){
		check(expr[i]);
	}
	while (top != -1){
		pop();
	}
	return 0;
}

