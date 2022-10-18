#include <stdio.h>
#include <math.h>
#include <windows.h>
#include "quadratic.h"

int main(){
	Quadratic q, q1;
	float a,b,c,root;
	int x, choice;
	char num, rep;
	system("color 70");
		do{
			system("cls");
				drawDBox(4,0,35,14);menu();//prints menu with box
					drawDBox(37,0,67,6);//prints second box
						gotoxy(18,12);scanf_s("%d",&choice);
							switch(choice){
								case 1:
									discriminant(&q);
									break;
								case 2:
									if(isImaginary(&q)==1){
										gotoxy(48,3);puts("Imaginary");
									} else {
										gotoxy(46,3);puts("Not Imaginary");
									};
									break;
								case 3:
									gotoxy(50,3);printf(firstRoot(&q) > 0 || firstRoot(&q) < 0 ? "%.2f" : "Math Error",firstRoot(&q));
									//printf(firstRoot(&q) > 0 ? "%.2f" : (firstRoot(&q) < 0 ? "%.2f" : "Math Error"),firstRoot(&q)); Hint: Use else if with variable in quantity
									break;
								case 4:
									gotoxy(50,3);printf(secondRoot(&q) > 0 || firstRoot(&q) < 0 ? "%.2f" : "Math Error",secondRoot(&q));
									break;
								case 5:
									gotoxy(40,3);display(&q);
									break;
								case 6:
									gotoxy(40,2);printf_s("Enter value of x: ");scanf_s("%d",&x);
										gotoxy(40,4);printf_s("Output: %d",getValue(q,x));
									break;
								case 7:
									Exit();
									return 0;
									break;
								default:
									gotoxy(42,3);printf("%s",warning);
							}
									gotoxy(4,16);system("pause");
		}while(rep == '\r' || '\r');
return 0;
}
