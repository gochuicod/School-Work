/*
Name: Darelle Gochuico
Date: 11/14/19
Description: Write a program that displays the given pattern with the use of while loop.
*/

#include <stdio.h>
int getNum();
void display (int n);

int main(){
	int n;
	char rep, num;
	do{
	printf ("\nEnter a number: ");
	n = getNum();
	if (n < 0){
		printf ("\nPlease enter a positive integer.");
		rep = 'y';
	} else
	
	display(n);
	printf ("\nContinue?");
	rep = getche(num);
	}while (rep == 'y' || rep == 'Y');
	
	return 0;
}

int getNum(){
	int num;
		scanf ("%d", &num);
	return num;
}

void display (int n){
	int row = n, col = 1;
	int c = 1;
	
	while (row <= n){
		while (col <= row){
			printf ("%d", col);
			col++;
			printf ("\n");
		}
		row++;
	}

	return;
}
