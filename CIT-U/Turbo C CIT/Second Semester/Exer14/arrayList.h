#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <stdlib.h>

struct list{
	int *items;		// pointer to the array
	int size;		// actual size of the array
	int count;		// number of items in the array
};

typedef struct list *List;	// pointer to the structure
List newList(int size);
int isEmpty(List list);
void display(List list);
bool contains(List list, int item);
void Remove(List list, int i);
void insertAfter(List list,int item, int i);
void addEnd(List list,int item);
void addFront(List list,int item);
void removeFront(List list);
void removeItem(List list, int item);
void removeIndex(List list, int i);
void Exit();
void menu();
