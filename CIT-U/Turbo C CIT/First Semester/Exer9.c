//Problem Description: A program that creates a perfect square of 10x10 or (n x n)

#include <stdio.h>
	void display();
	int main(){
		display ();
	return 0;
	}
	
	void display (){
		int row;
		int col;
			for (row = 1; row <= 10; row++){
				for (col = 1; col <= 10; col++){
				printf ("*");}
					printf ("\n");}
		return;
	}
