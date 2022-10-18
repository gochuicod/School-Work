#include <stdio.h>
#include <windows.h>
#define MAX 10

typedef struct {
int elements[MAX];
int count;
} Set;

void initialize(Set *s);
void display(const Set *s);
void add(Set *s1, int elem);
int contains(const Set *s, int elem);
int cardinality(const Set *s);
int isEmpty(const Set *s);
void getUnion(Set *result, const Set *s1, const Set *s2);
void intersection(Set *result, const Set *s1, const Set*s2);
void difference(Set *result, const Set *s1, const Set *s2);
int subset(const Set *s1, const Set *s2);
int disjoint(const Set *s1, const Set *s2);
int equal(const Set *s1, const Set *s2);
void menu();
void Exit();
void drawDBox(int x1, int y1, int x2, int y2);
void gotoxy(int x, int y);
const char *warning = "Enter a valid choice!";

int main(){
	Set s, s1, s2, result;
	char rep,num;
	int i,j,k,choice,elem,set,size;
//	printf("Enter size: ");scanf("%d",&s.count);
	initialize(&s1);initialize(&s2);initialize(&result);
		do{
			system("cls");
				drawDBox(4,0,35,20);menu();
					gotoxy(18,18);scanf_s("%d",&choice);
						switch(choice){
							case 1:
								gotoxy(42,1);printf("Enter set: ");scanf("%d",&choice);
								if (choice == 1){
									gotoxy(42,3);puts("Set initialized!");
									initialize(&s1);
								} else if (choice == 2){
									gotoxy(42,3);puts("Set initialized!");
									initialize(&s2);
								} else {
									gotoxy(42,3);puts("Invalid Choice!");
								}
								break;
							case 2:
								gotoxy(42,1);printf("Set 1: ");display(&s1);
								gotoxy(42,2);printf("Set 2: ");display(&s2);
								break;
							case 3:
								gotoxy(42,1);printf("Set1 or Set2(1/2): ");scanf("%d",&set);
									if (set == 1){
										gotoxy(42,2);printf("How many elements? ");scanf("%d",&size);
											if (size <= MAX){
												for (i = 0, j = 4; i < size; i++,j++){
													gotoxy(42,j);printf("[%d]: ",i);scanf("%d",&elem);
													add(&s1,elem);
												}
											} else {
												gotoxy(42,3);printf("LIMIT IS 10");
											}
									} else if (set == 2){
										gotoxy(42,2);printf("How many elements? ");scanf("%d",&size);
											if (size <= MAX){
												for (i = 0, k = 4; i < size; i++,k++){
													gotoxy(42,k);printf("[%d]: ",i);scanf("%d",&elem);
													add(&s2,elem);
												}
											} else {
												gotoxy(42,3);printf("LIMIT IS 10");
											}
									} else {
										gotoxy(42,2);printf("Invalid Choice!");
									}
								break;
							case 4:
								gotoxy(42,1);printf("Enter element: ");scanf("%d",&elem);
									for (i = 0, j = 0; i < cardinality(&s1), j < cardinality(&s2); i++,j++){
										if (s1.elements[i] == elem){
											gotoxy(42,3);puts("Exist");
											break;
										} else if (s2.elements[j] == elem){
											gotoxy(42,3);puts("Exist");
											break;
										}
									}
								break;
							case 5:
								gotoxy(42,1);printf("Cardinality of S1 is %d",cardinality(&s1));
								gotoxy(42,3);printf("Cardinality of S2 is %d",cardinality(&s2));
								break;
							case 6:
								gotoxy(42,3);printf(isEmpty(&s1) == 1 || isEmpty(&s2) == 1 ? "One or both of the sets are empty" : "Contains Values!");
								break;
							case 7:
								getUnion(&result,&s1,&s2);
								break;
							case 8:
								intersection(&result,&s1,&s2);
								break;
							case 9:
								difference(&result,&s1,&s2);
								break;
							case 10:
								gotoxy(42,1);printf(subset(&s1,&s2) == 1 ? "It is a subset" : "It is not a subset");
								break;
							case 11:
								gotoxy(42,1);printf(disjoint(&s1,&s2) == 1 ? "Disjoint" : "Not Disjoint");
								break;
							case 12:
								gotoxy(42,1);printf(equal(&s1,&s2) == 1 ? "Equal" : "Not Equal");
								break;
							case 13:
								Exit();
								return 0;
								break;
							default:
								gotoxy(42,3);printf("%s",warning);
						}
								gotoxy(4,22);system("pause");
		}while (rep == '\r' || '\r');
	return 0;
}

