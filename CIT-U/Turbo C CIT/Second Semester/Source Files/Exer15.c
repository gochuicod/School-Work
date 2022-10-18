#include <stdio.h>
#include <windows.h>

long factorial(int N);
int fibonacci(int n);
int tribonacci(int n);
int sumNos(int n);
long decimalBinary(int n);
void menu();

int main(){
	int n;
	int choice;
	while(1){
		menu();
		printf("Enter choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:{
				printf("Enter n: ");
				scanf("%d",&n);
				printf("Factorial of %d is: %d\n",n,factorial(n));
				break;
			}
			case 2:{
				printf("Enter n: ");
				scanf("%d",&n);
				printf("Fibonacci of term (%d): %d\n",n,fibonacci(n));
				break;
			}
			case 3:{
				printf("Enter n: ");
				scanf("%d",&n);
				printf("Tribonacci of term (%d): %d\n",n,tribonacci(n));
				break;
			}
			case 4:{
				printf("Enter n: ");
				scanf("%d",&n);
				printf("Sum of Nos: %d\n",sumNos(n));
				break;
			}
			case 5:{
				printf("Enter n: ");
				scanf("%d",&n);
				printf("The binary conversion of %d is %d\n",n,decimalBinary(n));
				break;
			}
		}
		system("pause");
		system("cls");	
	}
	return 0;
}

long factorial(int n){
	if(n == 0){
		return 1;
	}
	return n*factorial(n-1);
}

int fibonacci(int n){
	if(n == 0){
		return 0;
	}else if(n < 2){
		return 1;
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
	if(n == 1){
		return 1;
	}
	return n + sumNos(n-1);
}

long decimalBinary(int n){
	if (n == 0)  
        return 0;  
    else
        return (n % 2 + 10 *  
                decimalBinary(n / 2)); 
}

void menu(){
	printf("1.Factorial\n2.Fibonacci\n3.Tribonacci\n4.SumNos\n5.DecimalBinary\n\n");
}
