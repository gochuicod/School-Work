#include <stdio.h>
#include <windows.h>
#define MAX 10

typedef int BitSet[MAX];
void initialize(BitSet s);               
void add(int elem,BitSet s);
void display(BitSet s);
void getUnion(BitSet result,BitSet s1,BitSet s2); 
void intersection(BitSet result,BitSet s1,BitSet s2); 
void difference(BitSet result,BitSet s1,BitSet s2); 
int isEmpty(BitSet s);
int contains(BitSet s,int elem);
int disjoint(BitSet s1,BitSet s2); 
int equal(BitSet s1,BitSet s2);
int cardinality(BitSet s); 
int subset(BitSet s1,BitSet s2);
void Exit();
void menu();
void drawDBox(int x1, int y1, int x2, int y2);
void gotoxy(int x, int y);
void drawDBox(int x1, int y1, int x2, int y2);
void gotoxy(int x, int y);

int main(){
	BitSet s, s1, s2, result;
	int i, choice, elem, set;
	char rep, num;
	s == 0;
		system("color 1F");
			do{
				system("cls");
					drawDBox(4,0,35,20);menu();
						scanf("%d",&choice);
							switch(choice){
								case 1:
									initialize(s1);initialize(s2);
									break;
								case 2:
									drawDBox(36,0,61,20);
										gotoxy(38,2);printf("Set 1 or 2? ");scanf("%d",&set);
											if (set == 1){
												gotoxy(38,3);printf("How many elements? ");scanf("%d",&elem);
												add(elem,s1);
											} else if (set == 2) {
												gotoxy(38,3);printf("How many elements? ");scanf("%d",&elem);
												add(elem,s2);
											} else {
												gotoxy(38,3);puts("Enter a valid choice");
											}
									break;
								case 3:
									drawDBox(36,0,60,6);
										gotoxy(38,2);printf("Set 1: ");display(s1);
											gotoxy(38,4);printf("Set 2: ");display(s2);
									break;
								case 4:
									drawDBox(36,0,60,6);
										gotoxy(38,2);puts("Union");
											gotoxy(38,4);getUnion(result,s1,s2);
									break;
								case 5:
									drawDBox(36,0,60,6);
										gotoxy(38,2);puts("Intersection");
											gotoxy(38,4);intersection(result,s1,s2);
									break;
								case 6:
									drawDBox(36,0,60,8);
										difference(result,s1,s2);
									break;
								case 7:
										if (isEmpty(s1) || isEmpty(s2)){
											drawDBox(36,0,72,2);
												gotoxy(38,1);printf("One or both of the sets are Empty");
										} else {
											drawDBox(36,0,55,2);
												gotoxy(38,1);printf("Contains Values");
										}
									break;
								case 8:
									drawDBox(36,0,60,6);
										gotoxy(38,2);printf("Element to find: ");scanf("%d",&elem);
											gotoxy(38,4);printf(contains(s1,elem) == 1 || contains(s2,elem) == 1 ? "True" : "False");
									break;  
								case 9:
									drawDBox(36,0,50,2);
										gotoxy(38,1);printf(!disjoint(s1,s2) ? "Disjoint" : "Not Disjoint");
									break;
								case 10:
									drawDBox(36,0,48,2);
										gotoxy(38,1);printf(equal(s1,s2) ? "Equal" : "Not Equal");
									break;
								case 11:
									printf("Set 1: %d\nSet 2: %d",cardinality(s1),cardinality(s2));
									break;
								case 12:
									Exit();
									return 0;
									break;
								default:
									puts("\nInvalid choice!");
							}
								puts("\n");
								gotoxy(4,21);system("pause");
			}while (rep == '\r' || '\r');
}

void initialize(BitSet s){
	int i;
		for (i = 0; i < cardinality(s); i++){
			s[i] = 0;
		}
}

void add(int elem, BitSet s){
	int i,j=5;
		for (i = 0; i < elem; i++,j++){
			gotoxy(38,j);printf("[%d]: ",i);scanf("%d",&s[i]);
		}		
}

void display(BitSet s){
	int i;
		for (i = 0; i < cardinality(s); i++){
			printf("%d ",s[i]);
		}
}