void initialize(Set *s){
		int i;
			for (i = 0; i < cardinality(s); i++){
				s->count = 0;
			}
}

void display(const Set *s){
	int i;
		for (i = 0; i < cardinality(s); i++){
			printf("%d ",s->elements[i]);
		}
}

void add(Set *s, int elem){
	int i;
		s->elements[cardinality(s)] = elem;
			s->count++;
}

int contains(const Set *s, int elem){
	int i;
		for (i = 0; i < cardinality(s); i++){
			if (s->elements[i] == elem){
				return 1;
			} else {
				return 0;
			}
		}
}

int cardinality(const Set *s){
	return s->count;
}

int isEmpty(const Set *s){
	if (s->count == 0){
		return 1;
	} else {
		return 0;
	}
}

void getUnion(Set *result, const Set *s1, const Set *s2){
	int i,j;
		initialize(result);
			for (i = 0; i < cardinality(s1); i++){
				if (!equal(s1,s2)){
					printf("%d ",s1->elements[i]);
				}
			}
			for (j = 0; j < cardinality(s2); j++){
				if (!equal(s1,s2)){
					printf("%d ",s2->elements[j]);
				}
			}
}

void intersection(Set *result, const Set *s1, const Set*s2){
	int i,j,k,l=42;
		initialize(result);
			for (i = 0; i < cardinality(s1); i++){
				for (j = 0; j < cardinality(s2); j++){
					if (s2->elements[j] == s1->elements[i]){
						k++;
					}
					if (k == 1){
						gotoxy(l,2);printf("%d ", s2->elements[j]);
						l+=2;
					}
						k = 0;
				}
			}
}

void difference(Set *result, const Set *s1, const Set *s2){
	int i;
		initialize(result);
			for (i=0; i<cardinality(s1); i++)
				if (!contains(s2, s1->elements[i]))
					add(result, s1->elements[i]);
}

int subset(const Set *s1, const Set *s2){
	int i,j;
		for (i = 0, j = 0; i < cardinality(s1), j < cardinality (s2); i++, j++){
			if (s1->elements[i] == s2->elements[j]){
				return 1;
			} else {
				return 0;
			}
		}
}

int disjoint(const Set *s1, const Set *s2){
	Set result;
		if (s1->elements < 0 || s2->elements < 0)
			return 1;
		else
			return 0;
}

int equal(const Set *s1, const Set *s2){
	int i,j;
		for (i = 0, j = 0; i < cardinality(s1), j < cardinality(s2); i++, j++){
			if (s1->elements[i] == s2->elements[j] || s2->elements[j] == s1->elements[j]){
				return 1;
				break;
			}
		}
	return 0;
}

void menu(){
		gotoxy(10, 2);printf_s ("Quadratic Equations");
		gotoxy(10, 4);printf_s ("1. Initialize");
		gotoxy(10, 5);printf_s ("2. Display");
		gotoxy(10, 6);printf_s ("3. Add");
		gotoxy(10, 7);printf_s ("4. Contain");
		gotoxy(10, 8);printf_s ("5. Cardinality");
		gotoxy(10, 9);printf_s ("6. Empty");
		gotoxy(10, 10);printf_s ("7. Union");
		gotoxy(10, 11);printf_s ("8. Intersection");
		gotoxy(10, 12);printf_s ("9. Difference");
		gotoxy(10, 13);printf_s ("10. Subset");
		gotoxy(10, 14);printf_s ("11. Disjoint");
		gotoxy(10, 15);printf_s ("12. Equal");
		gotoxy(10, 16);printf_s ("13. Exit");
		gotoxy(10, 18);printf_s ("Choice: ");
	return;
}

void Exit(){
		system("cls");printf_s("Exiting...");
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
