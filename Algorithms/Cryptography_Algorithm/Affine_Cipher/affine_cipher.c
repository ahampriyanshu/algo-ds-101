#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 100000

int CalcGCD(int);

int CalcGCD(int alpha)
{
	int x;
	int temp1 = alpha;
	int temp2 = 26;

	while (temp2 != 0)
	{
		x = temp2;
		temp2 = temp1 % temp2;
		temp1 = x;
	}
	return (temp1);
}

int main()
{
	int i, j, k, gcd, alpha, beta, numstr[100], numcipher[100];

	char str[100], cipher[100];

	printf("Enter a string\n");

	fgets(str, MAX, stdin);

	for (i = 0, j = 0; i < strlen(str); i++)
	{
		if (str[i] != ' ')
		{
			str[j] = toupper(str[i]);
			j++;
		}
		else
		{
			str[j] = ' ';
			j++;
		}
	}

	str[j] = '\0';

	printf("Enter Alpha value and must be between 1 and 25 both included\n");
	scanf("%d", &alpha);

	if (alpha < 1 || alpha > 25)
	{
		printf("Alpha should lie in between 1 and 25\nSorry Try again !\n");
		exit(0);
	}

	gcd = CalcGCD(alpha);

	if (gcd != 1)
	{
		printf("gcd(alpha,26)=1 but \n gcd(%d,26)=%d\nSorry Try again !\n", alpha, gcd);
		exit(0);
	}

	printf("Enter Beta value and must be between 0 and 25 both included\n");
	scanf("%d", &beta);

	if (beta < 0 || beta > 25)
	{
		printf("Beta value should lie between 0 and 25\nSorry Try again !\n");
		exit(0);
	}

	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] != ' ')
			numstr[i] = str[i] - 'A';
		else
			numstr[i] = -20;
	}

	printf("Affine Cipher text is: ");

	for (i = 0; i < strlen(str); i++)
	{
		if (numstr[i] != -20)
		{
			numcipher[i] = ((alpha * numstr[i]) + beta) % 26;
			printf("%c", (numcipher[i] + 'A'));
		}
		else
		{
			printf(" ");
		}
	}

	printf("\n");

}
