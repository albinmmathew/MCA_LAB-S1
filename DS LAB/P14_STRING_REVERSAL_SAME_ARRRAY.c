/* PROGRAM-14 STRING REVERSAL IN THE SAME ARRRAY 
@ALBIN MAMMEN MATHEW
29/07/2025
*/

#include <stdio.h>
#include <string.h>

void reverse(char str[20]) { //function to reverse the string
    int i = 0, j;
    char temp;
    j = strlen(str) - 1;
    while (i < j) { //swaping end characters
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int main() {
    char str[20];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
	printf("String is %s",str);
    reverse(str);
    printf("Reversed string : %s\n", str);
    return 0;
}

