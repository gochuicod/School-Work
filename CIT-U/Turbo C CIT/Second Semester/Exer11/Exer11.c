#include <stdio.h>
#include <math.h>
#include <windows.h>

typedef struct {
	float a;
		float b;
			float c;
} Quadratic;

void initialize(Quadratic q);
void discriminant(Quadratic *q, float a, float b, float c);
int isImaginary(Quadratic *q);
float firstRoot(Quadratic *q);
float secondRoot(Quadratic *q);
void display(Quadratic *q);
int getValue(Quadratic q, int x);
void menu();
void Exit();
void drawDBox(int x1, int y1, int x2, int y2);
void gotoxy(int x, int y);
const char *warning = "Enter a valid choice!";

int main(){
	Quadratic q, q1;
	float a,b,c,root;
	int x, choice;
	char num, rep;
	system("color 70");
	initialize(q);
		do{
			system("cls");
				drawDBox(4,0,35,14);menu();//prints menu with box
					drawDBox(37,0,67,6);//prints second box
						gotoxy(18,12);scanf_s("%d",&choice);
							switch(choice){
								case 1:
									gotoxy(40,2);printf_s("Enter value of a: ");scanf_s("%f",&q.a);// This is how a pointer is declared to use *q and point it to variables in a defined structure
										gotoxy(40,3);printf_s("Enter value of b: ");scanf_s("%f",&q.b);
											gotoxy(40,4);printf_s("Enter value of c: ");scanf_s("%f",&q.c);
												discriminant(&q,a,b,c);
									break;
								case 2:
									gotoxy(46,3);printf(isImaginary(&q) == 0 ? "Not Imaginary" : "Imaginary");
									break;
								case 3:
									//gotoxy(50,3);printf(isImaginary(&q) == 0 ? "%.2f" : "ERROR",firstRoot(&q));
									gotoxy(50,3);printf(firstRoot(&q) > 0 || firstRoot(&q) < 0 ? "%.2f" : "Math Error",firstRoot(&q));
									//printf(firstRoot(&q) > 0 ? "%.2f" : (firstRoot(&q) < 0 ? "%.2f" : "Math Error"),firstRoot(&q)); Hint: Use else if with variable in quantity
									break;
								case 4:
									//gotoxy(50,3);printf(isImaginary(&q) == 0 ? "%.2f" : "ERROR",secondRoot(&q));
									gotoxy(50,3);printf(secondRoot(&q) > 0 || firstRoot(&q) < 0 ? "%.2f" : "Math Error",secondRoot(&q));
									break;
								case 5:
									gotoxy(40,3);display(&q);
									break;
								case 6:
									gotoxy(40,2);printf_s("Enter value of x: ");scanf_s("%d",&x);
										gotoxy(40,4);printf_s("Output: %d",getValue(q,x));
									break;
								case 7:
									Exit();
									return 0;
									break;
								default:
									gotoxy(42,3);printf("%s",warning);
							}
									gotoxy(4,16);system("pause");
		}while(rep == '\r' || '\r');
return 0;
}

void initialize(Quadratic q){
		q.a = 0, q.b = 0, q.c = 0;
	return;
}

void discriminant(Quadratic *q, float a, float b, float c){
		q->a, q->b, q->c;
	return;
}

int isImaginary(Quadratic *q){
	Quadratic point;
		if (q->a < 0 || q->b < 0 || q->c < 0){// q->a has the value stored in discriminant similar to the rest
			return 1;
		} else {
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
		gotoxy(10, 2);printf_s ("Quadratic Equations");
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

void drawDBox(int x1, int y1, int x2, int y2){
	int x, y;
			gotoxy(x1,y1);putchar(201);
			gotoxy(x2,y1);putchar(187);
			gotoxy(x2,y2);putchar(188);
			gotoxy(x1,y2);putchar(200);
		for(x = x1 + 1; x < x2; x++){
			gotoxy(x,y1);putchar(205);
			gotoxy(x,y2);putchar(205);
		}
		for(y = y1 + 1; y < y2; y++){
			gotoxy(x1,y);putchar(186);
			gotoxy(x2,y);putchar(186);
		}
	return;
}

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
