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

int main(){
	List list;
	int choice,size,item,i;
	char rep;
		do{
			system("cls");menu();
			scanf("%d",&choice);
				switch(choice){
					case 1:
						printf("\nHow much to allocate? ");scanf("%d",&size);
							printf("\n");
								list = newList(size);
						break;
					case 2:
						printf(!isEmpty(list) ? "Contains Values" : "Empty");
						break;
					case 3:
						display(list);
						break;
					case 4:
						printf("Enter item: ");scanf("%d",&item);
							printf(contains(list,item) ? "Item Exists!" : "Doesn't Exist");
						break;
					case 5:
						if(list->count == list->size){
							list->size *= 2;
							list = (List) realloc(list,list->size*sizeof(List));
							list->items = (int*) realloc(list->items,list->size*sizeof(int));
						}
						printf("Enter index: ");scanf("%d",&i);
							printf("\nEnter item: ");scanf("%d",&item);
								insertAfter(list,item,i);
						break;
					case 6:
						printf("Enter item: ");scanf("%d",&item);
							removeItem(list,item);
						break;
					case 7:
						if(list->count == list->size){
							list->size *= 2;
							list = (List) realloc(list,list->size*sizeof(List));
							list->items = (int*) realloc(list->items,list->size*sizeof(int));
						}
						printf("Enter item: ");scanf("%d",&item);
							addEnd(list,item);
						break;
					case 8:
						if(list->count == list->size){
							list->size *= 2;
							list = (List) realloc(list,list->size*sizeof(List));
							list->items = (int*) realloc(list->items,list->size*sizeof(int));
						}
						printf("Enter item: ");scanf("%d",&item);
							addFront(list,item);
						break;
					case 9:
						removeFront(list);
						break;
					case 10:
						printf("Enter index: ");scanf("%d",&i);
							removeIndex(list,i);
						break;
					case 11:
						Exit();
						return 0;
						break;
					default:
						printf("\nInvalid Choice!\n");
						break;
				}
					printf("\n");system("pause");
		}while (rep == '\r' || '\r');
}

List newList(int size){
	List l;
		l = (List) malloc(size*sizeof(List));
			l->items = (int*) malloc(size*sizeof(int));
				l->size = size;
					l->count = 0;
						printf("List created.");
	return l;
}

int isEmpty(List list){
	if (list->count == 0)
		return 1;
	return 0;
}

void display(List list){
	if (isEmpty(list) == 1){
		printf("Set is Empty");
		return;
	}
		int i;
			printf("Set: ");
				for (i = 0; i <list->count; i++){
					if (i + 1 == list->count){
						printf("%d ",list->items[i]);
					} else {
						printf("%d ",list->items[i]);
					}
				}
						printf("\n");
}

bool contains(List list, int item){
	int i;
		for (i = 0; i < list->count; i++){
			if (list->items[i] == item)
				return true;
		}
	return false;
}

void insertAfter(List list,int item, int i){
	int j;
		list->count++;
			for (j = list->count-1; j >= i; j--){
				list->items[j+1] = list->items[j];
			}
				list->items[i] = item;
}

void addEnd(List list,int item){
	int i = list->count;
		list->items[i] = item;
			list->count = i+1;
}

void addFront(List list,int item){
	int i;
		list->count++;
			for (i = list->count-1; i >= 0; i--){
				list->items[i+1] = list->items[i];
			}
				list->items[0] = item;
}

void removeFront(List list){
	int i;
		for (i = 1; i < list->count; i++){
			list->items[i-1] = list->items[i];
		}
			list->count--;
}

void removeItem(List list, int item){
	int i,j;
		for (i = 0; i < list->count; i++){
			if (item == list->items[i]){
				for (j = i; j < list->count; j++){
					list->items[j] = list->items[j + 1];
				}
					printf("\nItem Removed\n");
					break;
			}
		}
			list->count--;
}

void removeIndex(List list, int i){
	int j;
		for (j = i+1; j < list->count; j++){
			list->items[j - 1] = list->items[j];
		}
			list->count--;
}

void Exit(List list){
	List l;
	system("cls");
		printf_s("Exiting...");
}

void menu(){
	printf("1.NewList\n2.IsEmpty\n3.Display\n4.Contains\n5.InsertAfter\n6.RemoveItem\n7.AddEnd\n8.AddFront\n9.RemoveFront\n10.RemoveIndex\n11.Exit\n\nChoice: ");
}
