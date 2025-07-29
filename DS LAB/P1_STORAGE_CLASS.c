/*Program 1 USE DIFFERENT STORAGE CLASSES (LOCAL,GLOBAL,STATIC,REGISTER)
@ALBIN MAMMEN MATHEW
16/07/2025
*/

#include <stdio.h>
int a=10;	//intialising global variable
void disp(){
	int i=3;	//intialising local variable
	printf("this is a local variable : %d \n",i);
}
int main(){
	static int c;//intialising static varible
	register int p=4; //intialising register variable
	printf("this is a static variable : %d \n",c);
	printf("this is a global variable : %d \n",a);
	printf("this is a register variable : %d \n",p);
	disp();
	return 0;
}
