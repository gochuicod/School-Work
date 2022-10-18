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
void isEmpty(List list);
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
	List list,l;
	int choice,size,item,i;
	char rep;
		do{
			system("cls");menu();
			scanf("%d",&choice);
				switch(choice){
					case 1:
						printf("\nHow much to allocate? ");scanf("%d",&size);
							printf("\n");
								newList(size);
						break;
					case 2:
						isEmpty(list);
						break;
					case 3:
						display(list);
						break;
					case 4:
						printf("Enter item: ");scanf("%d",&item);
							printf(contains(list,item) ? "Item Exists!" : "Doesn't Exist");
						break;
					case 5:
						printf("Enter index: ");scanf("%d",&i);
							printf("\nEnter item: ");scanf("%d",&item);
								insertAfter(list,item,i);
						break;
					case 6:
						printf("Enter item: ");scanf("%d",&item);
							removeItem(list,item);
						break;
					case 7:
						printf("Enter item: ");scanf("%d",&item);
							addEnd(list,item);
						break;
					case 8:
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
		int i;
			l->items = (int*)calloc(size,sizeof(int));
				printf("How many items?");scanf("%d",&l->count);printf("\n");
					for (i = 0; i < l->count; i++){
						printf("[%d]: ",i);scanf("%d",&l->items[i]);
					}
						l->size = size;
}

void isEmpty(List list){
	List l;
		int i, temp = 0;
			for (i = 0; i < l->size; i++){
				if (l->count == 0){
					temp += 0;
				} else {
					temp ++;
				}
			}
				if (temp == 0){
					printf("\nIt has no values\n");
				} else {
					printf("\nIt has values\n");
				}
}

void display(List list){
	List l;
		int i;
			for (i = 0; i < l->size; i++){
				printf("\n[%d]: %d",i,l->items[i]);
			}
}

bool contains(List list, int item){
	List l;
		int i;
			for (i = 0; i < l->size; i++){
				if (item == l->items[i]){
					return true;
				}
			}
	return false;
}

void insertAfter(List list,int item, int i){
	List l;
		int j,k,choice;
			for (k = 0; k < l->size; k++){
				if (item != l->items[k]){
					for (k = l->size; k >= i; k--){
						l->items[k] = l->items[k - 1];
					}
						l->items[i] = item;
						printf("Item Added");
						break;
				}
			}
						l->count++;
}

void addEnd(List list,int item){
	List l;
		int i;
			for (i = 0; i < l->size; i++){
				l->items[l->count] = item;
				break;
			}
				printf("\nItem Added\n");
				l->count++;
}

void addFront(List list,int item){
	List l;
		int i;
			if (l->count == l->size){
				l->size *= 2;
				l = (List) realloc(l,l->size*sizeof(List));
				l->items = (int*) realloc(l->items,l->size*sizeof(int));
			} else {
				for (i = l->size; i > 0; i--){
					l->items[i] = l->items[i - 1];
				}
				for (i = 0; i < l->size; i++){
					l->items[0] = item;
				break;
				}
					printf("\nItem Added\n");
						l->count++;
			}
}

void removeFront(List list){
	List l;
		int i,j = 0;
			for (i = 0; i < l->size; i++, j++){
				l->items[j] = 0;
				break;
			}
				printf("\nItem Removed\n");
					l->count--;
}

void removeItem(List list, int item){
	List l;
		int i, j;
			for (i = 0; i < l->size; i++){
				if (item == l->items[i]){
					for (j = i; j < l->size; j++){
						l->items[j] = l->items[j + 1];
					}
						printf("\nItem Removed\n");
						l->count--;
						break;
				}
			}
}

void removeIndex(List list, int i){
	List l;
		int j,k;
			for (j = 0; j < l->size; j++){
				if (i == j){
					l->size-=1;
					break;
				} else {
					l->size;
				}
			}
			for (j = 0, k = 0; j < l->size; j++, k++){
				l->items[k] = l->items[k + 1];
			}
				printf("\nItem Removed\n");
}

void Exit(List list){
	List l;
	system("cls");
		printf_s("Exiting...");
}

void menu(){
	printf("1.New List\n2.Is Empty\n3.Display\n4.Contains\n5.Insert After\n6.Remove Item\n7.Add End\n8.Add Front\n9.Remove Front\n10.RemoveIndex\n11.Exit\n\nChoice: ");
}
