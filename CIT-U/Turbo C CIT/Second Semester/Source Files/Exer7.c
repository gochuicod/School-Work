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
void gotoxy(int x, int y);
void drawDBox(int x1, int y1, int x2, int y2);
void Exit(void);
void menu();

int main(){
	int switch_case, item, item_sub, k, n, index, asc_desc, la[99999];
	char rep, num;
	system("color 1F");
		do{
			system("cls");
			drawDBox(4,0,27,18);
			menu();
			scanf("%d", &switch_case);
			switch(switch_case){
				case 1:
					drawDBox(30,0,65,18);
					gotoxy(35,2);printf("Enter array size: ");scanf("%d", &n);
					if (n < 0){
						drawDBox(30,0,65,4);
						gotoxy(34,2);printf("Negative inputs are disabled.");
					} else {   
						createArray(la,n);
					}
					break;
				case 2:
					if (n == 0){
						drawDBox(30,0,65,4);gotoxy(34,2);printf("Please create an array first!");
					} else {
						drawDBox(30,0,60,18);
						gotoxy(35,2);printf("These are the values");
						printArray(la,n);
					}
					break;
				case 3:
					
					if (n == 0){
						drawDBox(30,0,65,4);gotoxy(34,2);printf("Please create an array first!");
					} else {
						drawDBox(30,0,65,18);
						gotoxy(35,2);printf("Enter position: ");scanf("%d", &k);
						gotoxy(35,4);printf("Enter item: ");scanf("%d", &item);
						n = insertAtPos(la, n, item, k);
					}
					break;
				case 4:
					if (n == 0){
						drawDBox(30,0,65,4);gotoxy(34,2);printf("Please create an array first!");
					} else {
						drawDBox(30,0,65,6);gotoxy(34,2);printf("Enter item: ");scanf("%d", &item);
						insertFront(la, &n, item);
					}
					break;
				case 5:
					if (n == 0){
						drawDBox(30,0,65,4);gotoxy(34,2);printf("Please create an array first!");
					} else {
						drawDBox(30,0,65,6);gotoxy(34,2);printf("Enter index: ");scanf("%d", &index);
						removeAtPos(la,&n,index);
					}
					break;
				case 6:
					if (n == 0){
						drawDBox(30,0,65,4);gotoxy(34,2);printf("Please create an array first!");
					} else {
						drawDBox(30,0,65,6);gotoxy(34,2);printf("Enter item: ");scanf("%d", &item);
						n = removeItem(la,n,item);
					}
					break;
				case 7:
					if (n == 0){
						drawDBox(30,0,65,4);gotoxy(34,2);printf("Please create an array first!");
					} else {
						drawDBox(30,0,65,4);gotoxy(34,2);n = removeFront(la,n);
					}
					break;
				case 8:
					if (n == 0){
						drawDBox(30,0,65,4);gotoxy(34,2);printf("Please create an array first!");
					} else {
						drawDBox(30,0,65,6);gotoxy(34,2);printf("Enter item to be located: ");scanf("%d", &item);
						locateIndex(la,n,item);
					}
					break;
				case 9:
					if (n == 0){
						drawDBox(30,0,65,4);gotoxy(34,2);printf("Please create an array first!");
					} else {
						drawDBox(30,0,65,6);gotoxy(34,2);printf("Enter item: ");scanf("%d", &item);
						locateItem(la,n,item);
					}
					break;
				case 10:
					if (n == 0){
						drawDBox(30,0,65,4);gotoxy(34,2);printf("Please create an array first!");
					} else {
							drawDBox(30,0,90,10);
								gotoxy(34,2);printf("Hint! Press 1 for Ascending or Press 0 for Descending.");
									gotoxy(34,4);system("pause");
										gotoxy(34,6);printf("Sort Ascending or Descending? ");scanf("%d", &asc_desc);
											if (asc_desc == 1){
												gotoxy(34,2);sortAscending(la, n);
											} else {
												gotoxy(34,2);sortDescending(la, n);
											}
					}
					break;
				case 11:
					Exit();
					return 0;
					break;
				default:
					gotoxy(35,4);printf("Enter a valid choice!\n");
			}
					gotoxy(4,21);printf("Press any key to return to the main menu...");
					rep = getche(num);
		}while(rep == '\r' || '\r');
	return 0;
}

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
