/* PROGRAM-15 SORTING N STRINGS
@ALBIN MAMMEN MATHEW
29/07/2025
*/

#include <stdio.h>
#include <string.h>
int main() {
    int n, i, j;
    char str[20][100], temp[100];

    printf("Enter the number of strings: ");
    scanf("%d", &n);
    getchar(); // to consume the newline after scanf

    for (i = 0; i < n; i++) {
        printf("Enter string %d: ", i + 1);
        fgets(str[i], sizeof(str[i]), stdin);
        str[i][strcspn(str[i], "\n")] = '\0';  // remove newline
    }

    for (i = 0; i < n - 1; i++) {  // Sort strings using bubble sort
        for (j = i + 1; j < n; j++) {
            if (strcmp(str[i], str[j]) > 0) {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    printf("\nStrings in ascending order:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", str[i]);
    }

    return 0;
}


