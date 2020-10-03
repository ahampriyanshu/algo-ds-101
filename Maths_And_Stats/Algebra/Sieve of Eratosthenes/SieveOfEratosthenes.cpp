#include <bits/stdc++.h> 
using namespace std; 
#define mp make_pair
#define pb push_back
#define f first
#define s second

void Sieve(int n) 
{ 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    int c = 0;
  
    for (int p=2; p<=n; p++) 
    {
        if (prime[p])
            c++;
    }

    cout << "Prime Numbers <= n:- " << c << endl;
}
int main() 
{ 
    int N;
    cout << "Enter N :-" << endl;
    cin >> N;
    Sieve(N);
    return 0; 
} 