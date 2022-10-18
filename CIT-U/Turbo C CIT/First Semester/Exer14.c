//Problem Description: A program that converts decimal to binary, octal or hexadecimal

#include <stdio.h>
#include <math.h>
#include <windows.h>

int toBinary(int n);
int toOct(int n);
void toHex(char arr[], int size, int n);
void menu();
void Exit();
void gotoxy(int x, int y);

int main(){
	int num, n, rep;
	char arr[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
		gotoxy(5, 16);printf ("Enter a decimal number:");scanf ("%d", &n);
			do{
				system("cls");menu();
					gotoxy(5, 12);printf ("Enter a valid choice [1-4]:");scanf ("%d", &num);
						switch(num){
							case 1: 
								gotoxy(5, 16);printf("Binary Value: %d",toBinary(n));
								break;
							case 2:
								gotoxy(5, 16);printf("Octal Value: %d",toOct(n));
								break;
							case 3:
								gotoxy(5, 16);toHex(arr, 16, n);
								break;
							case 4:
								system("cls");
									Exit();
										return 0;
								break;
							default:
								gotoxy(5, 16);printf("Please enter a valid number!");
						}
							gotoxy (5, 18);system("pause");
			}while (rep == 'y' || 'Y');
	return 0;
}

int toBinary(int n){
	long long bin = 0;
    int rem, i = 1, step = 1;
	    while (n != 0) {
	        rem = n % 2;
	        n /= 2;
	        bin += rem * i;
	        i *= 10;
	    }
    return bin;
}

int toOct(int n){
	long octalNumber = 0, i = 1;
    int remainder, count = 0;
    
	    while(n != 0){
	        remainder = n % 8;
	        n = n / 8;
	        octalNumber = octalNumber + remainder * pow(10, count);
	        count++;
	    }
	    
	return octalNumber;
}

void toHex(char arr[], int size, int n){
	long int decimalNumber,remainder,quotient;
	int i=1,j,temp;
	
		quotient = n;
		
			while(quotient!=0) {
				temp = quotient % 16;
				
			if(temp < 10)
				temp = temp + 48; 
			else
				temp = temp + 55;
					arr[i++]= temp;
						quotient = quotient / 16;
			}
				printf("Hex Value: ",n);
			
			for (j = i - 1; j > 0; j--){
				printf("%c",arr[j]);
			}
	return;
}


void menu(){
	int i;
		gotoxy(2, 0);printf ("%c", 201);
		gotoxy(35, 0);printf ("%c", 187);
		gotoxy(2, 14);printf ("%c", 200);
		gotoxy(35,14);printf ("%c", 188);
		
			for (i = 3; i < 35; i++){
				gotoxy(i, 14);printf ("%c", 205);
				gotoxy(i, 0);printf ("%c", 205);
				}
			for (i = 1; i < 14; i++){
				gotoxy(2, i);printf ("%c", 186);
				gotoxy(35, i);printf ("%c", 186);
				}
		gotoxy(5, 2);printf ("Conversion from Decimal to:");
		gotoxy(12, 4);printf ("1. Binary");
		gotoxy(12, 6);printf ("2. Octal");
		gotoxy(12, 8);printf ("3. Hexadecimal");
		gotoxy(12, 10);printf ("4. Exit");
}

void Exit(){
	printf ("Exiting...");
}

void gotoxy(int x, int y){
	COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
