// ---------------------------------PROBLEM STATEMENT--------------------------------
//Given a number n, the task is to find out whether this number is smith number or not. 
//Smith Number is a composite number whose sum of digits is equal to the 
//sum of digits in its prime factorization.


#include<bits/stdc++.h>
using namespace std;
int num;

// array to store prime numbers
vector <int> is_prime;

// function for sieve of Sundaram
void sieve_of_sundaram()
{
    // sieve of sundaram will give primes smaller than 2+2*n for a given number n
    // we will reduce num to num/2 as it won't effect our answer
	// is_marked array is used to separate numbers of the form i+j+2*i*j from others where 1 <= i <= j
	bool is_marked[num/2 + 100] = {0};

    //logic : 
    // marking all numbers i where 2*i+1 is not prime
	for (int i=1; i<=(sqrt(num)-1)/2; i++)
		for (int j=(i*(i+1))<<1; j<=num/2; j=j+2*i+1)
			is_marked[j] = true;

	is_prime.push_back(2);// as 2 is the first prime number 

	// rest primes are pushed in is_prime vecto, they are of the form 2*i + 1 where is_marked[i] is false.
	for (int i=1; i<=num/2; i++)
		if (is_marked[i] == false)
			is_prime.push_back(2*i + 1);
}

// function to check if a number is Smith number or not
bool is_smith_number(int n)
{
	int initial_n = n;// storing the initial value of n in a variable 

	int sum_of_digits = 0;// to store the sum of digits of prime factores of n
	for (int i = 0; is_prime[i] <= n/2; i++)
	{
		while (n % is_prime[i] == 0)
		{
            //adding the digits of primes[i] to sum_of_digits of primes[i] is a prime factor
			int p = is_prime[i];
			n = n/p;
			while (p > 0)
			{
				sum_of_digits += (p % 10);
				p = p/10;
			}
		}
	}

    // if n is not 1, one prime factor of n still exist and we need to sum its digits too
	if (n != 1 && n != initial_n)
	{
		while (n > 0)
		{
			sum_of_digits = sum_of_digits + n%10;
			n = n/10;
		}
	}

    // after covering all the prime factors of initial n, we add the digits of initial n too
	int sumDigits = 0;
	while (initial_n > 0)
	{
		sumDigits = sumDigits + initial_n % 10;
		initial_n = initial_n/10;
	}

    // we return true only if the sum of digits in prime factors of inital n and sum of digits 
    // of initial n are same
	return (sum_of_digits == sumDigits);
}

// main function
int main()
{
    int n;
    // taking input for number n
    cout<<"Enter the value of n: ";
    cin>>n;
    num=n;
    // calling the function sieve_of_sundaram
    sieve_of_sundaram();
    // printing smith numbers present between 1 and n
    cout << "Smith numbers present between 1 and n: \n";
    for (int i=1; i<=n; i++)
    {
        if (is_smith_number(i))
            cout << i << " ";
    }
	return 0;
}
