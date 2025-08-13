#include<stdio.h>
#include<malloc.h>
struct book{
	char bname[20];
	char aname[20];
	float price;
	struct book *next;
};

int main(){
	struct book *first,*t;
	char ch;
	first=(struct book *)malloc(sizeof(struct book));
	t=first;
	do{
		printf("Enter the book name, author name, price:");
		scanf("%s %s %f",t->bname,t->aname,&t->price);
		printf("Add another book (y/n)");
		ch=getchar();
		ch=getchar();
		if(ch=='y'|| ch=='Y'){
			t->next=(struct book *)malloc(sizeof(struct book));
			t=t->next;
		}else{
			t->next=NULL;
		}
	}while(ch=='y'||ch=='Y');
	t=first;
	while(t!=NULL){
		printf("%s\t%s\t%f\n",t->bname,t->aname,t->price);
		t=t->next;
	}
	free(first);
	return 0;
}
