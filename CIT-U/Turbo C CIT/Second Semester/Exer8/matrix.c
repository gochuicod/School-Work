#include "matrix.h"

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
