#include <stdio.h>
#include <windows.h>

int main(){
	int time, hours, mins, sec, coinValue, quarter, dime, penny, n1;
	char rep, num, choice, s;
		do{
			system("cls");
			drawDBox(2,0,21,13);
			menu();
			s = getche(choice);
			switch(s){
				case 'a':
					gotoxy(28,2);drawDBox(25,0,60,6);
					gotoxy(28,2);printf("Enter time (in seconds): ");scanf("%d", &time);gotoxy(28, 2);
					if (time >= 0){
						convertTime(time,&hours,&mins,&sec);
					} else {
						gotoxy(28,4);printf("Enter a positive number!");
					}
					break;
				case 'b':
					gotoxy(28,2);drawDBox(25,0,65,6);
					gotoxy(28,2);printf("Enter coin amount (in cents): ");scanf("%d", &coinValue);gotoxy(28, 2);
					computeCoin(coinValue,&quarter,&dime,&penny);
					break;
				case '1':
					gotoxy(28,2);drawDBox(25,0,78,4);
					displayTime(time,&hours,&mins,&sec);
					break;
				case '2':
					gotoxy(28,2);drawDBox(25,0,72,4);
					displayCoin(coinValue,&quarter,&dime,&penny);
					break;
				case 'd':
					Exit();
					return 0;
					break;
				default:
					gotoxy(2,15);printf("Enter a valid choice!");
					rep = 'y';
			}
			gotoxy(2,17);printf("\n Press Y to return to the main menu.");
			rep = getche(num);
		}while(rep = 'Y' || 'y');
	return 0;
}
