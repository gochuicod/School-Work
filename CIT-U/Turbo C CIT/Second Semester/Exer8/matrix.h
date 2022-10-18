#include <stdio.h>
#include <windows.h>
#include "myTools.h"
#define COL 6
#define ROW 6

void createMatrix(int matrixA[][COL], int matrixB[][COL], int row, int col);
void add(int matrixResult[][COL],int matrixA[][COL],int matrixB[][COL],int row,int col);
void subtract(int matrixResult[][COL],int matrixA[][COL],int matrixB[][COL],int row,int col);
void multiply(int matrixResult[][COL],int matrixA[][COL],int matrixB[][COL],int row,int col);
void Exit(void);
void menu();
