/*PROGRAM-12 STACK OPERATIONS USING ARRAY
@ALBIN MAMMEN MATHEW
23/07/2025
*/

#include <stdio.h>

int push(int stack[5], int top, int e){ //function to push elements onto stack
    if (top + 1 == 5){
        printf("Error: Stack is Full\n");
    } else {
        stack[++top] = e;
        printf("Pushed\n");
    }
    return top;
}

int pop(int stack[5], int top){ //function to pop the top element from stack
    if (top == -1){
        printf("Error: Stack is Empty\n");
    }else{
        printf("Popped element: %d\n", stack[top--]);
    }
    return top;
}

void peek(int stack[5], int top){ //function to peek the top element in stack
    if (top ==-1){
    	printf("Stack is Empty\n");
	}else{
		printf("Top element: %d \n",stack[top]);
	}
}

int menu() { //function for menu interface
    int ch;
    printf("\nPush - 1\nPop - 2\nPeek - 3\nExit - 4\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}

void processStack() { //working of menu
    int stack[5], top = -1;
    int ch, value;
    for (ch = menu(); ch != 4; ch = menu()) {
        switch (ch) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                top = push(stack, top, value);
                break;
            case 2:
                top = pop(stack, top);
                break;
            case 3:
                peek(stack, top);
                break;
            default:
                printf("Error: Wrong Choice.\n");
        }
    }
}

int main() {
    processStack();
    return 0;
}
