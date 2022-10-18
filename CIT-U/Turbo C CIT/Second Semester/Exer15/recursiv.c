#include "recursiv.h"

long factorial(int n){
	if(n == 0){
		return 1;
	}
	return n*factorial(n-1);
}

int fibonacci(int n){
	if (n <= 1){
		return n;
	}
	return fibonacci(n-1) + fibonacci(n-2);
}

int tribonacci(int n){
	if(n == 0) return 0;
	if(n < 3){
		return 1;
	}
	return tribonacci(n-1)+ tribonacci(n-2) + tribonacci(n-3) ;
}

int sumNos(int n){
	if(n <= 1){
		return 1;
	}
	return n + sumNos(n-1);
}

long decimalBinary(int n){
	int r;
	// Another way to answer
//		if (n > 0){
//			r = n%2;
//			n /= 2;
//			decimalBinary(n);
//			printf("%d",r);
//		}
	
	// Shortest way to answer
	if (n < 1)
        return 0;  
    else
        return (n % 2 + 10 * decimalBinary(n / 2)); 
}

void menu(){
	printf("1.Factorial\n2.Fibonacci\n3.Tribonacci\n4.SumNos\n5.DecimalBinary\n\n");
}
