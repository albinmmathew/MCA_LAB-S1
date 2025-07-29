/*PROGRAM-3 A MENU FOR ARRAY OPERATIONS(INSERT,DELETE,DISPLAY,SEARCH,SORT) USING LOCAL VARIABLE
@ALBIN MAMMEN MATHEW
16/07/2025
*/

#include <stdio.h>
int insert(int a[5], int pos, int e) //function to insert an element
{
    if (pos + 1 == 5)
    {
        printf("Error: Array is Full\n");
    }
    else
    {
        a[++pos] = e;
    }
    return pos;
}

int erase(int a[5], int pos) //function to delete top element
{
    if (pos == -1)
    {
        printf("Error: Array is Empty\n");
    }
    else
    {
        printf("Deleted element: %d\n", a[pos--]);
    }
    return pos;
}

void display(int a[5], int pos) //function to display entire array
{
    if (pos == -1)
    {
        printf("Error: Array is Empty\n");
    }
    else
    {
    	int i;
        for (i = 0; i <= pos; i++)
        {
            printf("%d\t", a[i]);
        }
        printf("\n");
    }
}

void search(int b,int a[5],int pos){ //function to search for an element throughout the array and display its index
	int isfound=0,i;
	for (i=0;i<=pos;i++){
		if(b==a[i]){
			isfound=1;
			printf("Element found at [%d] position. \n",i);
		}
	}
	if(isfound==0)
		printf("element not found");
}

void sort(int a[5]){	//function to sort the stack
	int i,j,temp;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(a[i]<a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}

int menu() //function to create menu interface
{
    int ch;
    printf("\nInsert - 1\nDelete - 2\nDisplay - 3\nSearch - 4\nSort - 5\nExit - 6\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}

void processArray() //working of menu
{
    int a[5], pos = -1,b;
    int ch, value;
    for (ch = menu(); ch != 6; ch = menu())
    {
        switch (ch)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                pos = insert(a, pos, value);
                break;
            case 2:
                pos = erase(a, pos);
                break;
            case 3:
                display(a, pos);
                break;
            case 4:
            	printf("Enter the element to search: ");
            	scanf("%d",&b);
            	search(b,a,pos);
            	break;
            case 5:
            	sort(a);
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
