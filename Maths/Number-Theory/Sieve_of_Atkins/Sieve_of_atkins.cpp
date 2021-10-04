#include<bits/stdc++.h>
using namespace std;

#define ll long long int

vector<ll> SieveOfAtkin(long long int limit) 
{ 
    vector<ll> primes;
    primes.push_back(2);
    primes.push_back(3); 
    bool sieve[limit]; 
    for (long long int i = 0; i < limit; i++) 
        sieve[i] = false; 
    for (long long int x = 1; x * x < limit; x++) { 
        for (long long int y = 1; y * y < limit; y++) { 
            long long int n = (4 * x * x) + (y * y); 
            if (n <= limit && (n % 12 == 1 || n % 12 == 5)) 
                sieve[n] ^= true; 
  
            n = (3 * x * x) + (y * y); 
            if (n <= limit && n % 12 == 7) 
                sieve[n] ^= true; 
  
            n = (3 * x * x) - (y * y); 
            if (x > y && n <= limit && n % 12 == 11) 
                sieve[n] ^= true; 
        } 
    } 
  
    // Mark all multiples of squares as non-prime 
    for (long long int r = 5; r * r < limit; r++) { 
        if (sieve[r]) { 
            for (long long int i = r * r; i < limit; i += r * r) 
                sieve[i] = false; 
        } 
    } 
   
    for (int a = 5; a < limit; a++) 
        if (sieve[a]) 
            primes.push_back(a);
    return primes; 
}
int main()
{
    cout<<"Primes from 1 to 100 are: ";
    vector<ll> primes = SieveOfAtkin(100);
    for(auto ele:primes)
        cout<<ele<<" ";
}