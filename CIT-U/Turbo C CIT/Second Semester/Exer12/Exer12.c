#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#define MAX 10

typedef struct {
	int elements[MAX];
	int count;
} Set;

void initialize(Set *s);
void display(const Set *s);
void add(Set *s, int elem);
int contains (const Set *s, int elem);
int cardinality(const Set *s);
int isEmpty(const Set *s);
void getUnion(Set *result, const Set *s1, const Set *s2);
void intersection(Set *result, const Set *s1, const Set *s2);
void difference(Set *result, const Set *s1, const Set *s2);
int subset(const Set *s1, const Set *s2);
int disjoint(const Set *s1, const Set *s2);
int equal(const Set *s1, const Set *s2);
void Exit();
void menu();
void gotoxy(int x, int y);
void drawDBox(int x1, int y1, int x2, int y2);

int main(){
	Set s1, s2, res;
	int i, num, limit;
	char pick[2];
	char *pPick=pick;
		initialize(&s1);initialize(&s2);initialize(&res);
			do{
				drawDBox(27,0,60,26);menu();
				
				if (!isEmpty(&s1)){
					drawDBox(65,0, 100, 3);
					gotoxy(67, 1); printf("Set 1: ");
					gotoxy(75,1);display(&s1);
				}
				if (!isEmpty(&s2)){
					drawDBox(65,0, 100, 3);
					gotoxy(67, 2); printf("Set 2: ");
					gotoxy(75,2);display(&s2);
				}
				
				gotoxy(31,25);printf("Enter a valid choice: ");
				gets(pPick);
			
				if (strcmp(pPick, "1a")==0){
					initialize(&s1);
					gotoxy(65, 5);
					printf("How many digits do you want to enter? ");
					scanf("%d", &limit);
					if (limit<=10){
						for (i=0; i<limit; i++){
							gotoxy(65, 6+i);printf("S1[%d]: ",i);scanf("%d", &num);
							add(&s1, num);
						}
					}
					else if (limit>MAX){
						gotoxy(65, 6);
						printf("The number of digits must not be more than 10");
					}
					gotoxy(31,28);system("pause");
					system("cls");
				}
				else if (strcmp(pPick, "1b")==0){
					initialize(&s2);
					gotoxy(65, 5);
					printf("How many digits do you want to enter? ");
					scanf("%d", &limit);
					if (limit<=MAX){
						for (i=0; i<limit; i++){
							gotoxy(65, 6+i);printf("S2[%d]: ",i);scanf("%d", &num);
							add(&s2, num);
						}
					}
					else if (limit>MAX){
						gotoxy(65, 6);
						printf("The number of digits must not be more than 10");
					}
		
					gotoxy(31,28);system("pause");
					system("cls");
				}
				else if (strcmp(pPick, "2")==0){
					getUnion(&res, &s1, &s2);
					gotoxy(65,5);printf("Union: ");
					gotoxy(72,5);
					if (!isEmpty(&s1) && !isEmpty(&s2) && !isEmpty(&res))
						display(&res);
					else if (isEmpty(&s1) || isEmpty(&s2))
						printf("One or both of the sets are empty.");
					else if (isEmpty(&res))
						printf("There is no union");
					gotoxy(31,28);system("pause");
					system("cls");
				}
				else if (strcmp(pPick, "3")==0){
					intersection(&res, &s1, &s2);
					gotoxy(65,5);printf("Intersection: ");
					gotoxy(80,5);
					if (!isEmpty(&s1) && !isEmpty(&s2) && !isEmpty(&res))
						display(&res);
					else if (isEmpty(&s1) || isEmpty(&s2))
						printf("One or both of the sets are empty.");
					else if (isEmpty(&res))
						printf("There is no intersection");
					gotoxy(31,28);system("pause");
					system("cls");
				}
				else if (strcmp(pPick, "4a")==0){
					difference(&res, &s1, &s2);
					gotoxy(65,5);printf("Difference: ");
					gotoxy(77,5);
					if (!isEmpty(&s1) && !isEmpty(&s2) && !isEmpty(&res))
						display(&res);
					else if (isEmpty(&s1) || isEmpty(&s2))
						printf("One or both of the sets are empty.");
					else if (isEmpty(&res))
						printf("There is no difference");
					gotoxy(31,28);system("pause");
					system("cls");
				}
				else if (strcmp(pPick, "4b")==0){
					difference(&res, &s2, &s1);
					gotoxy(65,5);printf("Difference: ");
					gotoxy(77,5);
					if (!isEmpty(&s1) && !isEmpty(&s2) && !isEmpty(&res))
						display(&res);
					else if (isEmpty(&s1) || isEmpty(&s2))
						printf("One or both of the sets are empty.");
					else if (isEmpty(&res))
						printf("There is no difference");
					gotoxy(31,28);system("pause");
					system("cls");
				}
				else if (strcmp(pPick, "5a")==0){
					gotoxy(65,5);printf("Is Set 1 a subset of Set 2? ");
					gotoxy(65,6);
					if (!isEmpty(&s1) && !isEmpty(&s2))
						printf("%s",subset(&s1, &s2)? "YES": "NO");
						
					else
						printf("One or both of the sets are empty.");
					gotoxy(31,28);system("pause");
					system("cls");
				}
				else if (strcmp(pPick, "5b")==0){
					gotoxy(65,5);printf("Is Set 2 a subset of Set 1? ");
					gotoxy(65,6);
					if (!isEmpty(&s1) && !isEmpty(&s2))
						printf("%s",subset(&s2, &s1)? "YES": "NO");
					else
						printf("One or both of the sets are empty.");
					gotoxy(31,28);system("pause");
					system("cls");
				}
				else if (strcmp(pPick, "6")==0){
					gotoxy(65,5);printf("Are the sets disjointed? ");
					gotoxy(65,6);
					if (!isEmpty(&s1) && !isEmpty(&s2))
						printf("%s",disjoint(&s2, &s1)? "YES": "NO");
					else
						printf("One or both of the sets are empty.");
					gotoxy(31,28);system("pause");
					system("cls");
				}
				else if (strcmp(pPick, "7")==0){
					gotoxy(65,5);
					printf("Are the sets equal? ");
					gotoxy(65,6);
					if (!isEmpty(&s1) && !isEmpty(&s2))
						printf("%s",equal(&s2, &s1)? "YES": "NO");
					else
						printf("One or both of the sets are empty.");
					gotoxy(31,28);system("pause");
					system("cls");
				}
				
				else if (strcmp(pPick, "8")==0){
					system("cls");
						Exit();
							return 0;
				}
				
				else 
					system("cls");
		
			} while (strcmp(pPick, "8")!=0);
	return 0;
}

