//Problem Description: A program that gets the highest number in the array, gets the sum of the row or the column
//						It is also considered as a rowMagic or columnMagic when all the rows or columns have the same sum
//						It is also considered as Magic Square when all the rows and columns have the same sum

#include <stdio.h>
#include <windows.h>
#define ROW 3
#define COL 3

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
void gotoxy(int x, int y);

int main(){
	int n, rep, num, choice, arr[ROW][COL];
		do{
			system("cls");menu();
				gotoxy(2, 16);printf ("Please enter a number [1 - 9]: ");scanf("%d", &n);
		switch (n){
			case 1:
				gotoxy(4, 18);getData(arr);
				break;
			case 2:
				gotoxy(0, 18);display(arr);
				break;
			case 3:
				gotoxy(2, 18);Max(arr);
				break;
			case 4:
				gotoxy(2, 18);printf("Please enter a row of your choice: ");scanf("%d", &choice);
				gotoxy(2, 20);printf ("The sum of the row is %d", rowSum(arr, choice));
				break;
			case 5:
				gotoxy(2, 18);printf("Please enter a column of your choice: ");scanf("%d", &choice);
				gotoxy(2, 20);printf("The sum of the column is %d", columnSum(arr, choice));
				break;
			case 6:
//				gotoxy(2, 18);printf(isRowMagic(arr) ? "It is a Magic row!" : "It is not a Magic row");  // This is an option to shorten code by TERNARY operation and another style of operation for conditional statements
				if (isRowMagic(arr)){
					gotoxy(2, 18);printf ("It is a Magic row!");
				} else {
					gotoxy(2, 18);printf ("It is not a Magic row");
				}
				break;
			case 7:
//				gotoxy(2, 18);printf(isColumnMagic(arr) ? "It is a Magic column!" : "It is not a Magic column");  // This is an option to shorten code by TERNARY operation and another style of operation for conditional statements
				if (isColumnMagic(arr)){
					gotoxy(2, 18);printf ("It is a Magic column!");
				} else {
					gotoxy(2, 18);printf ("It is not a Magic column");
				}
				break;
			case 8:
//				gotoxy(2, 18);printf(isMagic(arr) ? "It is a Magic square!" : "It is not a Magic square!");  // This is an option to shorten code by TERNARY operation and another style of operation for conditional statements
				if (isMagic(arr)){
					gotoxy(2, 18);printf ("It is a Magic square!");
				} else {
					gotoxy(2, 18);printf ("It is not a Magic square");
				}
				break;
			case 9:
				system("cls");
					Exit();
				return 0;
				break;
			default:
				gotoxy(2, 18);printf ("Please enter a valid number!");
			}
				gotoxy(37,0);system("pause");
		} while (rep == 'y' || 'Y');
	return 0;
}// end of main

void getData(int arr[][COL]){
	int a, b;
	int largest;
		for (a = 0; a < ROW; a++){
			for (b = 0; b < COL; b++){
				printf ("\n[%d][%d]:", a, b);
				scanf ("%d", &arr[a][b]);
				largest = arr[0][0];
			}
			printf ("\n");
		}
	return; 
}// allows the user to input the elements of the array.

void display(int arr[][COL]){
	int a, b;
	int largest;
	printf ("These are the elements\n\n");
		for (a = 0; a < ROW; a++){
			for (b = 0; b < COL; b++){
				printf("%d\t", arr[a][b]);
			}
			printf ("\n\n");
		}
		
	return;
}// prints the elements of the array.

int Max(int arr[][COL]){
	int a, b;
	int largest;
		for (a = 0; a < ROW; a++){
			for (b = 0; b < COL; b++){
				if (largest <= arr[a][b]){
					largest = arr[a][b];
				}
			}
		}
			printf ("The largest element is: %d", largest);
			
	return largest;
}// returns the largest element in the array.

int rowSum(int arr[][COL], int row){
	int a, sum = 0;
				for (a = 0; a < ROW; a++){
					sum += arr[row][a];
				}
	return sum;
}// returns the sum of the elements in the given row of array arr.

int columnSum(int arr[][COL], int col){
	int a, sum = 0;
		for (a = 0; a < COL; a++){
				sum +=  arr[a][col];
			}
	return sum;
}// returns the sum of the elements in the given column of array arr.

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
	int i;
			gotoxy(2, 0);printf ("%c", 201);
			gotoxy(35, 0);printf ("%c", 187);
			gotoxy(2, 14);printf ("%c", 200);
			gotoxy(35,14);printf ("%c", 188);
		for (i = 3; i < 35; i++){
			gotoxy(i, 14);printf ("%c", 205);
			gotoxy(i, 0);printf ("%c", 205);
			}
		for (i = 1; i < 14; i++){
			gotoxy(2, i);printf ("%c", 186);
			gotoxy(35, i);printf ("%c", 186);
			}
			
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
		
	return;
}// prints the menu 

void Exit(){
	printf ("Exiting...");
}// initiates exit

void gotoxy(int x, int y){
	COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}// sets coordinates based on the cartesian plane
