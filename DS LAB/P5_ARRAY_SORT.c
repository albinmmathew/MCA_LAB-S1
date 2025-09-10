/*PROGRAM-5 SORT ARRAY IN ASC WITH ALTEAST 3 FUNCTIONS - READ DISP SORT
@ALBIN MAMMEN MATHEW
23/07/2025
*/

#include<stdio.h>
void read(int n,int arr[n]){ //function to insert elements in array
	int i;
	for(i=0;i<n;i++){
		printf("Enter the value for %d :",i);
		scanf("%d",&arr[i]);
	}
}

void disp(int n,int arr[n]){ //function to display all elemenyts in array 
	int i;
	for (i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
}

void sort(int n,int arr[n]){ //function for sorting the elements in array in ascending order
	int i,j,temp;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}


int menu(){ //funtion for menu interface
	int ch;
	printf("\nREAD-1\nSORT-2\nDISPLAY-3\nEXIT-4\nENTER YOUR CHOICE : ");
	scanf("%d",&ch);
	return ch;
}

void processArray(int n,int arr[n]){ //working of menu
	int ch;
	for (ch=menu();ch!=4;ch=menu()){
		switch(ch) {
			case 1:
				read(n,arr);
				break;
			case 2:
				sort(n,arr);
				break;
			case 3:
				disp(n,arr);
				break;
			default:
				printf("Errror: Wrong Choice\n");
				break;
		}
	}
}
int main(){
	int n;
	printf("Enter limit of Array:");
	scanf("%d",&n);
	int arr[n];
	processArray(n,arr);
	return 0;
}
