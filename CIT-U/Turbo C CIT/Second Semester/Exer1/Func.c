#include <stdio.h>

int getNum(){
		int num;
			scanf ("%d", &num);
	return num;
}

void display(int a, int b, int c){		
	int row, highest;
	
		if(a >= b && a >= c){
			highest = a;
		} else if (b >= a && b >= c){
			highest = b;
		} else {
			highest = c;
		}
		
			printf ("\n%d %d %d",a,b,c);
			printf ("\n");
		
		for (row = 1; row <= highest; row++){
			if (row <= a){
				printf ("* ");
			} else {
				printf ("  ");
			}
			if (row <= b){
				printf ("X ");
			} else {
				printf ("  ");
			}
			if (row <= c){
				printf ("@");
			} else {
				printf ("  ");
			}
			printf ("\n");
		}	
		
		
	return;
}
