#include <stdio.h>
	int getSize();
	void display(int size);
	int main(){
		int size;
		char rep;
			do{
				size = getSize();
					display (size);
				printf ("Continue?(y/n): ");
				rep = getche(size);
			}while (rep == 'y');
		return 0;
	}
	
	int getSize(){
		int size;
			printf ("\nEnter size: ");
			scanf ("%d",&size);
		return size;
	}
	
	void display(int size){
		int row;
		int col;

			for(col = 0; col <= row; col++){
					printf ("*");}// The asterisks on the top portion
					printf ("\n");
				for(row = 0; row < size; row++){
					for (col = 1; col <= (size/size); col++){
							printf ("#");}// The number sign on the left
						for (col = 1; col <= row; col++){
								printf (" ");}// The empty space on bottom left
							for(col = 1; col <= (size/size); col++){
									printf ("#");}// The number sign on the center
								for(col = 1; col <= (size/size); col++){
										printf (" ");}
										printf ("*");// The asterisks on the center
									for (col = 0; col <= size; col++){
											printf (" ");}// The empty space on the upper right
											printf ("*");// The asterisks on the right
											printf ("\n");}
										for (col = 1; col <= row; col++){
												printf ("#");}
												printf ("\n");// The asterisks on the bottom
		return;
	}
