#include "twoD.h"

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
