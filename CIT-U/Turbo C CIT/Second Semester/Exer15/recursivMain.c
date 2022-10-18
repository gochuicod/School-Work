#include "recursiv.h"

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
