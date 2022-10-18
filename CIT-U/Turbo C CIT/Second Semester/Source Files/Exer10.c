#include <stdio.h>
#include <windows.h>

void initSeats(int seats[], int size);
void displaySeats(int seats[], int size);
int assignSeat(int seats[], int seatType);
int assignFirstClass(int seats[], int size);
int assignEconomy(int seats[], int size);
void boardPass(int seat);
void Exit(void);
void gotoxy(int x, int y);
void drawDBox(int x1, int y1, int x2, int y2);

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
