/***

Guidelines to run this code:
	->Ensure you have latest version of c compiler
	->Compile and Run either through User Interface or Command Line.
		Example for gcc compiler,
				gcc Sum_Of_GP.c
				./a.out(for Linux) or a(for Windows)
				

***/

/***

About the approach:
	->Formula used: a(r^n - 1)/(r - 1)
		. a is first term
		. r is common ratio
		. n is number of terms
		of the geometric sequence
	->some values of common ratio are handled differently
	->Time Complexity: O(n) where n is number of terms in the geometric sequence
	->Space Complexity: O(1)
	->It is considered that a,r and n are given by the user and sum is within double datatype limits

***/
#include<stdio.h>

/*
arguments:
	base value and the exponent term
returns:
	result obtained by calculating the power of the base raised to the exponent term given
*/
double power(double base,double exponent)
{
	double result = 1.0;
	for(int i = 1;i <= exponent;i++)
	{
		result *= base;
	}
	return result;
}
	
	

int main()
{
	double first_term;
	double common_ratio;
	double num_terms;
	
	//take the first term as input from the user
	printf("Enter the first term of the GP Sequence:");
	scanf("%lf",&first_term);
	
	//take the common ratio as input from the user
	printf("Enter the common ratio of the GP Sequence:");
	scanf("%lf",&common_ratio);
	
	//take the number of terms as input from the user
	printf("Enter the number of terms in the GP Sequence:");
	scanf("%lf",&num_terms);
	
	//wrong case:number_of_terms is negative
	if(num_terms < 0)
	{
		printf("Sum of the given Geometric Sequence is not possible due to negative number of terms\n");
	}
	
	//case 1:common_ratio is zero,hence the general formula fails as 0/0 is encountered
	else if(common_ratio == 0) 
	{
		printf("Sum of the given Geometric Sequence is %lf\n",first_term);
	}
	
	//case 2:common_ratio is one,hence again the general formula fails as 0/0 is encountered
	else if(common_ratio == 1)
	{
		printf("Sum of the given Geometric Sequence is %lf\n",first_term * num_terms);
	}
	
	//case 3:other values
	else
	{
		double result = (first_term * (power(common_ratio,num_terms) - 1)) / (common_ratio - 1);
		
		printf("Sum of the given Geometric Sequence is %lf\n",result);
	}
		
	return 0;
}
	
	
	
	