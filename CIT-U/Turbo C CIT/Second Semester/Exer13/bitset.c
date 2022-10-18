#include "bitset.h"
#include "myTools.h"

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
		gotoxy(10, 4);printf_s ("1. Initialize");
		gotoxy(10, 5);printf_s ("2. Add Elements");
		gotoxy(10, 6);printf_s ("3. Display Elements");
		gotoxy(10, 7);printf_s ("4. Get Union");
		gotoxy(10, 8);printf_s ("5. Get Intersection");
		gotoxy(10, 9);printf_s ("6. Get Difference");
		gotoxy(10, 10);printf_s ("7. Is it Empty?");
		gotoxy(10, 11);printf_s ("8. Contains Values?");
		gotoxy(10, 12);printf_s ("9. Disjointed?");
		gotoxy(10, 13);printf_s ("10. Is it Equal?");
		gotoxy(10, 14);printf_s ("11. Cardinality");
		gotoxy(10, 15);printf_s ("12. Exit");
		gotoxy(10, 17);printf_s ("Choice: ");
	return;
}
