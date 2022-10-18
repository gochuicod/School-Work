#include <stdio.h>
#include <windows.h>

int main(){
	int n, sum, a, b, c, d;
	char rep, num, choice, s;
	float ave;
		do{
			system("cls");
			drawDBox(2,0,21,11);
			menu();
			s = getche(choice);
			switch(s){
				case 'a':
					gotoxy(28,2);
					sumAll(&n,&sum);
					break;
				case 'b':
					gotoxy(28,2);
					aveAllDiv(&n,&ave);
					break;
				case 'c':
					gotoxy(28,2);
					swap(&a,&b,&c,&d);
					break;
				case 'd':
					Exit();
					return 0;
					break;
				default:
					gotoxy(2,13);printf("Enter a valid choice!");
					rep = 'y';
			}
			gotoxy(2,15);printf("\n Press Y to return to the main menu.");
			rep = getche(num);
		}while(rep == 'y' || 'Y');
	return 0;
}
