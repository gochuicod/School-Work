//Problem Description: A program that determines if the input is a leap year or not

#include <stdio.h>

int getYear();
int isLeapYear(int year);
void display (int res);

int main (){
	int year, res;
		year = getYear();
		res = isLeapYear(year);
		display (res);
return 0;
}

int getYear(){
	int year;
		printf ("Input year:");scanf ("%d",&year);
return year;
}

int isLeapYear(int year){
	int res;
		if (year % 400 == 0 || year % 4 == 0)
			res = 1;
		else if (year % 100 == 0)
			res = 0;
		else
			res = 0;
return res;
}

void display (int res){
	if (res == 1)
		printf ("The year is a leap year");
	else 
		printf ("The year is not a leap year");
return;	
}
