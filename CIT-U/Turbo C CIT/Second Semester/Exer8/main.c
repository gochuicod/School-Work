#include "matrix.h"

int main(){
	int switch_case, matrixA[ROW][COL], matrixB[ROW][COL], matrixResult[ROW][COL], row = 0, col = 0;
	char rep, num;
		do{
			system("cls");
				drawDBox(4,0,27,12);
					menu();
						scanf("%d", &switch_case);
							switch(switch_case){
								case 1:
									gotoxy(0,14);printf("Hint! Use space between numbers.");
										printf("\n\n");system("pause");
											gotoxy(0,18);printf("Enter row and col size: ");scanf("%d %d", &row, &col);
									if (row > 6 && col > 6 || row > 6 || col > 6){
										gotoxy(0,20);printf("Limit is only 6 rows and 6 columns!");
											break;
									} else if (row == 0 && col == 0 || row < 1 || col < 1){
										gotoxy(0,20);printf("Row or Col can't be less than 1!");
											break;
									} else {
										gotoxy(0,20);createMatrix(matrixA,matrixB,row,col);
									}
									break;
								case 2:
									if (row < 1  && col < 1 || row > 6 && col > 6 || row > 6 || col > 6 || row < 1 || col < 1){
										gotoxy(0,14);printf("Matrix A and B not initialized.");
											break;
									} else {
										gotoxy(0,14);add(matrixResult,matrixA,matrixB,row,col);
									}
									break;
								case 3:
									if (row < 1 && col < 1 || row > 6 && col > 6 || row > 6 || col > 6 || row < 1 || col < 1){
										gotoxy(0,14);printf("Matrix A and B not initialized.");
											break;
									} else {
										gotoxy(0,14);subtract(matrixResult,matrixA,matrixB,row,col);
									}
									break;
								case 4:
									if (row < 1 && col < 1 || row > 6 && col > 6 || row > 6 || col > 6 || row < 1 || col < 1){
										gotoxy(0,14);printf("Matrix A and B not initialized.");
											break;
									} else {
										gotoxy(0,14);multiply(matrixResult,matrixA,matrixB,row,col);
									}
									break;
								case 5:
									Exit();
									return 0;
									break;
								default:
									gotoxy(0,14);printf("Enter a valid choice!\n");
							}
										printf("\n\nPress any key to return to the main menu...");rep = getche(num);
		}while(rep == '\r' || '\r');
	return 0;
}
