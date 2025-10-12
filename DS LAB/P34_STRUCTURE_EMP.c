//Define a structure for employees with eno,ename, esal and dno. Read  n employees information and provide functions for the following:  
//a.Searching an employee by no
//b.Sorting the employees by
//            i.Name
//			 ii.Salary
//c.Deleting an employee

/*PROGRAM 34 EMPLOYEE MANAGEMENT USING STRUCTURE
@ALBIN MAMMEN MATHEW
19/09/2025
*/

#include <stdio.h>
#define max 100

struct employees {
	int eno, dno;
	char ename[20];
	float esal;
};
typedef  struct employees emp;
emp emplist[100];
int count = 0;


void insert(){
	printf("Enter the employee no :");
	scanf("%d",&emplist[count].eno);
	printf("Enter the employee name :");
	scanf("%s",emplist[count].ename);
	printf("Enter the employee salary :");
	scanf("%f",&emplist[count].esal);
	printf("Enter the department no :");
	scanf("%d",&emplist[count].dno);
	printf("Data inserted\n");
	count++;	
}

void delete(){
	int del, i, found = 0;
	printf("\nEnter employee number to delete: ");
	scanf("%d", &del);
	for (i = 0; i < count; i++) {
		if (emplist[i].eno == del) {
			found = 1;
			break;
		}
	}
	if (found) {
		for (; i < count - 1; i++) {
			emplist[i] = emplist[i + 1];
		}
		count--;
		printf("Employee deleted.\n");
	} else {
		printf("Employee not found.\n");
	}
}

void display(){
	int i;
    if (count == 0) {
        printf("\nNo employees to display.\n");
        return;
    }
    printf("\n%-10s %-20s %-10s %-10s\n", "EmpNo", "Name", "Salary", "DeptNo");
    printf("------------------------------------------------------\n");

    for (i = 0; i < count; i++) {
        printf("%-10d %-20s %-10f %-10d\n",
               emplist[i].eno, emplist[i].ename, emplist[i].esal, emplist[i].dno);
    }
}

void search(){
	int no, i, found = 0;
	printf("\nEnter employee number to search: ");
	scanf("%d", &no);
	for (i = 0; i < count; i++) {
		if (emplist[i].eno == no) {
			found = 1;
			break;
		}
	}
	if (found) {
		printf("%-10d %-20s %-10f %-10d\n", emplist[i].eno, emplist[i].ename, emplist[i].esal, emplist[i].dno);
	} else {
		printf("Employee not found.\n");
	}
}

void sort(){
	printf("1. Sort by Name\n2. Sort by Salary\n");
	int ch, i, j;
	scanf("%d",&ch);
	if (ch == 1){
		emp temp;
		for(i = 0; i < count; i++) {
			for (j = i + 1; j < count; j++) {
				if (strcmp(emplist[i].ename, emplist[j].ename) > 0) {
					temp = emplist[i];
					emplist[i] = emplist[j];
					emplist[j] = temp;
				}
			}
		}
	}
	else if (ch == 2) {
		emp temp;
		for(i = 0; i < count; i++) {
			for (j = i + 1; j < count; j++) {
				if (emplist[i].esal > emplist[j].esal) {
					temp = emplist[i];
					emplist[i] = emplist[j];
					emplist[j] = temp;
				}
			}
		}
	}
	printf("Employees sorted.\n");
	display();
}

int menu(){
	int ch;
	printf("INSERT - 1\nDELETE - 2\nDISPLAY - 3\nSEARCH - 4\nSORT - 5\nEXIT - 6\n");
	printf("Enter your choice: ");
	scanf("%d",&ch);
	return ch;
}

void processArray(){
	int ch, i, a, size;
	for(ch = menu(); ch != 6; ch = menu()){
		switch (ch) {
			case 1:
				printf("SINGLE  INSERT - 1\nGROUP INSERT -2\n");
				scanf("%d",&a);
				if (a == 1){
					insert();
				}
				else if (a == 2){
					printf("Number of employees to be inserted: ");
					scanf("%d",&size);
					for(i = 0;i < size; i++){
						insert();
					}
				}
				break;
			case 2 :
				delete();
				break;
			case 3 :
				display();
				break;
			case 4 :
				search();
				break;
			case 5 :
				sort();
				break;
			default :
				printf("Invalid choice.\n");
				break;
		}
	}
}

int main(){
	printf("EMPLOYEE DETAILS \n");
	processArray();
}
