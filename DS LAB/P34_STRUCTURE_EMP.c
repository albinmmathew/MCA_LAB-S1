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
void read(){
	
}
void delete(){
	
}
void search(int empno){
	
}
void sort(emp emp){
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
	emp emp;
	free(emp);
	return 0;
}
