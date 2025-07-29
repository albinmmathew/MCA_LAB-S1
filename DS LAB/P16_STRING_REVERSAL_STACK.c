/* PROGRAM-16 STRING REVERSAL USING STACK
@ALBIN MAMMEN MATHEW
29/07/2025
*/

#include <stdio.h>
char stack[100];
int top=-1;
void push(char e) //function to push elements onto stack
{
    if (top + 1 == 100)
    {
        printf("Error: Stack is Full\n");
    }
    else
    {
        stack[++top] = e;
        printf("%c",e);
    }
}

void pop() //function to top pop element from stack
{
    if (top == -1)
    {
        printf("Error: Stack is Empty\n");
    }
    else
    {
        printf("%c", stack[top--]);
    }
}

void peek() //function to display the top element of the stack
{
    int i;
    if (top ==-1){
    	printf("Stack is Empty\n");
	}
	else{
		printf("%c \n",stack[top]);
	}
}

int menu()
{
    int ch;
    printf("\nPush - 1\nPop - 2\nPeek - 3\nReverse - 4\nExit - 5\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}

void processArray()
{
    int ch;
	char value;
    for (ch = menu(); ch != 5; ch = menu())
    {
        switch (ch)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf(" %c",&value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
            	while (top!=-1){	//function to pop all elements to print reverse
            		pop();
				}
				break;
			default:
                printf("Error: Wrong Choice.\n");
        }
    }
}

int main()
{
    processArray();
    return 0;
}

