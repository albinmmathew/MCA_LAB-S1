/*Program 19    EVALUATION OF INFIX EXPRESSION
@ALBIN MAMMEN MATHEW
Roll No: 08
Date: 15/9/2025
*/


#include <stdio.h>
#include <ctype.h>

int precedence(char op) { // function to return precedence of operators
	switch (op) {
		case '/':
		case '*': return 1;
		case '+':
		case '-': return 0;
	}
	return -1;
}

int apply(int a, int b, char sign) { // function to apply the operator on two operands
	switch (sign) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
	}
	return 0;
}

int evaluate(char a[100]) { // function to evaluate infix expression
	int i = 0, vstack[100], vtop = -1, otop = -1;
	char opstack[100], sign;
	int v1, v2;
	int number = 0; // variable to store the parsed number

	while (a[i] != '\0') {
		if (isdigit(a[i])) {
			number = 0;
			while (isdigit(a[i])) {
				number = number * 10 + (a[i] - '0');
				i++;
			}
			vstack[++vtop] = number;
			continue; // Go to the next character in the outer loop
		} else if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/') {
			while (otop != -1 && precedence(opstack[otop]) >= precedence(a[i])) {
				v2 = vstack[vtop--];
				v1 = vstack[vtop--];
				sign = opstack[otop--];
				vstack[++vtop] = apply(v1, v2, sign);
			}
			opstack[++otop] = a[i];
		}
		i++;
	}

	while (otop != -1) {
		v2 = vstack[vtop--];
		v1 = vstack[vtop--];
		sign = opstack[otop--];
		vstack[++vtop] = apply(v1, v2, sign);
	}
	return vstack[0];
}

int main() {
	char a[100];
	int result;
	printf("enter infix expression: ");
	scanf("%s", a);
	result = evaluate(a);
	printf("RESULT: %d", result);
	return 0;
}

