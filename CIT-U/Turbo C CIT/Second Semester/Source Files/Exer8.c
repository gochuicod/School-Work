#include <stdio.h>
#include <windows.h>
#define COL 6
#define ROW 6

void createMatrix(int matrixA[][COL], int matrixB[][COL], int row, int col);
void add(int matrixResult[][COL],int matrixA[][COL],int matrixB[][COL],int row,int col);
void subtract(int matrixResult[][COL],int matrixA[][COL],int matrixB[][COL],int row,int col);
void multiply(int matrixResult[][COL],int matrixA[][COL],int matrixB[][COL],int row,int col);
void gotoxy(int x, int y);
void drawDBox(int x1, int y1, int x2, int y2);
void Exit(void);
void menu();

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

void createMatrix(int matrixA[][COL], int matrixB[][COL], int row, int col){
	int i, j, k = 20;
		for (i = 0; i < row; i++){
			for (j = 0; j < col; j++){
				printf("[%d][%d]: ",i,j);
				scanf("%d", &matrixA[i][j]);
			}
		}
		printf("\n");
		for (i = 0; i < row; i++){
			for (j = 0; j < col; j++,k++){
				gotoxy(15,k);printf("[%d][%d]: ",i,j);
				scanf("%d", &matrixB[i][j]);
			}
		}
	return;
}

void add(int matrixResult[][COL],int matrixA[][COL],int matrixB[][COL],int row,int col){
	int i, j;
		for (i = 0; i < row; i++){
			for (j = 0; j < col; j++){
				matrixResult[i][j] = matrixA[i][j] + matrixB[i][j];
				printf("[%d][%d]: %d\t",i,j,matrixResult[i][j]);
			}
				printf("\n");
		}
	return;
}

void subtract(int matrixResult[][COL],int matrixA[][COL],int matrixB[][COL],int row,int col){
	int i, j;
		for (i = 0; i < row; i++){
			for (j = 0; j < col; j++){
				matrixResult[i][j] = matrixA[i][j] - matrixB[i][j];
				printf("[%d][%d]: %d\t",i,j, matrixResult[i][j]);
			}
				printf("\n");
		}
	return;
}

void multiply(int matrixResult[][COL],int matrixA[][COL],int matrixB[][COL],int row,int col){
	int i, j, k;
		for (i = 0; i < row; i++){
			for (j = 0; j < col; j++){
				matrixResult[i][j] = 0;
				for (k = 0; k < row; k++){
					matrixResult[i][j] += matrixA[i][k] * matrixB[k][j];
				}
			}
		}
		for (i = 0; i < row; i++){
			for (j = 0; j < col; j++){
				printf("[%d][%d]: %d\t",i,j,matrixResult[i][j]);
			}
				printf("\n");
		}
	return;
}

void menu(){
		gotoxy(12,2);printf("MATRICES");
		gotoxy(6,4);printf("[1] MATRIXCreate");
		gotoxy(6,5);printf("[2] MATRIXSum");
		gotoxy(6,6);printf("[3] MATRIXDifference");
		gotoxy(6,7);printf("[4] MATRIXProduct");
		gotoxy(6,8);printf("[5] Exit");
		gotoxy(6,10);printf("Choice: ");
	return;
}

void Exit(void){
	system("cls");printf("Program terminated!");
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
