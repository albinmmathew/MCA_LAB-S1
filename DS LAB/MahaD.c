#include<stdio.h>
int top=-1;
int stack[20];
void operation(char c){
    if(c=='*'){
        if(top==-1){
            printf("Stack is empty\n");
        }
        else{
            printf("%c ",stack[top--]);
        }
    }
    else{
        stack[++top]=c;
    }
}
int main(){
    char str[20];
    int i;
    printf("Enter the string: ");
    scanf("%s",str);
    for(i=0;str[i]!='\0';i++){
        operation(str[i]);
    }
    while(top!=-1){
        printf("%c ",stack[top--]);
    }
    return 0;
}
