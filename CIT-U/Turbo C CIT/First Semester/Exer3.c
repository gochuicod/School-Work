//Problem Description: A program that disseminates the values according to it's denominations in sequential form

#include <stdio.h>

int main (){		
	int amt, b1, b2, b3, b4, b5, b6, b7, b8, b9;
		
	printf ("Enter amount:");scanf("%d",&amt);
	
		b1 = amt / 1000;
		b2 = amt % 1000 / 500;
		b3 = amt % 1000 % 500 / 200;
		b4 = amt % 1000 % 500 % 200 / 100;
		b5 = amt % 1000 % 500 % 200 % 100 / 50;
		b6 = amt % 1000 % 500 % 200 % 100 % 50 / 20;
		b7 = amt % 1000 % 500 % 200 % 100 % 50 % 20 / 10;
		b8 = amt % 1000 % 500 % 200 % 100 % 50 % 20 % 10 / 5;
		b9 = amt % 1000 % 500 % 200 % 100 % 50 % 20 % 10 % 5 / 1;
	
			printf ("Denominations:\n");
			printf ("1000:%d\n", b1);
			printf ("500 :%d\n", b2);
			printf ("200 :%d\n", b3);
			printf ("100 :%d\n", b4);
			printf ("50  :%d\n", b5);
			printf ("20  :%d\n", b6);
			printf ("10  :%d\n", b7);
			printf ("5   :%d\n", b8);
			printf ("1   :%d\n", b9);	
	return 0;
}
