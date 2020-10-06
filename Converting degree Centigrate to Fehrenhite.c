// Converting temperature from degree centigrate to degree fehrenhite

#include<stdio.h>
int main()
{
	float C,F;
	printf("temperature in centigrate= ");
	scanf("%f",&C);
	F=(1.8*C)+32;
	printf("converted temperature in fehrenhite = %f",F);
	return 0;
}
