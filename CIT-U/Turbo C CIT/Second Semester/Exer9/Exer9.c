#include <stdio.h>
#include <windows.h>
#define ROW 4
#define COL 4

void getData(int arr[][COL]);
void display(int arr[][COL]);
int Max(int arr[][COL]);
int rowSum(int arr[][COL], int row);
int columnSum(int arr[][COL], int col);
int isRowMagic(int arr[][COL]);
int isColumnMagic(int arr[][COL]);
int isMagic(int arr[][COL]);
void menu();
void Exit();
void drawDBox(int x1, int y1, int x2, int y2);
void gotoxy(int x, int y);

int main(){
	int arr[ROW][COL], n, choice;
	char rep, num;
		do{
		system("cls");
		drawDBox(4,0,35,16);menu();
		scanf ("%d", &n);
		switch (n){
			case 1:
				gotoxy(40,2);printf("Enter values");
				drawDBox(37,0,55,21);getData(arr);
				break;
			case 2:
				gotoxy(40,2);printf ("The elements");
				drawDBox(37,0,55,21);display(arr);
				break;
			case 3:
				drawDBox(37,0,67,4);Max(arr);
				break;
			case 4:
				drawDBox(37,0,80,6);
				gotoxy(40,2);printf ("Please enter a row of your choice: ");scanf ("%d", &choice);
				gotoxy(40,4);printf ("The sum of the row is %d", rowSum(arr, choice));
				break;
			case 5:
				drawDBox(37,0,80,6);
				gotoxy(40,2);printf ("Please enter a column of your choice: ");scanf ("%d", &choice);
				gotoxy(40,4);printf ("The sum of the column is %d", columnSum(arr, choice));
				break;
			case 6:
				drawDBox(37,0,65,4);
				if (isRowMagic(arr)){
					gotoxy(40,2);printf ("It is a Magic row!");
				} else {
					gotoxy(40,2);printf ("It is not a Magic row");
				}
				break;
			case 7:
				drawDBox(37,0,66,4);
				if (isColumnMagic(arr)){
					gotoxy(40,2);printf ("It is a Magic column!");
				} else {
					gotoxy(40,2);printf ("It is not a Magic column");
				}
				break;
			case 8:
				drawDBox(37,0,67,4);
				if (isMagic(arr)){
					gotoxy(40,2);printf ("It is a Magic square!");
				} else {
					gotoxy(40,2);printf ("It is not a Magic square");
				}
				break;
			case 9:
				system("cls");
				Exit();
				return 0;
				break;
			default:
				drawDBox(37,0,70,4);gotoxy(40,2);printf ("Please enter a valid number!");
			}
				gotoxy(4,18);printf ("Press any key...");
				rep = getche(num);
		} while (rep == '\r' || '\r');
	return 0;
}// end of main

void getData(int arr[][COL]){								// allows the user to input the elements of the array.
	int a, b, largest, k = 4;
		for (a = 0; a < ROW; a++){
			for (b = 0; b < COL; b++, k++){
				gotoxy(40,k);printf ("[%d][%d]: ", a, b);scanf ("%d", &arr[a][b]);
				largest = arr[0][0];
			}
		}
	return; 
}

void display(int arr[][COL]){								// prints the elements of the array.
	int a, b, largest, k = 4;
		for (a = 0; a < ROW; a++){
			for (b = 0; b < COL; b++, k++){
				gotoxy(40,k);printf("[%d][%d]: %d", a, b, arr[a][b]);
			}
		}
	return;
}

int Max(int arr[][COL]){									// returns the largest element in the array.
	int a, b;
	int largest;
		for (a = 0; a < ROW; a++){
			for (b = 0; b < COL; b++){
				if (largest <= arr[a][b]){
					largest = arr[a][b];
				}
			}
		}
					gotoxy(40,2);printf ("The largest element is: %d", largest);
	return largest;
}

int rowSum(int arr[][COL], int row){						// returns the sum of the elements in the given row of array arr.
	int a, sum = 0;
				for (a = 0; a < ROW; a++){
					sum += arr[row][a];
				}
	return sum;
}

int columnSum(int arr[][COL], int col){						// returns the sum of the elements in the given column of array arr.
	int a, sum = 0;
		for (a = 0; a < COL; a++){
				sum +=  arr[a][col];
			}
	return sum;
}

int isRowMagic(int arr[][COL]){
	int temp = rowSum(arr, 0);
	if(temp == rowSum(arr, 1) && temp == rowSum(arr, 2)){
		return 1;
	} else {
		return 0;
	}
}

int isColumnMagic(int arr[][COL]){
	int temp = columnSum(arr, 0);
	if (temp == columnSum(arr, 1) && temp == columnSum(arr, 2)){
		return 1;
	} else {
		return 0;
	}
}

int isMagic(int arr[][COL]){
	if (isRowMagic(arr) && isColumnMagic){
		return 1;
	} else {
		return 0;
	}
}

void menu(){
		gotoxy(9, 2);printf ("Two-dimensional Array");
		gotoxy(10, 4);printf ("1. Input Elements");
		gotoxy(10, 5);printf ("2. Print Elements");
		gotoxy(10, 6);printf ("3. Largest Element");
		gotoxy(10, 7);printf ("4. Row Sum");
		gotoxy(10, 8);printf ("5. Column Sum");
		gotoxy(10, 9);printf ("6. Magic Row");
		gotoxy(10, 10);printf ("7. Magic Column");
		gotoxy(10, 11);printf ("8. Magic");
		gotoxy(10, 12);printf ("9. Exit");
		gotoxy(10, 14);printf ("Choice: ");
	return;
}

void Exit(){
		printf ("Exiting...");
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
