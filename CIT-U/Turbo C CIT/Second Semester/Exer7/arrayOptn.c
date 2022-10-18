#include "arrayOptn.h"

void createArray(int la[], int n){												//Creates the Array
	int i, j, k = 4;
		for(i = 0; i < n;k++){
			int duplicated = 0;
			gotoxy(35,k);printf("[%d]: ", i);scanf("%d", &la[i]);
			for (j = 0; j < n; j++){
					if (la[i] < 0){
						printf("\nError! Negative integers are disabled.\n\n");
						duplicated = 1;
						break;
					}
				}
				for (j = 0; j < i; j++){
					if(la[i] == la[j]){
						printf("\nYou already entered this! Try again.\n\n");
                		duplicated = 1;
                		break;
					}
				}
				
				if (! duplicated){
					i++;
				}
			}
	return;
}

void printArray(int *la, int n){												//Prints the Array
	int i, k = 4;
			for(i = 0; i < n; i++,k++){
				gotoxy(35,k);printf("[%d]: %d", i, la[i]);
			}
	return;
}

int insertAtPos(int *la, int n, int item, int k){								//Inserts item at desired position in the Array
	int i;
		for(i = 0; i <= n; i++){
			if (item == la[i]){
				gotoxy(35,6);printf("Existing item in the array!");
				return n;
			}
		}
		for(i = 0; i < n; i++){
			if (item != la[i]){
				for (i = n; i >= k; i--){
					la[i] = la[i - 1];
				}
					la[k] = item;
					break;
			}
		}
		gotoxy(35,6);printf("Item Added!");
	return n + 1;
}

void insertFront(int *la, int *n, int item){									//Inserts item at index zero
	int i;
		for(i = 0; i < *n; i++){
			if (item == la[i]){
				gotoxy(34,4);printf("Existing item in the array!");
				break;
			} else {
				for (i = *n; i > 0; i--){
					la[i] = la[i - 1];
				}
					la[0] = item;
					*n+=1;
					gotoxy(34,4);printf("Item Added!");
					break;
			}
		}
	return;
}

void removeAtPos(int *la, int *n, int index){									//Removes item at desired position in the Array
	int i, j = 0;
		for (i = 0; i < *n; i++,j++){
			if (index == i){
				*n-=1;
				break;
			} else {
				*n;
			}
		}
//		la[j] = 0;
		for (i = 0; i < *n; i++, j++){
			la[j] = la[j + 1];
		}
			gotoxy(34,4);printf("Item Removed!");
	return;
}

int removeItem(int la[], int n, int item){
	int i, j = 0;
		for (i = 0; i < n; i++){
			if (item == la[i]){
				for (j = i; j < n; j++){
					la[j] = la[j + 1];
				}
					gotoxy(34,4);printf("Item Removed!");
					return n - 1;
					break;
			}
		}
}

int removeFront(int la[], int n){												//Removes item at index zero
	int i, j = 0;
		for (i = 0; i < n; i++, j++){
			la[j] = la[i + 1];
		}
		gotoxy(41,2);printf("Item Removed!");
	return n - 1;
}

int locateIndex(int la[], int n, int item){										//Locates index from desired item
	int i, found = 0;
		for(i = 0; i <= n - 1; i++){
			if (item == la[i]){
				gotoxy(34,4);printf("Index: %d", i);
			}
		}
	return -1;
}

int locateItem(int la[], int n, int item){										//Locates item in the Array
	int i, found = 0;
		for(i = 0; i < n; i++){
			if (la[i] == item){
				gotoxy(34,4);printf("Item exists!");
				return 1;
				break;
			}
		}
			gotoxy(34,4);printf("Item doesn't exist!");
	return 0;
}

void sortAscending(int la[], int n){											//Sorts the array of numbers ascending and descending
	int i, tmp, j = 0;
			for (i = 0; i < n; i++){   												// loop n times - 1 per element
        		for (j = 0; j < n - i - 1; j++){ 										// last i elements are sorted already
            		if (la[j] > la[j + 1]){  											// swop if order is broken
                		tmp = la[j];
                		la[j] = la[j + 1];
                		la[j + 1] = tmp;
            		}
        		}
    		}
	  		gotoxy(34,8);printf("Array Sorted!");
	return;
}

void sortDescending(int la[], int n){
	int i, tmp, j = 0;
			for (i = 0; i < n; ++i){
            for (j = i + 1; j < n; ++j){
                if (la[i] < la[j]){
                    tmp = la[i];
                    la[i] = la[j];
                    la[j] = tmp;
                }
            }
        }
        gotoxy(34,8);printf("Array Sorted!");
	return;
}

void menu(){
		gotoxy(7,2);printf("ARRAY OPERATIONS");
		gotoxy(6,4);printf("[1] CREATEArray");
		gotoxy(6,5);printf("[2] PRINTArray");
		gotoxy(6,6);printf("[3] INSERTAtPos");
		gotoxy(6,7);printf("[4] INSERTFront");
		gotoxy(6,8);printf("[5] REMOVEAtPos");
		gotoxy(6,9);printf("[6] REMOVEItem");
		gotoxy(6,10);printf("[7] REMOVEFront");
		gotoxy(6,11);printf("[8] LOCATEIndex");
		gotoxy(6,12);printf("[9] LOCATEItem");
		gotoxy(6,13);printf("[10] SORT");
		gotoxy(6,14);printf("[11] Exit");
		gotoxy(6,16);printf("Choice: ");
	return;
}

void Exit(void){
	system("cls");printf("Program terminated!");
	return;
}
