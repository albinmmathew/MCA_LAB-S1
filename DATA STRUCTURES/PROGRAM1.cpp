//Program 1
#include <stdio.h>
int a=10;	//this is a global variable
void disp(){
	int i=3;	//this is a local variable
	printf("this is a local variable : %d \n",i);
}
int main(){
	static int c;//this is a static varible
	register int p=4; //this is a register variable
	printf("this is a static variable : %d \n",c);
	printf("this is a global variable : %d \n",a);
	printf("this is a register variable : %d \n",p);
	disp();
	return 0;
}
