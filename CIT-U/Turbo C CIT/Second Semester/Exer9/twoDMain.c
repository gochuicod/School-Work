#include "twoD.h"

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
