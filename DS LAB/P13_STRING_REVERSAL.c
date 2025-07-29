/* PROGRAM-13 STRING REVERSAL
@ALBIN MAMMEN MATHEW
29/07/2025
*/

#include<stdio.h>

void str_rev(char a[20]){ //program to reverse a string
	int i=0;
	while (a[i] != '\0') {
        i++;
    }
	for (;i>=0;i--){
		printf("%c",a[i]);
	}
}

int main(){
	char a[20];
	printf("Enter a String: ");
	gets(a);
	str_rev(a);
	return 0;
}
