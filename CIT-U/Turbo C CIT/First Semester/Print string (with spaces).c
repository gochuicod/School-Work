#include <stdio.h>
#include <windows.h>
void gotoxy(int x, int y);

int main(){
	int load;
	float tuition, misc, reg, total, health;
	char cy[15], name[50], id[15];
		
		//gotoxy(20,2);
		printf("%40s", "OXFORT UNIVERSITY\n"); // "%[insert any number]s" , "[insert any string]" this also functions similar to "gotoxy" but only moves text to the right
		//gotoxy(24,3);
		printf("%35s", "Cebu City");
		
		gotoxy(5,5);printf("Name: ");
		scanf("%[^\n]s",name);  //Includes the spaces to be stored
		gotoxy(35,5);printf("I.D. no.: ");
		scanf("%s", &id);
		gotoxy(5,7);printf("Course & Year: ");
		scanf("%s", &cy);
		gotoxy(35,7);printf("Total Unit Load:");
		scanf("%d", &load);
		
		gotoxy(17, 10);printf("Tuition Fee\t  : %.2f", tuition = 309.99*load);
		gotoxy(17, 12);printf("Miscellaneous Fee: %.2f", misc = tuition * 0.20);
		gotoxy(17, 14);printf("Registration Fee : %.2f", reg = 1000);
		gotoxy(17, 16);printf("Health Insurance : %.2f", health = 10);
		gotoxy(36, 17);printf("-------");
		gotoxy(17, 18);printf("Tuition Fee\t  : %.2f", total = tuition + misc + reg + health);

	return 0;
}

void gotoxy(int x, int y){
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
