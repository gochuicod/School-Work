#include <stdio.h>

int main(){
	int a,b,c;
	char rep, num;
	
	do {
		system("cls");
		printf ("Please enter a number for A:");
		a = getNum();
		printf ("Please enter a number for B:");
		b = getNum();
		printf ("Please enter a number for C:");
		c = getNum();
		
		if (a < 0 || b < 0 || c < 0) {
			printf ("\nPlease enter positive integers.");
			rep = 'y';
		
		} else 
		
		display(a,b,c);
		printf ("\n\nDo you want to continue?");
		rep = getche(num);
		
	}while (rep == 'y' || rep == 'Y');
		
	return 0;
}
