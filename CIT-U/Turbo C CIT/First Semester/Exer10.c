//Problem Description: A program that creates a certain pattern ( arrowhead )

#include <stdio.h>

int getNum();
void display(int n);

int main (){
	int n;
		n = getNum();
			display(n);
	return 0;
}
	
int getNum(){
	int n;
		printf ("Enter a number: ");scanf("%d",&n);
	return n;
}
	
void display(int n){
	int row;
	int col;
	for (row = 1; row <n; row++){
		for (col = 1; col <= (row - 1); col++){
			printf (" ");}
			for (col = 1; col <= n; col++){
				printf ("*");}
						printf ("\n");}
	for (row; row > 0; row--){
		for (col = 1; col <= (row - 1); col++){
			printf (" ");}
			for (col = 1; col <= n; col++){
				printf ("*");}
					printf ("\n");}
		return;
	}
