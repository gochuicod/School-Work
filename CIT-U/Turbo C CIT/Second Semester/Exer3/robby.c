#include <stdio.h>
#include <windows.h>

void initialize(int *x, int *y){
	*x = 0;
	*y = 0;
		drawDBox(25, 0, 56, 4);
		gotoxy(28, 2);printf("Coordinates set to origin!");
	return;
}

void printLocation(int x, int y){
	drawDBox(25, 0, 60, 4);
	gotoxy(28, 2);printf("Current Location: (%d,%d)", x, y);
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
			gotoxy(26, 4);printf("  Enter number of spaces: ");
			scanf("%d", &e);
			if (e > 0){
			*x += e;
			} else {
			gotoxy(28, 6);printf("Please enter a positive number!");
			}
			break;
		case 2:
			gotoxy(26, 4);printf("  Enter number of spaces: ");
			scanf("%d", &w);
			if (w > 0){
			*x -= w;
			} else {
			gotoxy(28, 6);printf("Please enter a positive number!");
			}
			break;
		case 3:
			gotoxy(26, 4);printf("  Enter number of spaces: ");
			scanf("%d", &n);
			if (n > 0){
			*y += n;
			} else {
			gotoxy(28, 6);printf("Please enter a positive number!");
			}
			break;
		case 4:
			gotoxy(26, 4);printf("  Enter number of spaces: ");
			scanf("%d", &s);
			if (s > 0){
			*y -= s;
			} else {
			gotoxy(28, 6);printf("Please enter a positive number!");
			}
			break;
		default:
			gotoxy(28, 4);printf("Enter a valid number!");			
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
		gotoxy(6, 2);printf ("Robby Robot");
		gotoxy(6, 4);printf ("[a] Origin");
		gotoxy(6, 5);printf ("[b] Location");
		gotoxy(6, 6);printf ("[c] Move");
		gotoxy(6, 7);printf ("[d] Exit");
		gotoxy(6, 9);printf("Choice: ");
		getche(choice);
	return;
}
