#include <stdio.h>

void main(void){
	/*int row;
	
		for (row = 'A'; row <= 'Z'; row++){
			printf ("%c ", row);
		}*/ // End of English Alphabet
		
	/*int row, n, sum;
	
	scanf ("%d", &n);
		for (row = 1; row <= n; row++){
			sum += row;
		}
			printf ("%d ", sum);*/ //End of sum of all natural numbers
			
	/*int row, n, sum;
	
	scanf ("%d", &n);
		for (row = 2; row <= n; row += 2){
			sum += row;
		}
		printf ("%d ", sum);*/ // Sum of even numbers
		
	int row, n, sum;
	
	scanf ("%d", &n);
		for (row = 0; row <= n; row += 2){
			sum += row;
		}
		printf ("%d ", sum);
			
	return;
}
