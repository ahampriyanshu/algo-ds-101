#include <stdio.h>
#include <math.h>

int main(){
	double principle, rate, timeSpan;

    printf("Enter the principle amount\n");
    scanf(" %lf", &principle);

    printf("Enter the compound rate of interest\n");
    scanf(" %lf", &rate);

    printf("Enter the time span or number of times the amount gets compounded\n");
    scanf(" %lf", &timeSpan);
  
    /* Calculate compound interest */
    /*Formula to calculate final amount after applying compound interest is given by:
	FinalAmount = (principle)*((1 + (rate)/100)^(timeSpan))*/
    double FinalAmount = principle * (pow((1 + rate / 100), timeSpan)); 

    printf("Final amount after applying Compound interest = %lf\n", FinalAmount);
  
    return 0;
}

