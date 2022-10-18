/*#include<stdio.h>
int main()
{
    int yr;

    scanf ("%d", &yr);

    if (yr%4 == 0 && yr%100 == 0 && yr%400 == 0)
        printf("Leap Year");

    else if (yr%4==0 && yr%100!=0)
        printf("Leap Year");
    else
        printf ("Not a Leap Year");

    return 0;
}*/																			//LEAP YEAR PROBLEM NO.1 IN CODECHUM (URIEL)

/*#include <stdio.h>

int main(){
 	float package_A = 250.00, package_B = 5000.00, package_C1 = 8000.00, package_C2 = 14000.00, package_C3 = 18000.00, additional_gallons = 0.002, package_a, package_b;
    int gallons_used;
    char package_type, pType;
        printf("Type of package: ");pType = getche();
        printf("\n\nNumber of gallons: ");scanf("%d",&gallons_used);
        if (pType == 'A' || pType == 'a'){
        	if (gallons_used == 0){
        		printf("P: 0");
			} else {
				package_a = package_A + (gallons_used * additional_gallons);
        		printf("\nP%.2f", package_a);
			}
		} else if (pType == 'B' || pType == 'b' && gallons_used > 4000000){
			if (gallons_used < 4000000){
				printf("\nP%.2f", package_B);
			} else if (gallons_used > 4000000){
				package_b = package_B + ((gallons_used - 4000000) * additional_gallons);
				printf("\nP%.2f", package_b);
			}
		} else if (pType == 'C' || pType == 'c'){
			if (gallons_used < 4000000){
				printf("\nP%.2f", package_C1);
			} else if (gallons_used > 4000000 && gallons_used < 10000000){
				printf("\nP%.2f", package_C2);
			} else if (gallons_used > 10000000){
				printf("\nP%.2f", package_C3);
			}
		}																					
	return 0;
}*/																			//PACKAGE PROBLEM NO.2 IN CODECHUM (URIEL)

/*#include <stdio.h>

int main(){
	int first_integer, second_integer;
		scanf("%[^\n]d", first_integer);
		scanf("%d", second_integer);
}*/

/*#include <stdio.h>
 
int main(void){
	int first_integer, second_integer;
        scanf ("%d,%d", &first_integer, &second_integer);
        	if (first_integer % second_integer == 0 || second_integer % first_integer == 0){
				printf("divisible");
        	} else {
        		printf("not");
			}
			
//			else if (first_integer / second_integer != 1 || second_integer / first_integer != 1){
  //      		printf("not");
	//		}
	return 0;
}*/

/*#include <stdio.h>

int main(){
	char operatorr;
	float number_1, number_2, sum, difference, quotient, product;

	printf("Enter operation: ");operatorr = getche();
	printf("\nEnter two numbers: ");scanf("%f %f", &number_1, &number_2);

		if (operatorr == '+'){
			sum = number_1 + number_2;
			printf("\nSum = %.3f", sum);
		} else if ( operatorr == '*'){
			product = number_1 * number_2;
			printf("\nProduct = %.3f", product);
		}else if ( operatorr == '-'){
			difference = number_1 - number_2;
			printf("\nDifference = %.3f", difference);
		} else if ( operatorr == '/'){
			quotient = number_1 / number_2;
			printf("\nQuotient = %.3f", quotient);
		}	
	return 0;
	
	float kWh_100 = 150.00, kWh_500 = 350.00, total_kWh;
	int input;
	
		scanf("%d", &input);
		if (input > 500){
			total_kWh = kWh_500 + ((input - 500) * 0.3);
			printf("P%.2f", total_kWh);
		} else if (input >= 101 && input <= 500){
			total_kWh = kWh_100 + ((input - 100)* 0.5);
			printf("P%.2f", total_kWh);
		} else if (input >= 0 && input <= 100){
			total_kWh = kWh_100;
			printf("P%.2f", total_kWh);
		}
	return 0;
}*/
