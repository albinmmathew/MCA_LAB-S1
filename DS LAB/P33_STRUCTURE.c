/*PROGRAM 33 DATE USING STRUCTURE
@ALBIN MAMMEN MATHEW
Roll No: 08
19/09/2025
*/

#include<stdio.h>
struct date {
	int day, month, year;
};
typedef struct date date;
void read(date *d) {
	printf("\nEnter the date (dd-mm-yyy) : ");
	scanf("%d-%d-%d", &d->day, &d->month, &d->year);
}
void display(date d){
	printf("Given Date is %d/%d/%d \n",d.day,d.month,d.year);
}
void comparedate(date d, date e) {
	if (d.day == e.day && d.month == e.month && d.year == e.year)
		printf("Dates are same.\n");
	else 
		printf("The dates are  not same.\n");
}
int main () {
	date d1, d2;
	read(&d1);
	display(d1);
	read(&d2);
	display(d2);
	comparedate(d1,d2);
	return 0;
}
