/* Method:-
Sum of first N natural number = (2 * N) * (N + 1);
*/
// C Program to find sum 
// of first n natural numbers 
#include <stdio.h>

int main() {
	// declaring the variables 
	// where n is indicating the natural number 
	// and S the sum of natural number
	int n,S;
	// taking input n from user
	scanf("%d",&n);
	// Calculating the sum
	// by Arithmetic Progression formula
	S = (2*n)*(n+1);
	// display the sum
	printf("%d",S);
}