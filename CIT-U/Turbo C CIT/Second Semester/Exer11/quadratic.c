#include <stdio.h>
#include <math.h>
#include <windows.h>
#include "quadratic.h"

void discriminant(Quadratic *q){
		gotoxy(40,2);printf_s("Enter value of a: ");scanf_s("%f",&q->a);// This is how a pointer is declared to use *q and point it to variables in a defined structure
			gotoxy(40,3);printf_s("Enter value of b: ");scanf_s("%f",&q->b);
				gotoxy(40,4);printf_s("Enter value of c: ");scanf_s("%f",&q->c);
	return;
}

int isImaginary(Quadratic *q){
	Quadratic point;
		if (q->a < 0 || q->b < 0 || q->c < 0){// q->a has the value stored in discriminant similar to the rest
			gotoxy(48,3);puts("Imaginary");
			return 1;
		} else {
			gotoxy(46,3);puts("Not Imaginary");
			return 0;
		}
}

float firstRoot(Quadratic *q){
	float root;
		root = (-q->b + sqrt(pow(q->b,2) - 4 * q->a * q->c))/(2 * q->a);
	return root;
}

float secondRoot(Quadratic *q){
	float root;
		root = ((-q->b - sqrt(pow(q->b,2) - 4 * q->a * q->c))/(2 * q->a));
	return root;
}

void display(Quadratic *q){
		printf("a:%.2f, b:%.2f, c:%.2f",q->a,q->b,q->c);
	return;
}

int getValue(Quadratic q, int x){
	int value;
		value = (q.a * pow(x,2)) + (q.b*x) + q.c;
	return value;
}

void menu(){
		gotoxy(9, 2);printf_s ("Two-dimensional Array");
		gotoxy(10, 4);printf_s ("1. Discriminant");
		gotoxy(10, 5);printf_s ("2. Imaginary");
		gotoxy(10, 6);printf_s ("3. 1st Root");
		gotoxy(10, 7);printf_s ("4. 2nd Root");
		gotoxy(10, 8);printf_s ("5. Display");
		gotoxy(10, 9);printf_s ("6. X-Value");
		gotoxy(10, 10);printf_s ("7. Exit");
		gotoxy(10, 12);printf_s ("Choice: ");
	return;
}

void Exit(){
		system("cls");printf_s("Exiting...");
	return;
}
