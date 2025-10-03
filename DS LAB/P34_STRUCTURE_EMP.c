/*PROGRAM 23 EMPLOYEE MANAGEMENT USING STRUCTURE
@ALBIN MAMMEN MATHEW
19/09/2025
*/

#include<stdio.h>
struct employees {
	int eno;
	char ename[20];
	int  esal, dno;
	struct employees *next;
};
typedef  struct employees emp;
emp *head = NULL;
void read(){
	if (head == NULL){
		head = (emp*)malloc(sizeof(emp));
	}
	else{
		emp *temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		printf("Enter Employee No, Name, Salary, Dept No:\n");
		scanf("%d%s%d%d",&temp->eno, temp->ename, &temp->dno, &temp->esal);
		temp -> next = NULL;
	}
}
void delete(){
	display();
	int d;
	printf("Enter the id to delete:");
	scanf("%d",&d);
	
	
}
void search(){
	
}
void sort(){
	int z;
	for (z = -1; z != 1 || z != 2 || z!= 3; ){
		printf("Sort By :\n 1. Name\n 2. Salary \n3. Exit ");
		scanf("%d",&z);
	}
	if(z == 1){
		
		printf("Sorted by Name");
	}
	else if(z == 2){
		
		printf("Sorted by Salary");
	}
	else 
		return;
}
int main() {
	return 0;
}
