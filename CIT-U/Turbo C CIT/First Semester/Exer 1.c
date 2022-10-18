//Problem Description: A program that gets the sum of two numbers

#include <stdio.h>
int getNum();
int computeSum(int sum, int num1, int num2);

int main(){
	int num1, num2;
	int sum;
		num1 = getNum();
		num2 = getNum();
		printf("Sum = %d", computeSum(sum,num1,num2));
return 0;
}

int getNum(){
	int num;
		printf ("Enter number:");
		scanf ("%d",&num);
	return num;
}

int computeSum(int sum, int num1, int num2){
	return sum = num1+num2;
}
