//Problem Description: Display the reverse of the raw input integer ( limit of 5 integers ) in sequential form

#include <stdio.h>

int main (){	
	int num, i, r = 0;
		printf("Input integer:");scanf("%i",&num);
		
	for(i = 5; i>0 &num>0; i--){
		r = num % 10;
		printf("%d", r);
		num = (num - (num%10))/10;
	}
}
