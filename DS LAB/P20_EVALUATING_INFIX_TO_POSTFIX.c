/*Program 20    EVALUATING INFIX TO POSTFIX EXPRESSION
@ALBIN MAMMEN MATHEW
Roll No: 08
Date: 15/9/2025
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define s 20

char stack[s], expr[s], post[s];
int top = -1, j = 0;


void push(char e) { stack[++top] = e; } // Function to insert element into stack

char pop() { // Function to delete top element
	if (top == -1) {
		printf("Error: Stack is empty");
		return '\0';
	} else {
		return stack[top--];
	}
}

char peek() { // Function to return top element
	if (top == -1) {
		return '\0';
	} else {
		return stack[top];
	}
}

int isOperator(char c) { return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'); } // Function to check if character is operator

char chariden(char d) { // Function to identify character type
	if (isalnum(d)) {
		return 'n';
	} else if (isOperator(d)) {
		return 'o';
	} else if (d == '(' || d == ')') {
		return 'p';
	} else {
		return 'x';
	}
}

int precedence(char d) { // Function to return precedence of operators
	switch (d) {
		case '^': return 3;
		case '*':
		case '/': return 2;
		case '+':
		case '-': return 1;
		default: return 0;
	}
}

void oper(char d) { // Function to handle operator
	int e, f;
	e = precedence(d);
	f = precedence(peek());
	while (top != -1 && isOperator(peek()) && (e <= f)) {
		post[j++] = pop();
		f = precedence(peek());
	}
	push(d);
}

void para(char d) { // Function to handle parenthesis
	if (d == '(') {
		push(d);
	} else if (d == ')') {
		while (top != -1 && peek() != '(') {
			post[j++] = pop();
		}
		if (peek() == '(')
			pop(); // Remove '(' from stack
		else
			printf("Error: Mismatched parentheses\n");
	}
}

void IntoPost(char expr[s]) { // Function to convert infix to postfix
	int i;
	char c, d;
	for (i = 0; expr[i] != '\0'; i++) {
		d = expr[i];
		c = chariden(d);
		switch (c) {
			case 'o':
				oper(d);
				break;
			case 'n':
				post[j++] = d;
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
	post[j] = '\0'; // Null terminate postfix string
	printf("postfix Expression: %s\n", post);
}

int evaluatePostfix(char post[s]) { // function to evaluate postfix expression
	int i = 0, vstack[100], vtop = -1;
	int v1, v2;
	while (post[i] != '\0') {
		if (isdigit(post[i])) {
			vstack[++vtop] = post[i] - '0'; // Convert char to int
		} else if (isOperator(post[i])) {
			v2 = vstack[vtop--];
			v1 = vstack[vtop--];
			vstack[++vtop] = apply(v1, v2, post[i]);
		}
		i++;
	}
	return vstack[vtop];
}

int main() {
	printf("Enter the infix expression: ");
	scanf("%s", expr);
	printf("The infix expression:\n%s\n", expr);
	IntoPost(expr);
	printf("The postfix expression:\n%s\n", post);
	printf("The evaluated result is: %d\n", evaluatePostfix(post));
	return 0;
}
int main() {
	printf("Enter the infix expression: ");
	scanf("%s", expr);
	printf("The infix expression:\n%s\n", expr);
	IntoPost(expr);
	printf("The postfix expression:\n%s\n", post);
	printf("The evaluated result is: %d\n", evaluatePostfix(post));
	return 0;
}
