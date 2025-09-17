#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define s 20
char stack[s],expr[s],post[s];
int top =-1,j=0;
void push(char e){		//Function to insert element into stack
	stack[++top]=e;  
}
char pop() //function to delete top element
{
	if (top==-1){
		printf("Error: Stack is empty");
		return '\0';
	}else{
		return stack[top--];
	}	
}

char peek(){
	if (top==-1){
		return '\0';
	}else{
		return stack[top];
	}	
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

char chariden(char d){
	if(isalnum(d)){
		return 'n';
	}else if(isOperator(d)){
		return 'o';
	}else if (d == '(' || d == ')') {
		return 'p';
	}else
		return 'x';
}

int postcedence(char d) {
    switch(d) {
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default : return 0;
    }
}

void number(char d){
	post[j++]=d;
}

void oper(char d) {
	int e,f;
	e=postcedence(d);
	f=postcedence(peek());
    while (top != -1 && isOperator(peek()) && (((e < f) || (e==f )))) {
        post[j++] = pop();
    }
    push(d);
}


void para(char d) {
    if (d == '(') {
        push(d);
    } else if (d == ')') {
        while (top != -1 && peek() != '(') {
            post[j++] = pop();
        }
        if (peek() == '(')
            pop();  // Remove '(' from stack
        else
            printf("Error: Mismatched parentheses\n");
    }
}

void reverse(char str[20]) { //function to reverse the string
    int i = 0, j;
    char temp;
    j = strlen(str) - 1;
    while (i < j) { //swaping end characters
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    for (i=0;i<20;i++){
    	if (str[i]=='(')
    		str[i]=')';
    	if (str[i]==')')
    		str[i]='(';
	}
}

void IntoPost(char expr[s]){
	int i;
	char c,d;
	for(i=0;expr[i]!='\0';i++){
		d=expr[i];
		c=chariden(d);
		switch(c){
			case 'o':
				oper(d);
				break;
			case 'n':
				number(d);
				break;
			case 'p':
				para(d);
				break;
			default:
				break;
		}
	}
	while (top != -1) {
        if (peek() == '(') {
            printf("Error: Mismatched parentheses\n");
            pop();
        } else {
            post[j++] = pop();
        }
    }
    post[j] = '\0';  // Null terminate postfix string
    printf("postfix Expostssion: %s\n", post);
} 



int main(){
	printf("Enter the expr: ");
	scanf("%s",expr);
	IntoPost(expr);
	return 0;
}
