//Problem Description: A program that displays time in hours, minutes and seconds

#include <stdio.h>

void main (void){
	int time, seconds, minutes, hours;
		printf ("Enter time in <seconds>:");scanf("%d",&time);
			hours = time / 3600;
			minutes = time %3600 / 60;
			seconds = time % 60;
		printf ("%dhours %dminutes %dseconds",hours, minutes, seconds);
}
