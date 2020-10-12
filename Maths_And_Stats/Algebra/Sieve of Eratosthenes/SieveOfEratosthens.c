/*C program to print all prime number less than or equal to n using Sieve of Eratosthenes*/

#include<stdio.h>
#include<stdbool.h>

void SieveOfEratosthenes(int num)
{
	/*Boolean array to mark a number is prime or not*/
	bool prime[num+1];
	int i,j;
	
	/*Initialisation(Mark all number as prime)*/
	for(i=0;i<=num;i++)
	prime[i]=true;
	
	/*Zero is not prime*/
	prime[0]=false;
	
	/*One is not prime*/
	prime[1]=false;
	
	/*Mark all non prime number as false*/
	for(i=2;i<=num;i++){
		if(prime[i]==true){
			for(j=i*i;j<=num;j+=i)
			prime[j]=false;
		}
	}
	/*Print all the prime numbers*/
	for(i=2;i<=num;i++){
		if(prime[i]==true)
		printf("%d ",i);
	}
	printf("\n");
}

int main()
{
	int num;
	/*Take input from the user*/
	scanf("%d",&num);
	/*Prime number generation using Sieve of Eratosthenes*/
	SieveOfEratosthenes(num);
	return 0;
}
