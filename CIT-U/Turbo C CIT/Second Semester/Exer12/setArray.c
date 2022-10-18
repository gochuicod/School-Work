#include "setArray.h"
#include "myTools.h"

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
