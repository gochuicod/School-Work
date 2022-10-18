#include <stdio.h>
#include <windows.h>

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
		gotoxy(10,7);printf("[1] Time");
		gotoxy(10,8);printf("[2] Coin");
		gotoxy(6,9);printf("[d] Exit");
		gotoxy(6,11);printf("Choice: ");
	return;
}

void Exit(void){
	system("cls");printf("Program terminated. Thank you!");
	return;
}
