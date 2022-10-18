#include "airlines.h"

int main(){
	int n, seatType, seats[10];
	char rep, num;
		system("color 70");
		initSeats(seats,10);
			do{
				system("cls");
				drawDBox(2,0,43,12);//prints menu
				drawDBox(2,13,43,15);//prints add more
				drawDBox(45,0,69,6);//prints boarding pass
				drawDBox(45,7,69,9);//prints full
				gotoxy(10,2);printf("Welcome to MGM Airlines!");
				gotoxy(5,4);printf("First Class Section:");
				gotoxy(9,5);printf("Economy Section:");
				displaySeats(seats,10);
				gotoxy(10,7);printf("Type 1 for First Class");
				gotoxy(10,8);printf("Type 2 for Economy");
				gotoxy(10,10);printf("Choice: ");scanf("%d",&seatType);
				assignSeat(seats,seatType);
				if (seats [4] && seats [9] == 1){
					Exit();
					return 0;
				}
				gotoxy(4,14);printf("Add more seats?(Y/N): ");
				rep = getche(seats);
			}while (rep == 'y' || rep == 'Y');
	return 0;
}
