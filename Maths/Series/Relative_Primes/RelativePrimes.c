#include<stdio.h>

void main(){
        int p,i,j;
        int remainder = 2;
        int divident,divisor;

        printf("Enter Number\n");
        scanf("%d",&p);

        for(i = 2 ; i < p ; i++){

                divident  = p;
                divisor = i;

                while(divisor != 0){

                        remainder = divident % divisor;
                        divident  = divisor;
                        divisor  = remainder;
                }
       
                if(divident  == 1){
                        printf("Relatively Prime Number is : %d \n" ,i);
                }
        }

}

/* Output:
Enter Number 
8
Relatively Prime Number is : 3
Relatively Prime Number is : 5
Relatively Prime Number is : 7 */
 
