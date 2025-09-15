#include<stdio.h>
int a=10,b=10;  //global var
void display() {
    int c=10;
    static int d=10;    //static var
    printf("%d\t%d\n",c++,d++);
}
int main(){
    register int e=11;  //register var
    int b=5;    //local var
    printf("Global variable: %d\nLocal variable: %d\n",a,b);
    printf("Register variable: %d",e);
    printf("Static variable: \n");
    display();
    display();
    return 0;
}
