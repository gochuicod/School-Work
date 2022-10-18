#include "arrayOptn.h"

int main(){
	int switch_case, item, item_sub, k, n, index, asc_desc, la[99999];
	char rep, num;
	system("color 1F");
		do{
			system("cls");
			drawDBox(4,0,27,18);
			menu();
			scanf("%d", &switch_case);
			switch(switch_case){
				case 1:
					drawDBox(30,0,65,18);
					gotoxy(35,2);printf("Enter array size: ");scanf("%d", &n);
					if (n < 0){
						drawDBox(30,0,65,4);
						gotoxy(34,2);printf("Negative inputs are disabled.");
					} else {   
						createArray(la,n);
					}
					break;
				case 2:
					if (n == 0){
						drawDBox(30,0,65,4);gotoxy(34,2);printf("Please create an array first!");
					} else {
						drawDBox(30,0,60,18);
						gotoxy(35,2);printf("These are the values");
						printArray(la,n);
					}
					break;
				case 3:
					
					if (n == 0){
						drawDBox(30,0,65,4);gotoxy(34,2);printf("Please create an array first!");
					} else {
						drawDBox(30,0,65,18);
						gotoxy(35,2);printf("Enter position: ");scanf("%d", &k);
						gotoxy(35,4);printf("Enter item: ");scanf("%d", &item);
						n = insertAtPos(la, n, item, k);
					}
					break;
				case 4:
					if (n == 0){
						drawDBox(30,0,65,4);gotoxy(34,2);printf("Please create an array first!");
					} else {
						drawDBox(30,0,65,6);gotoxy(34,2);printf("Enter item: ");scanf("%d", &item);
						insertFront(la, &n, item);
					}
					break;
				case 5:
					if (n == 0){
						drawDBox(30,0,65,4);gotoxy(34,2);printf("Please create an array first!");
					} else {
						drawDBox(30,0,65,6);gotoxy(34,2);printf("Enter index: ");scanf("%d", &index);
						removeAtPos(la,&n,index);
					}
					break;
				case 6:
					if (n == 0){
						drawDBox(30,0,65,4);gotoxy(34,2);printf("Please create an array first!");
					} else {
						drawDBox(30,0,65,6);gotoxy(34,2);printf("Enter item: ");scanf("%d", &item);
						n = removeItem(la,n,item);
					}
					break;
				case 7:
					if (n == 0){
						drawDBox(30,0,65,4);gotoxy(34,2);printf("Please create an array first!");
					} else {
						drawDBox(30,0,65,4);gotoxy(34,2);n = removeFront(la,n);
					}
					break;
				case 8:
					if (n == 0){
						drawDBox(30,0,65,4);gotoxy(34,2);printf("Please create an array first!");
					} else {
						drawDBox(30,0,65,6);gotoxy(34,2);printf("Enter item to be located: ");scanf("%d", &item);
						locateIndex(la,n,item);
					}
					break;
				case 9:
					if (n == 0){
						drawDBox(30,0,65,4);gotoxy(34,2);printf("Please create an array first!");
					} else {
						drawDBox(30,0,65,6);gotoxy(34,2);printf("Enter item: ");scanf("%d", &item);
						locateItem(la,n,item);
					}
					break;
				case 10:
					if (n == 0){
						drawDBox(30,0,65,4);gotoxy(34,2);printf("Please create an array first!");
					} else {
							drawDBox(30,0,90,10);
								gotoxy(34,2);printf("Hint! Press 1 for Ascending or Press 0 for Descending.");
									gotoxy(34,4);system("pause");
										gotoxy(34,6);printf("Sort Ascending or Descending? ");scanf("%d", &asc_desc);
											if (asc_desc == 1){
												gotoxy(34,2);sortAscending(la, n);
											} else {
												gotoxy(34,2);sortDescending(la, n);
											}
					}
					break;
				case 11:
					Exit();
					return 0;
					break;
				default:
					gotoxy(35,4);printf("Enter a valid choice!\n");
			}
					gotoxy(4,21);printf("Press any key to return to the main menu...");
					rep = getche(num);
		}while(rep == '\r' || '\r');
	return 0;
}
