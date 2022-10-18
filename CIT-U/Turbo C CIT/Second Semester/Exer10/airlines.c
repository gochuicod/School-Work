#include "airlines.h"

void initSeats(int seats[], int size){
	int i;
		for (i = 0; i < size; i++){
			seats[i] = 0;
		}
	return;
}

void displaySeats(int seats[], int size){
	int i, j = 26, k = 26;
		for (i = 0; i < 5; i++, j+=3){
			gotoxy(j,4);printf("[%d]", seats[i]);
		}
		for (i = 5; i < 10; i++, k+=3){
			gotoxy(k,5);printf("[%d]", seats[i]);
		}
	return;
}

int assignSeat(int seats[], int seatType){
		if (seatType == 1){
			assignFirstClass(seats,10);
		} else if (seatType == 2){
			assignEconomy(seats,10);
		} else {
			assignFirstClass(seats,0);
		}
			displaySeats(seats,10);
	return 1;
}

int assignFirstClass(int seats[], int size){
	int i, seat;
	char rep, num;
		for (i = 0; i < size/2; i++){
			if (seats[i] == 0){
				seats[i] = 1;
				seat = i + 1;
				boardPass(seat);
				break;
			} else if (seats[4] == 1){
				gotoxy(49,8);printf("First Class full!");
				rep = getche(num);
				return 0;
				break;
			}
		}
	return seats[i];
}

int assignEconomy(int seats[], int size){
	int i, seat;
	char rep, num;
		for (i = 5; i < size; i++){
			if (seats[i] == 0){
				seats[i] = 1;
				seat = i + 1;
				boardPass(seat);
				break;
			} else if (seats[9] == 1){
				gotoxy(49,8);printf("Economy is full!");
				rep = getche(num);
				break;
			}
		}
}

void boardPass(int seat){
	int i;
			if (seat <= 5){
				for (i = 0; i < 5; i++){
					gotoxy(48,2);printf("First Class Section");
					gotoxy(53,4);printf("Seat #%d", seat);
				}
			} else if (seat <= 10){
				for (i = 5; i < 10; i++){
					gotoxy(50,2);printf("Economy Section");
					gotoxy(53,4);printf("Seat #%d", seat);
				}
			}
	return;
}

void Exit(){
		system("cls");drawDBox(38,14,86,16);
		gotoxy(40,15);printf ("All seats full! Next flight leaves in 3 hours");
		gotoxy(40,17);system("pause");
	return;
}
