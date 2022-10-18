#include <stdio.h>
#include <windows.h>

int main(){
	int x, y;
	int x1,y1,x2,y2;
	char rep, num, l;
	
		do{
			system("cls");
			drawDBox(2, 0, 20, 11);
			switch(printCommand()){
				case 'a':
					gotoxy(2, 12);initialize(&x, &y);
					break;
				case 'b':
					gotoxy(2, 12);printLocation(x,y);
					break;
				case 'c':
					gotoxy(30, 2);move(&x,&y);
					break;
				case 'd':
					Exit();
					return 0;
					break;
				default:
					gotoxy(2, 13);
					printf("Enter a valid choice.");
					rep = 'y';
			}
			gotoxy(2, 15);
			printf("\n  Press Y to return to the main menu.");
			rep = getche(num);
		}while(rep == 'y' || 'Y');
	return 0;
}
