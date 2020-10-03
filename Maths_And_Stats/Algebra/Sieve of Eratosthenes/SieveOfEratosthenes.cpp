#include <bits/stdc++.h> 
using namespace std; 
#define mp make_pair
#define pb push_back
#define f first
#define s second

void Sieve(int n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    int c = 0;
    // Counting all prime numbers <= n; 
    for (int p=2; p<=n; p++) 
    {
        if (prime[p])
            c++;
    }

    cout << "Prime Count :- " << c << "\n";
} 
// Driver code 
int main() 
{ 
    int N;
    cout << "Enter N :-" << "\n";
    cin >> N;
    Sieve(N);
    return 0; 
} 