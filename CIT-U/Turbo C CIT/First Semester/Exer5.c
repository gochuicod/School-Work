//Problem Description: Display the reverse of the raw input integer ( limit of 5 integers ) in the form of functions.

#include <stdio.h>

int getNum();
int reverseNum(int num);
void display (int getNum, int reverseNum);

int main (){
	int iN, rev;
		iN = getNum();
		rev = reverseNum(iN);
		display (iN, rev);
}

int getNum(){
	int iN;
		printf ("Enter 5 digit number here:");scanf("%d",&iN);
	return iN;
}

int reverseNum (int iN){
	int rev;
		return rev = (iN % 10)*10000 + ((iN/10)%10)*1000 + ((iN/100)%10)*100 + ((iN/1000)%10)*10 + (iN/10000)*1;
}

void display (int getNum, int reverseNum){
		printf ("The number in reverse:%d",reverseNum);
	return;	
}
