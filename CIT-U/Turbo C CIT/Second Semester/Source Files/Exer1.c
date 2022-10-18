/*
Name: Darelle Gochuico
Date: 11/7/19
Description: Enter three numbers and display the given characters.
*/
#include <stdio.h>
void display(int a, int b, int c);
int getNum();

int main(){
	int a,b,c;
	char rep, num;
	
	do {
		system("cls");
		printf ("Please enter a number for A:");
		a = getNum();
		printf ("Please enter a number for B:");
		b = getNum();
		printf ("Please enter a number for C:");
		c = getNum();
		
		if (a < 0 || b < 0 || c < 0) {
			printf ("\nPlease enter positive integers.");
			rep = 'y';
		
		} else 
		
		display(a,b,c);
		printf ("\n\nDo you want to continue?");
		rep = getche(num);
		
	}while (rep == 'y' || rep == 'Y');
		
	return 0;
}

int getNum(){
		int num;
			scanf ("%d", &num);
	return num;
}

void display(int a, int b, int c){		
	int row, highest;
	
		if(a >= b && a >= c){
			highest = a;
		} else if (b >= a && b >= c){
			highest = b;
		} else {
			highest = c;
		}
		
			printf ("\n%d %d %d",a,b,c);
			printf ("\n");
		
		for (row = 1; row <= highest; row++){
			if (row <= a){
				printf ("* ");
			} else {
				printf ("  ");
			}
			if (row <= b){
				printf ("X ");
			} else {
				printf ("  ");
			}
			if (row <= c){
				printf ("@");
			} else {
				printf ("  ");
			}
			printf ("\n");
		}	
		
		
	return;
}
