#include <stdio.h>
#include <windows.h>
	void initSeats(int seats[], int size);
	void displaySeats(int seats[], int size);
	int assignSeat(int seats[], int seatType);
	int assignFirstClass(int seats[], int size);
	int assignEconomy(int seats[], int size);
	void boardPass(int seat);
	void exits(void);
	void gotoxy(int x, int y);
	
	int main(){
		int seats[10];
		int seatType, ctr;
		char rep;
			initSeats(seats, 10);
					do{
					system("cls");
					printf ("\nWelcome to MGM Airlines!");
					displaySeats(seats, 10);
					printf ("\n\nPlease type 1 for 'First Class'\nPlease type 2 for 'Economy': ");
					scanf("%d", & seatType);
					assignSeat(seats, seatType);
					
					if (seats[4] && seats[9] == 1){
						system("cls");
						exits();
						return 0;
						break;
						}
						gotoxy(2,18);
					printf ("\n\nDo you want to add more seats?");
					rep = getche(seats);
					}while (rep == 'y');
				
		return 0;
	}	
	
void initSeats(int seats[], int size){
	int initial;
		for (initial = 0; initial < size; initial++){
			seats[initial] = 0;
			if (initial > 4 || initial > 9){
			exits();
			}
		}
	return;
}// End of initialization
	
void displaySeats(int seats[], int size){
	int initial;
		printf ("\n\nFirst Class Section: ");
			for (initial = 0; initial <= 4; initial++){
				printf ("[%d]", seats[initial]);
			}
		printf ("\nEconomy Section:     ");
			for (initial = 5; initial <= 9; initial++){
				printf ("[%d]", seats[initial]);
			}
	return;
}
	
int assignSeat(int seats[], int seatType){
	int fc;
		if (seatType == 1){
			assignFirstClass(seats, 10);
		} else if (seatType == 2){
			assignEconomy(seats, 10);
		} else {
			assignFirstClass(seats, 0);
			gotoxy(0, 12);printf ("Please choose a valid section.");
	}
		gotoxy (0, 15);displaySeats(seats, 10);
	return 1;
}
	
	int assignFirstClass(int seats[], int size){
		int fc, seat, rep;
			for (fc = 0; fc < size/2; fc++){
				if (seats[fc] == 0){
//				gotoxy(2,15);
				seats[fc] = 1;
				seat = fc + 1;
				boardPass(seat);
				break;
			} else if (seats[4] == 1) {
				do{
				system("cls");
				gotoxy(0, 12);
				printf ("First Class is full. Continue to Economy?");
				rep = getche(seats);
				}while (rep == '1');
				return 0;
				break;
				}
			}
		return seats[fc];
	}// End of assignFirstClass
	
	int assignEconomy(int seats[], int size){
		int fc, seat, rep;
			for (fc = 5; fc < size; fc++){
				if (seats[fc] == 0){
//				gotoxy(2,15);
				seats[fc] = 1;
				seat = fc + 1;
				boardPass(seat);
				break;
			} else if (seats[9] == 1) {
				do{
				gotoxy(0, 12);
				printf ("Economy is full. Continue to First Class?");
				rep = getche(seats);
				}while (rep == 'y');
				return 0;
				break;				
				}
			}
		return seats[fc];
	}// End of assignEconomy
	
	void boardPass(int seat){
		int border, ctr;
			gotoxy(4, 11);
			printf ("Boarding Pass\n");
		if (seat <= 5){
			for (ctr = 0; ctr <= 4; ctr++){
				gotoxy(4, 12);
				printf ("First Class Section\n");
				gotoxy(4, 13);
				printf ("Seat #%d", seat);
			}
		} else if (seat <= 10) {
		for (ctr = 4; ctr <= 10; ctr++){
			gotoxy(4, 12);
			printf ("Economy Section\n");
			gotoxy(4, 13);
			printf ("Seat #%d", seat);
		}
	}
			gotoxy(2, 9);
			printf ("%c", 201);
			gotoxy(24, 9);
			printf ("%c", 187);
			gotoxy(2,15);
			printf ("%c", 200);
			gotoxy(24,15);
			printf ("%c", 188);
		for (seat = 3; seat < 24; seat++){
			gotoxy(seat, 9);
			printf ("%c", 205);
			gotoxy(seat, 15);
			printf ("%c", 205);
		}
		for (seat = 10; seat < 15; seat++){
			gotoxy(2, seat);
			printf ("%c", 186);
			gotoxy(24, seat);
			printf ("%c", 186);
		}
		return;
	}



	void exits(void){
		gotoxy (0, 12);
		printf ("All seats are taken. Next flight leaves in 3 hours...");
		gotoxy(0, 24);
		return;
	}
	
	void gotoxy(int x, int y){
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
