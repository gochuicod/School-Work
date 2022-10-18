/*
	Description: A circular racetrack is composed of four portions; concrete, mud, sand, and asphalt. Sly
	Slick's car takes 30 seconds to cross the concrete, 55 seconds to cross the mud, and 47 seconds to cross
	the sand and 38 seconds to cross the asphalt. Make a program that would input the TIME (in seconds) and output
	WHERE in the track Sly's car is. Assume that the race starts at the begginning of the concrete portion.
	
	Implement the following functions:
		
	int getTime();
	char determinePos(int time);
		C - concrete
		M - mud
		S - sand
		A - asphalt
	void display(char pos);
	
	SAMPLE OUTPUT IF APPLICABLE
	
	Enter time (in seconds): 23
	Sly's car is currently at the concrete portion of the racetrack.
	
	Enter time (in seconds): 70
	Sly's car is currently at the mud portion of the racetrack.
*/
#include <stdio.h>

int getTime();
char determinePos(int time);
void display(char pos);

int main (){
	int time;
	char pos, rep, num;
		do{
			system("cls");
			time = getTime();
			pos = determinePos(time);
			display (pos);
			printf("\n\nDo you want to continue?");
			rep = getche(num);
		}while(rep == 'y' ||  rep == 'Y');
	return 0;
}

int getTime(){
	int time;
		printf ("Enter time (in seconds):");scanf("%d",&time);
	return time;
}

char determinePos(int time){
	char pos;		
		time = time % 171;
		if (time > 0 && time <= 30)
			pos = 'C';
		else if (time > 30  && time <= 85)
			pos = 'M';
		else if (time > 85 && time <= 132)
			pos = 'S';
		else if (time > 132 && time <= 170)
			pos = 'A';
		else pos = 'C';
	return pos;
}

void display (char pos){
	char *subPos;		
		if (pos == 'C')
			subPos = "concrete";
		else if (pos == 'M')
			subPos = "mud";
		else if (pos == 'S')
			subPos = "sand";
		else if (pos == 'A')
			subPos = "asphalt";
		else subPos = "concrete";
			printf ("\nSly's car is currently at the %s portion of the racetrack", subPos);
	return;
}

