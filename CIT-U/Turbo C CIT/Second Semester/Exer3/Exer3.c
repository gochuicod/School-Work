#include<stdio.h>
#include<windows.h>

char printCommand(void);
void gotoxy(int x, int y);
void initialize(int *x, int *y);
void printLocation(int x, int y);
void move(int *x, int *y);
void Exit(void);
void drawDBox(int x1, int y1, int x2, int y2);

int main(){
	int x, y;
	int x1,y1,x2,y2;
	char rep, num, l;
	
		do{
			system("cls");
			drawDBox(2, 0, 20, 11);
			switch(printCommand()){
				case 'a':
					gotoxy(2, 12);
					initialize(&x, &y);
					break;
				case 'b':
					gotoxy(2, 12);
					printLocation(x,y);
					break;
				case 'c':
					gotoxy(30, 2);
					move(&x,&y);
					break;
				case 'd':
					Exit();
					return 0;
					break;
				default:
					gotoxy(2, 13);
					printf("Enter a valid choice.");
					rep = 'y';
			}
			gotoxy(2, 15);
			printf("\n  Press Y to return to the main menu.");
			rep = getche(num);
		}while(rep == 'y' || 'Y');
	return 0;
}

void initialize(int *x, int *y){
	*x = 0;
	*y = 0;
		drawDBox(25, 0, 56, 4);
		gotoxy(28, 2);
		printf("Coordinates set to zero!");
	return;
}

void printLocation(int x, int y){
	drawDBox(25, 0, 60, 4);
	gotoxy(28, 2);
	printf("Current Location: (%d,%d)", x, y);
	return;
}

void move(int *x, int *y){
	int in, n=0, s=0, e=0, w=0;
	
	drawDBox(25, 0, 65, 8);
	gotoxy(28, 2);
	printf("1-East, 2-West, 3-North, 4-South: ");
	scanf("%d", &in);
	switch(in){
		case 1:
			gotoxy(26, 4);
			printf("  Enter number of spaces: ");
			scanf("%d", &e);
			if (e > 0){
			*x += e;
			} else {
			gotoxy(28, 6);printf("Please enter a positive number!");
			}
			break;
		case 2:
			gotoxy(26, 4);
			printf("  Enter number of spaces: ");
			scanf("%d", &w);
			if (w > 0){
			*x -= w;
			} else {
			gotoxy(28, 6);printf("Please enter a positive number!");
			}
			break;
		case 3:
			gotoxy(26, 4);
			printf("  Enter number of spaces: ");
			scanf("%d", &n);
			if (n > 0){
			*y += n;
			} else {
			gotoxy(28, 6);printf("Please enter a positive number!");
			}
			break;
		case 4:
			gotoxy(26, 4);
			printf("  Enter number of spaces: ");
			scanf("%d", &s);
			if (s > 0){
			*y -= s;
			} else {
			gotoxy(28, 6);printf("Please enter a positive number!");
			}
			break;
		default:
			gotoxy(28, 4);
			printf("Enter a valid number!");			
	}
	return;
}

void Exit(void){
	system("cls");
	printf("Program terminated. Thank you!");
	return;
}

char printCommand(void){
	char choice;
		gotoxy(6, 2);
		printf ("Robby Robot");
		gotoxy(6, 4);
		printf ("[a] Origin");
		gotoxy(6, 5);
		printf ("[b] Location");
		gotoxy(6, 6);
		printf ("[c] Move");
		gotoxy(6, 7);
		printf ("[d] Exit");
		gotoxy(6, 9);
		printf("Choice: ");
		getche(choice);
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