void initialize(Set *s){
	s->count=0;
	return;
}

void display(const Set *s){
	int i;
	
	for (i=0; i<cardinality(s); i++)
		printf("[%d] ", s->elements[i]);
		
	return;	
}

void add(Set *s, int elem){
	s->elements[cardinality(s)] = elem;
	s->count++;
	return;
}

int contains(const Set *s, int elem){
	int i;
	
	for (i=0; i<cardinality(s); i++){
		if (s->elements[i]==elem)
			return 1;
	}
	return 0;
}

int cardinality(const Set *s){
	return s->count;
}

int isEmpty(const Set *s){
	if (cardinality(s)==0)
		return 1;
	return 0;
}

void getUnion(Set *result, const Set *s1, const Set *s2){
	int i;
	
	initialize(result);
	
	for (i=0; i<cardinality(s1); i++){
		if (!contains(result, s1->elements[i]))
			add(result, s1->elements[i]);
	}
	
	for (i=0; i<cardinality(s2); i++){
		if (!contains(result, s2->elements[i]))
			add(result, s2->elements[i]);
	}
	
	return;
}

void intersection(Set *result, const Set *s1, const Set *s2){
	int i;
		initialize(result);
			for (i=0; i<cardinality(s2); i++){
				if (contains(s1, s2->elements[i]))
					add(result, s2->elements[i]);
			}
	return;
}

void difference(Set *result, const Set *s1, const Set *s2){
	int i;
		initialize(result);
			for (i=0; i<cardinality(s1); i++)
				if (!contains(s2, s1->elements[i]))
					add(result, s1->elements[i]);
	return;
}

int subset(const Set *s1, const Set *s2){
	int i, sub=0;
		for (i=0; i<cardinality(s1); i++){
			if (contains(s2, s1->elements[i]))
				sub++;
		}
		if (sub==cardinality(s1) && cardinality(s1)<=cardinality(s2))
			return 1;
	return 0;
}

int disjoint(const Set *s1, const Set *s2){
	Set res;
		intersection(&res, s1, s2);
			if (isEmpty(&res))
				return 1;
	return 0;
}

int equal(const Set *s1, const Set *s2){
	int i, same=0;
		if (cardinality(s1)==cardinality(s2))
			same++;
			for (i=0; i<cardinality(s2); i++){
				if (contains(s1, s2->elements[i]))
					same++;
			}
					if (same==s1->count+1)
						return 1;
	return 0;
}

void Exit(){
		system("cls");printf_s("Exiting...");
	return;
}

void menu(){
	gotoxy(39,1); printf("Array Sets");
		     
	gotoxy(33,3); printf("1. Create");
	gotoxy(35,4); printf("a. Set 1");
	gotoxy(35,5); printf("b. Set 2");
	
	gotoxy(33,7); printf("2. Get union");
	gotoxy(33,9); printf("3. Find intersection");
	
	gotoxy(33,11); printf("4. Find difference");
	gotoxy(35,12); printf("a. Set 1 - Set 2");
	gotoxy(35,13); printf("b. Set 2 - Set 1");
	
	gotoxy(33,15); printf("5. Is it a subset?");
	gotoxy(35,16); printf("a. Set 1 of Set 2");
	gotoxy(35,17); printf("b. Set 2 of Set 1");
	
	gotoxy(33,19); printf("6. Is it a disjoint");
	gotoxy(33,21); printf("7. Is it equal?");
	gotoxy(33,23); printf("8. Exit");
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
