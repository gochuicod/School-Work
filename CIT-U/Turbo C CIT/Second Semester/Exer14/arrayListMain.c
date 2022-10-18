#include "arrayList.h"

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
