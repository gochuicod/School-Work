#include <stdio.h>
#include <windows.h>

void convertTime(int time, int* hours, int* mins, int* sec);
void displayTime(int time, int* hours, int* mins, int* sec);
void computeCoin(int coinValue, int* quarter, int* dime, int* penny);
void displayCoin(int coinValue, int* quarter, int* dime, int* penny);
void drawDBox(int x1, int y1, int x2, int y2);
void gotoxy(int x, int y);
void menu();
void Exit(void);
int getNum();

int main(){
	int time, hours, mins, sec, coinValue, quarter, dime, penny, n1;
	char rep, num, choice, s;
		do{
			system("cls");
			drawDBox(2,0,21,13);
			menu();
			s = getche(choice);
			switch(s){
				case 'a':
					gotoxy(28,2);drawDBox(25,0,60,6);
					gotoxy(28,2);printf("Enter time (in seconds): ");scanf("%d", &time);gotoxy(28, 2);
					if (time >= 0){
						convertTime(time,&hours,&mins,&sec);
					} else {
						gotoxy(28,4);printf("Enter a positive number!");
					}
					break;
				case 'b':
					gotoxy(28,2);drawDBox(25,0,65,6);
					gotoxy(28,2);printf("Enter coin amount (in cents): ");scanf("%d", &coinValue);gotoxy(28, 2);
					computeCoin(coinValue,&quarter,&dime,&penny);
					break;
				case '1':
					gotoxy(28,2);drawDBox(25,0,78,4);
					displayTime(time,&hours,&mins,&sec);
					break;
				case '2':
					gotoxy(28,2);drawDBox(25,0,72,4);
					displayCoin(coinValue,&quarter,&dime,&penny);
					break;
				case 'd':
					Exit();
					return 0;
					break;
				default:
					gotoxy(2,15);printf("Enter a valid choice!");
					rep = 'y';
			}
			gotoxy(2,17);printf("\n Press Y to return to the main menu.");
			rep = getche(num);
		}while(rep = 'Y' || 'y');
	return 0;
}

void convertTime(int time, int *hours, int *mins, int *sec){
			*hours = time / 3600;
			*mins = time % 3600 / 60;
			*sec = time % 3600 % 60 / 1;
	return;
}

void displayTime(int time, int* hours, int* mins, int* sec){
		gotoxy(28,2);printf("%d Second(s) = %d Hours %d Minutes %d Second(s)",time, *hours, *mins, *sec);
	return;
}

void computeCoin(int coinValue, int* quarter, int* dime, int* penny){
	*quarter = 0, *dime = 0, *penny = 0;
		if (coinValue < 100 && 0 < coinValue){
			*quarter = coinValue / 25;
			*dime = coinValue % 25 / 10;
			*penny = coinValue % 25 % 10 / 1;
		} else {
			gotoxy(28,4);printf("Converts cents between 0-99!");
		}
	return;
}

void displayCoin(int coinValue, int* quarter, int* dime, int* penny){
		gotoxy(28,2);printf("%d Cents = %d quarter(s) %d dime(s) %d penny",coinValue, *quarter,*dime,*penny);
	return;
}

int getNum(){
	int n;
		scanf("%d", &n);
	return n;
}

void menu(){
		gotoxy(7,2);printf("Conversion");
		gotoxy(6,4);printf("[a] Time");
		gotoxy(6,5);printf("[b] Coin");
		gotoxy(6,6);printf("[c] Display");
		gotoxy(10,7);printf("[1] Time");gotoxy(10,8);printf("[2] Coin");
		gotoxy(6,9);printf("[d] Exit");
		gotoxy(6,11);printf("Choice: ");
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