void getUnion(BitSet result, BitSet s1, BitSet s2){
	int i,j,k,l;
	initialize(result);
		for (i = 0, j = 0, k = 0; i < cardinality(s1), j < cardinality(s2);){
			if (s1[i] < s2[j]){
				result[k] = s1[i];
				i++,k++;
			} else if (s1[i] > s2[j]){
				result[k] = s2[j];
				j++;k++;
			} else {
				result[k] = s1[i];
				i++,j++,k++;
			}
		}
				if (i < cardinality(s1)){
					for (; i < cardinality(s1); i++){
						result[k] = s1[i];
						k++;
					}
				} else if (j < cardinality(s2)){
					for (;j < cardinality(s2); j++){
						result[k] = s2[j];
						k++;
					}
				}
						for (i = 0; i < k; i++){
							printf("%d ",result[i]);
						}
}

void intersection(BitSet result, BitSet s1, BitSet s2){
	int i, j, temp = 0, empty = 0;
		for (i = 0; i < cardinality(s1); i++){
			for (j = 0; j < cardinality(s2); j++){
				if (s1[i] == s2[j]){
					temp = 1;
				}
			}
				if (temp == 1){
					printf("%d ", result[i] = s1[i]);
				}
					temp = 0;
		}
}

void difference(BitSet result, BitSet s1, BitSet s2){
	int i,j, temp = 0;
		initialize(result);
			gotoxy(38,1);printf("Set 1 Difference");
				gotoxy(38,5);printf("Set 2 Difference");
					for (i = 0, j = 0, temp = 38; i < cardinality(s1), j < cardinality(s2);temp+=2){
						if (s1[i] < s2[j]){
							gotoxy(temp, 3);printf("%d ",result[i] = s1[i]);
							i++;
						} else if (s2[j] < s1[i]){
							gotoxy(temp, 7);printf("%d ",result[j] = s2[j]);
							j++;
						} else {
							i++,j++;
						}
					}
}

int isEmpty(BitSet s){
	if (cardinality(s) == 0){
		return 1;
	} else {
		return 0;
	}
}

int contains(BitSet s, int elem){
	int i;
		for (i = 0; i < cardinality(s); i++){
			if (s[i] == elem)
				return 1;
		}
	return 0;
}

int disjoint(BitSet s1, BitSet s2){
	int i,j,temp=0, True=0;
		for (i = 0; i < cardinality(s1); i++){
			for (j = 0; j < cardinality(s2); j++){
				if (s1[i] == s2[j]){
					temp++;
				}
			}
				if (temp == 1){
					True++;
				}
					temp = 0;
		}
				if (True > 0){
					return 1;
				} else {
					return 0;
				}
}

int equal(BitSet s1, BitSet s2){
	int i,j,temp;
		for (i = 0, j = 0; i < cardinality(s1), j < cardinality(s2);){
			if (s1[i] == s2[j]){
				temp++,i++;
			} else if (s2[j] == s1[i]){
				temp++,j++;
			} else {
				i++,j++;
			}
		}
			if (temp > 0){
				return 1;
			} else {
				return 0;
			}
}

int cardinality(BitSet s){
	int i,size = 0;
		for (i = 0; i < s[i]; i++){
			if (s > 0)
			size++;
		}
	return size;
}

void Exit(){
		system("cls");printf_s("Exiting...");
	return;
}

void menu(){
		gotoxy(18, 2);printf_s ("SETS");
		gotoxy(10, 4);printf_s ("1. Initialize");gotoxy(10, 5);printf_s ("2. Add Elements");
		gotoxy(10, 6);printf_s ("3. Display Elements");gotoxy(10, 7);printf_s ("4. Get Union");
		gotoxy(10, 8);printf_s ("5. Get Intersection");gotoxy(10, 9);printf_s ("6. Get Difference");
		gotoxy(10, 10);printf_s ("7. Is it Empty?");gotoxy(10, 11);printf_s ("8. Contains Values?");
		gotoxy(10, 12);printf_s ("9. Disjointed?");gotoxy(10, 13);printf_s ("10. Is it Equal?");
		gotoxy(10, 14);printf_s ("11. Cardinality");gotoxy(10, 15);printf_s ("12. Exit");
		gotoxy(10, 17);printf_s ("Choice: ");
	return;
}

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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
