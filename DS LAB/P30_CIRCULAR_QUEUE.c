/*Program 30 CIRCULAR QUEUE
@ALBIN MAMMEN MATHEW
Roll No: 08
Date: 06/08/2025
*/

#include<stdio.h>
int q[5],front=-1,rear=-1;
void enqueue(int v){
	if ((rear+1)%5==front){
		printf("Error:Queue is Full.\n");
	}else{
		if(front==-1)
			front=0;
		rear=(rear+1)%5;
		q[rear]=v;
		printf("Enqueued\n");
	}
}

void dequeue(){
	if (front==-1){
		printf("Error: Empty Queue.\n");
	}
	else{
		printf("Disqueued Element: %d",q[front]);
		if (front==rear){
			front=rear=-1;
		}else{
			front=(front+1)%5;
		}
	}
}

void display(){
	if (front==-1){
		printf("Error: Empty Queue.\n");
	}else{
		int i;
		for(i=front;;i=(i+1)%5){
			printf("%d \t",q[i]);
			if(i==rear)
				break;
		}
		printf("\n");
	}
}
int menu(){ //function for menu
	int ch;
	printf("\n ENQUEUE-1 \n DEQUEUE-2 \n DISPLAY-3 \n EXIT -4 \n Enter your choice : ");
	scanf("%d",&ch);
	return ch;
}
void processQueue(){ //working of menu
	int ch,b;
	for (ch=menu();ch!=4;ch=menu()){
		switch(ch){
			case 1:
				printf("Enter the value to insert : ");
				scanf("%d",&b);
				enqueue(b);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			default:
				printf("Error: Wrong Choice");
				break;	
		}
	}
}
int main() {
	processQueue();
	return 0;
}
