#include <stdio.h>
#include <windows.h>
#include <string.h>

void createArray(int la[], int n);
void printArray(int *la, int n);
int insertAtPos(int *la, int n, int item, int k);
void insertFront(int *la, int *n, int item);
void removeAtPos(int *la, int *n, int index);
int removeItem(int la[], int n, int item);
int removeFront(int la[], int n);
int locateIndex(int la[], int n, int item);
int locateItem(int la[], int n, int item);
void sortAscending(int la[], int n);
void sortDescending(int la[], int n);
void Exit(void);
void menu();
