#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node node;
node *head = NULL;

void insert(int a){
	node *t;
	if(head == NULL){
		head = (node *)malloc(sizeof(node));
		head -> data = a;
		head -> next = NULL;
	}
	else {
		t = head;
		while (t -> next != NULL) {
			t = t->next;
		}
		t -> next = (node *)malloc(sizeof(node));
		t -> next -> data = a;
		t -> next -> next = NULL;
	}
}

void delete(int a){
	node *t;
	if (head == NULL){
		printf("EMPTY LINKED LIST\n");
	}
	else if (head -> data == a){
		head = head -> next; 
	} else {
		t = head;
		while (t -> next != NULL && t -> next -> data !=  a) {
			t = t->next;
		}
		if (t -> next == NULL){
			printf("Element not found");
		}
		else {
			t -> next = t -> next -> next;
		}
	}
}

void display(){ 
	node *t;
	t = head;
	if (t == NULL)
		printf("EMPTY LINKED LIST\n");
		
	while (t != NULL ) {
		printf("%d \t ", t -> data);
		t = t -> next;
	}
	printf("\n");
}

void fire(int a, int b){
	node *t = head;
	int iffound = 0;
	if (head == NULL){
		printf("EMPTY LINKED LIST");
		return;
	}
	else {
		while (t != NULL ) {
			if(t -> data == a){
				t -> data = b;
				iffound = 1;
			}
			t = t -> next;
		}
	}
	if (iffound == 1){
		printf("Element Found & Replaced");
	} else {
		printf("Element not  Found");
	}
}

void search(int a) {
	node *t = head;
	int iffound = 0;
	if (head == NULL){
		printf("EMPTY LINKED LIST");
		return;
	} else {
		while (t != NULL ) {
			if(t -> data == a){
				iffound = 1;
				break;
			}
			t = t -> next;
		}
	}
	if (iffound == 1){
		printf("Element Found");
	} else {
		printf("Element not  Found");
	}
}

void count(){
	node *t;
	int c = 0;
	t = head;
	if (t == NULL){
		printf("EMPTY LINKED LIST");
		return;
	}
	else {
		while (t != NULL ) {
			c++;
			t = t -> next;
		}
	}
	printf("Number of elements in the linked list: %d", c);
}

void sort(){
	node *t1, *t2;
	int temp;
	if (head == NULL){
		printf("EMPTY LINKED LIST");
		return;
	}
	else {
		for (t1 = head; t1 != NULL; t1 = t1 -> next) {
			for (t2 = t1 -> next; t2 != NULL; t2 = t2 -> next) {
				if (t1 -> data > t2 -> data) {
					temp = t1 -> data;
					t1 -> data = t2 -> data;
					t2 -> data = temp;
				}
			}
		}
	}
}

/*
void reverse(){
	node *prev, *curr, *next;
	prev = NULL;
	curr = head;
	if (head == NULL){
		printf("EMPTY LINKED LIST");
		return;
	}
	else {
		while (curr != NULL) {
			next = curr -> next;
			curr -> next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}
} 
*/

int menu() {
	int ch;
	printf("\nINSERT-1\nDELETE-2\nDISPLAY-3\nFIND & REPLACE-4\nSearch-5\nCount-6\nReverse-7\nSort-8\nEXIT-9\n");
	printf("Enter Your Choice:");
	scanf("%d",&ch);
	return ch;
}

void processmenu(){
	int ch, a, b;
	for (ch = menu(); ch != 9; ch = menu()) {
		switch(ch) {
			case 1 :
				printf("Enter the element to insert: ");
				scanf("%d",&b);
				insert(b);
				break;
			case 2 :
				printf("Enter the element to delete: ");
				scanf("%d",&b);
				delete(b);
				break;
			case 3 :
				display();
				break;
			case 4 :
				printf("Enter the element to find: ");
				scanf("%d",&a);
				printf("Enter the element to replace: ");
				scanf("%d",&b);
				fire(a,b);
				break;
			case 5 :
				printf("Enter the element to search: ");
				scanf("%d",&a);
				search(a);
				break;
			case 6 :
				count();
				break;
			/*case 7 :
				reverse();
				break;*/
			case 8 :
				sort();
				break;
			default :
				printf("Error: Unknown Option Selected");
		}
	}
}

int main(){
	processmenu();
	return 0;
}