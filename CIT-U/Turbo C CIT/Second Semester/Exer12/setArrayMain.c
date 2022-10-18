#include "setArray.h"
#include "myTools.h"

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
