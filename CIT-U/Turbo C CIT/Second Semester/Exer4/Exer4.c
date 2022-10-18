#include <stdio.h>
#include <windows.h>

void sumAll(int *n, int *sum);
void aveAllDiv(int *n,float *ave);
void swap(int *a, int *b,int *c,int *d);
void drawDBox(int x1, int y1, int x2, int y2);
void gotoxy(int x, int y);
void menu();
void Exit(void);
int getNum();

int main(){
	int n, sum, a, b, c, d;
	char rep, num, choice, s;
	float ave;
		do{
			system("cls");
			drawDBox(2,0,21,11);
			menu();
			s = getche(choice);
			switch(s){
				case 'a':
					gotoxy(28,2);
					sumAll(&n,&sum);
					break;
				case 'b':
					gotoxy(28,2);
					aveAllDiv(&n,&ave);
					break;
				case 'c':
					gotoxy(28,2);
					swap(&a,&b,&c,&d);
					break;
				case 'd':
					Exit();
					return 0;
					break;
				default:
					gotoxy(2,13);printf("Enter a valid choice!");
					rep = 'y';
			}
			gotoxy(2,15);printf("\n Press Y to return to the main menu.");
			rep = getche(num);
		}while(rep == 'y' || 'Y');
	return 0;
}

int getNum(){
	int n;
		scanf("%d", &n);
	return n;
}

void sumAll(int *n, int *sum){
	int i;
	*sum = 0;
		drawDBox(25,0,50,6);
		gotoxy(28,2);printf("Enter a number: ");
		scanf("%d",&*n);
			for (i = 0; i <= *n; i++){
				*sum += i;
			}
				gotoxy(28,4);printf("Sum = %d", *sum);
	return;
}

void aveAllDiv(int *n, float *ave){
	int i, num = 0;
	*ave = 0;
		drawDBox(25,0,50,6);
		gotoxy(28,2);printf("Enter a number: ");
		scanf("%d",&*n);
			gotoxy(28,4);
				for(i = 3; i <= *n; i+=3){
					*ave += i;
					if (i % 3 == 0){
						num += 1;
					}
				}
			if (*ave == 0){
				printf("Undefined");
			} else {
				printf("Average = %.2f", *ave / num);
			}
	return;
}

void swap(int *a, int *b, int *c, int *d){
	int temp;
		drawDBox(25,0,75,12);
		drawDBox(65,0,75,12);
		drawDBox(55,0,75,12);
		gotoxy(28,2);printf("Numbers");
		gotoxy(28,4);printf("Enter a value for a:");
		*a = getNum();
		gotoxy(28,6);printf("Enter a value for b:");
		*b = getNum();
		gotoxy(28,8);printf("Enter a value for c:");
		*c = getNum();
		gotoxy(28,10);printf("Enter a value for d:");
		*d = getNum();
		gotoxy(58,2);printf("Before");
		gotoxy(60,4);printf("%d", *a);gotoxy(60,6);printf("%d", *b);
		gotoxy(60,8);printf("%d", *c);gotoxy(60,10);printf("%d", *d);
		temp = *a;
		*a = *b;
		*b = *c;
		*c = *d;
		*d = temp;
		gotoxy(68,2);printf("After");
		gotoxy(70,4);printf("%d",*a);gotoxy(70,6);printf("%d",*b);
		gotoxy(70,8);printf("%d",*c);gotoxy(70,10);printf("%d",*d);
	return;
}

void menu(){
		gotoxy(4,2);printf("Pointer Exercise");
		gotoxy(6,4);printf("[a] Sum");
		gotoxy(6,5);printf("[b] Average");
		gotoxy(6,6);printf("[c] Swap");
		gotoxy(6,7);printf("[d] Exit");
		gotoxy(6,9);printf("Choice: ");
	return;
}

void Exit(void){
	system("cls");printf("Program terminated. Thank you!");
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
			gotoxy(x1, y);putchar(186);
			gotoxy(x2, y);putchar(186);
		}
	return;
}

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
