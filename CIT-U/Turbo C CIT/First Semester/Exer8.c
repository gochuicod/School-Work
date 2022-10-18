//Problem Description: A program that increments an input in this pattern ( 1, 2, 3, 4, 5 ... ) starting from 0.

#include <stdio.h>

int getNum();
void display (int n);

int main (){
	int n;
		n = getNum();
			display (n);
	return 0;
}
	
int getNum(){
	int n;
		printf ("Enter a number: ");scanf("%d",&n);
	return n;
}
	
void display (int n){  
   	int res = 0, c = 1;
	   	do{
	   		printf ("%d ",res);
	   		res = res + c;
	   		c++;
		}while (c <= n);
   	return; 
}
