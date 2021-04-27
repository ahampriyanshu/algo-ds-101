#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

const int N = 4;
const int K = 2;
const int prime = 256;
size_t size = 1024;

int mod_expo(int base, int exp, int mod)
{
	if (exp == 0)
	{
		return 1;
	}
	else if (exp % 2 == 0)
	{
		int mysqrt = mod_expo(base, exp / 2, mod);
		return (mysqrt * mysqrt) % mod;
	}
	else
	{
		return (base * mod_expo(base, exp - 1, mod)) % mod;
	}
}

void free_heap_mem(char **shares, int n)
{
	int i;

	for (i = 0; i < n; ++i)
	{
		free(shares[i]);
	}
	free(shares);
}


int *gcdD(int a, int b)
{
	int *xyz = malloc(sizeof(int) * 3);

	if (b == 0)
	{
		xyz[0] = a;
		xyz[1] = 1;
		xyz[2] = 0;
	}
	else
	{
		int n = floor(a / b);
		int c = a % b;
		int *r = gcdD(b, c);

		xyz[0] = r[0];
		xyz[1] = r[2];
		xyz[2] = r[1] - r[2] * n;

		free(r);
	}

	return xyz;
}

int modInverse(int k)
{
	k = k % prime;

	int r;
	int *xyz;

	if (k < 0)
	{
		xyz = gcdD(prime, -k);
		r = -xyz[2];
	}
	else
	{
		xyz = gcdD(prime, k);
		r = xyz[2];
	}

	free(xyz);

	return (prime + r) % prime;
}

int *split_number(int number, int n, int t)
{
	int *shares = malloc(sizeof(int) * n);
	int *coef = malloc(sizeof(int) * t);
	int x;
	int i;

	coef[0] = number;

	for (i = 1; i < t; ++i)
	{

#ifdef HAVE_ARC4RANDOM
		coef[i] = arc4random_uniform(prime);
#else
		coef[i] = rand() % (prime);
#endif
	}

	for (x = 0; x < n; ++x)
	{
		int y = coef[0];

		for (i = 1; i < t; ++i)
		{
			int temp = mod_expo(x + 1, i, prime);

			y = (y + (coef[i] * temp % prime)) % prime;
		}
		y = (y + prime) % prime;

		shares[x] = y;
	}

	free(coef);

	return shares;
}

char **split_string(char *secret, int n, int t)
{
	int len = strlen(secret);

	char **shares = malloc(sizeof(char *) * n);
	int i;

	for (i = 0; i < n; ++i)
	{

		shares[i] = (char *)malloc(2 * len + 6 + 1);

		sprintf(shares[i], "%02X%02XAA", (i + 1), t);
	}

	for (i = 0; i < len; ++i)
	{
		int letter = secret[i];

		if (letter < 0)
		{
			letter = prime + letter;
		}

		int *chunks = split_number(letter, n, t);
		int j;

		for (j = 0; j < n; ++j)
		{
			if (chunks[j] == prime)
			{
				sprintf(shares[j] + 6 + i * 2, "G0");
			}
			else
			{
				sprintf(shares[j] + 6 + i * 2, "%02X", chunks[j]);
			}
		}

		free(chunks);
	}

	return shares;
}

int join_shares(int *xy_pairs, int n)
{
	int secret = 0;
	long numerator;
	long denominator;
	long startposition;
	long nextposition;
	long value;
	int i;
	int j;

	for (i = 0; i < n; ++i)
	{
		numerator = 1;
		denominator = 1;

		for (j = 0; j < n; ++j)
		{
			if (i != j)
			{
				startposition = xy_pairs[i * 2];
				nextposition = xy_pairs[j * 2];
				numerator = (numerator * -nextposition) % prime;
				denominator = (denominator * (startposition - nextposition)) % prime;
			}
		}

		value = xy_pairs[i * 2 + 1];

		secret = (secret + (value * numerator * modInverse(denominator))) % prime;
	}

	secret = (secret + prime) % prime;

	return secret;
}

char *decode(char **shares, int n)
{

	if ((n == 0) || (shares == NULL) || (shares[0] == NULL))
	{
		return NULL;
	}
	int len = (strlen(shares[0]) - 6) / 2;

	char *result = malloc(len + 1);
	char codon[3];
	codon[2] = '\0';

	int x[n];
	int i;
	int j;

	for (i = 0; i < n; ++i)
	{
		if (shares[i] == NULL)
		{
			free(result);
			return NULL;
		}

		codon[0] = shares[i][0];
		codon[1] = shares[i][1];

		x[i] = strtol(codon, NULL, 16);
	}

	for (i = 0; i < len; ++i)
	{
		int *chunks = malloc(sizeof(int) * n * 2);

		for (j = 0; j < n; ++j)
		{
			chunks[j * 2] = x[j];

			codon[0] = shares[j][6 + i * 2];
			codon[1] = shares[j][6 + i * 2 + 1];

			if (memcmp(codon, "G0", 2) == 0)
			{
				chunks[j * 2 + 1] = prime;
			}
			else
			{
				chunks[j * 2 + 1] = strtol(codon, NULL, 16);
			}
		}

		char letter = join_shares(chunks, n);

		free(chunks);

		sprintf(result + i, "%c", letter);
	}

	return result;
}

char *encode(char *secret, int n, int t)
{
	char **result = split_string(secret, n, t);

	int len = strlen(secret);
	int key_len = 6 + 2 * len + 1;
	int i;

	char *shares = malloc(key_len * n + 1);

	for (i = 0; i < n; ++i)
	{
		sprintf(shares + i * key_len, "%s\n", result[i]);
	}

	free_heap_mem(result, n);

	return shares;
}

// Driver Code
int main(void)
{
	srand(time(NULL));

	int M;
	char **codes = malloc(sizeof(char *) * prime);
	char *code = malloc(sizeof(char) * prime);
	char *str = malloc(sizeof(char) * size);

	getline(&str, &size, stdin);
	char *shares = encode(str, N, K);
	puts(shares);

	printf("Enter the number of shares you want to enter to decode the orginal secret\n");
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		printf("Enter the %d share\n", i+1);
		scanf("%s", code);
		codes[i] = strdup(code);
	}
	char *secret = decode(codes, M);
	printf("The secret is : ");
	puts(secret);
	free_heap_mem(codes, M);
	free(shares);
	free(secret);
	free(code);
	free(str);
	return 0;
}
