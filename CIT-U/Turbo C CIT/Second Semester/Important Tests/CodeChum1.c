#include <stdio.h>
#include <math.h>
#define MAX_SIZE 100  // Maximum array size

int main(){
    int arr[MAX_SIZE];
    int size, i, toSearch, found;
    
    printf("Hello World\n\n");//Start and End of print
    
    float area,n;// Start of square backyard
    	printf("Enter the number of the square backyard: ");
        scanf("%f",&n);
        area = pow(n,2);
        printf("%.2f\n\n", area);// End of square backyard
        
	int h,n1,n2,n3;// Start of Biggest Integer
		printf("Enter three numbers: ");
		scanf("%d %d %d",&n1,&n2,&n3);
	if(n1>=n2&&n1>=n3)
		h=n1;
	else if(n2>=n1&&n2>=n3)
		h=n2;
	else
		h=n3;
		printf("Biggest Integer: %d\n\n", h);// End of Biggest Integer
		
 	int j, n4;// Start of Asterisk Pattern
 		printf("Enter a number for pattern: ");
		scanf("%d",&n4);
			for(i=1;i<=n4;i++){
				for(j=1;j<=i;j++){
					printf("*");
				}
					printf("\n");
			}// End of Asteriks Pattern	

	// START OF LOCATING ELEMENT
    /* Input size of array */
    printf("\nEnter size of array: ");
    scanf("%d", &size);

    /* Input elements of array */
    printf("Enter elements in array: ");
    for(i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }

    printf("\nEnter element to search: ");
    scanf("%d", &toSearch);

    /* Assume that element does not exists in array */
    found = 0; 
    
    for(i=0; i<size; i++){
        /* 
         * If element is found in array then raise found flag
         * and terminate from loop.
         */
        if(arr[i] == toSearch){
            found = 1;
            break;
        }
    }

    /*
     * If element is not found in array
     */
    if(found == 1){
        printf("\n%d is found at position %d", toSearch, i + 1);
    }
    else
    {
        printf("\n%d is not found in the array", toSearch);
    }
    // END OF LOCATING ELEMENT
    return 0;
}
