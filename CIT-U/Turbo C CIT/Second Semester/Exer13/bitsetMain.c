#include "bitset.h"
#include "myTools.h"

int main(){
	BitSet s, s1, s2, result;
	int i, choice, elem[MAX], set;
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
//									gotoxy(38,1);printf(isEmpty(s1) || isEmpty(s2) ? "One or both of the sets are Empty" : "Contains Values");
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
