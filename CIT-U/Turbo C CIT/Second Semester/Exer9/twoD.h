#include "myTools.h"
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
