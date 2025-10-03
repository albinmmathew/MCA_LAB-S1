/*Program 25 ADDING POLYNOMIAL
@ALBIN MAMMEN MATHEW
Roll No: 08
Date: 08/08/2025
*/

#include<stdio.h>
#define size 10

void read(int poly[], int deg) {
	int i;
	for(i = deg; i >= 0; i--) {
		printf("Enter the coefficient of x^ %d : ",i) ;
		scanf("%d", &poly[i]);
	}
}
void print(int poly[], int deg) {
	int i;
	for(i = deg; i != -1; i--) {
		if(poly[i] == 0)
			continue;
		if(i != deg) {
			if(poly[i] != 0) {
				printf(" + ");
			}
		}
		if(i == 0) {
			printf("%d", poly[i]);
		}else if(i == 1) {
			printf("%dx", poly[i]);
		}else {
			printf("%dx^%d", poly[i], i);
		}
	}
}
void sum(int poly1[], int poly2[], int sum[], int deg1, int deg2){
	int i, deg = deg1;
	if(deg1 < deg2)
		deg = deg2;
	for(i = 0; i <= deg; i++) {
		sum[i] = 0;
		sum[i] = poly1[i] + poly2[i];
	}
	print(sum,deg);
}
int main() {
	int poly1[size], poly2[size], s[size], deg1, deg2;
	printf("Enter the degree of polynomial 1: ");
	scanf("%d", &deg1);
	read(poly1, deg1);
	printf("Enter the degree of polynomial 2: ");
	scanf("%d", &deg2);
	read(poly2, deg2);
	sum(poly1, poly2, s, deg1, deg2);
	return 0;
}	
