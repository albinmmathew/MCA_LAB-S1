/*PROGRAM 50 LINKED LIST FUNCTIONS - INSERT DELETE DISPLAY SORT REVERSE COUNT
@ALBIN MAMMEN MATHEW
Roll No: 08
26/09/2025
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for a node
struct node{
	char name[50];
	struct node *next;
};
typedef struct node node;
node *head = NULL;

//Function to insert a name at the end
void insert(char a[]) {
	node *t;
	if(head == NULL){
		head = (node *)malloc(sizeof(node));
		strcpy(head->name, a);
		head->next = NULL;
	}
	else {
		t = head;
		while (t->next != NULL) {
			t = t->next;
		}
		t->next = (node *)malloc(sizeof(node));
		strcpy(t->next->name, a);
		t->next->next = NULL;
	}
}

// Function to delete a name
void delete(char a[]) {
	node *t;
	if (head == NULL){
		printf("EMPTY LINKED LIST\n");
	}
	else if (strcmp(head->name, a) == 0){
		head = head->next; 
	} else {
		t = head;
		while (t->next != NULL && strcmp(t->next->name, a) != 0) {
			t = t->next;
		}
		if (t->next == NULL){
			printf("Element not found");
		}
		else {
			t->next = t->next->next;
		}
	}
}

// Function to display all names
void display(){ 
	node *t;
	t = head;
	if (t == NULL)
		printf("EMPTY LINKED LIST\n");
		return;
	while (t != NULL ) {
		printf("%s \t ", t->name);
		t = t->next;
	}
	printf("\n");
}

// Function to sort names alphabetically
void sort(){
	node *t1, *t2;
	char temp[50];
	if (head == NULL){
		printf("EMPTY LINKED LIST");
		return;
	}
	else {
		for (t1 = head; t1 != NULL; t1 = t1->next) {
			for (t2 = t1->next; t2 != NULL; t2 = t2->next) {
				if (strcmp(t1->name, t2->name) > 0) {
					strcpy(temp, t1->name);
					strcpy(t1->name, t2->name);
					strcpy(t2->name, temp);
				}
			}
		}
	}
}

// Function to reverse the linked list
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

// Function to count nodes
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

int menu() {
	int ch;
	printf("\nINSERT-1\nDELETE-2\nDISPLAY-3\nSORT-4\nREVERSE-5\nCOUNT-6\nEXIT-7\n");
	printf("Enter Your Choice:");
	scanf("%d",&ch);
	return ch;
}

void processmenu(){
	int ch;
	char name[50];
	for (ch = menu(); ch != 7; ch = menu()) {
		switch(ch) {
			case 1 :
				printf("Enter the name to insert: ");
				scanf("%s", name);
				insert(name);
				break;
			case 2 :
				printf("Enter the name to delete: ");
				scanf("%s", name);
				delete(name);
				break;
			case 3 :
				display();
				break;
			case 4 :
				sort();
				break;
			case 5 :
				reverse();
				break;
			case 6 :
				count();
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
