#include <stdio.h>
#include <windows.h>
#define MAX 100

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
