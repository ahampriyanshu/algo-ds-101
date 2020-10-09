// Calculating Prime factors of a given number

#include <bits/stdc++.h> 
using namespace std; 
  
// Function to find prime factors of a number num
void PrimeFactorisation(int num)  
{  
    // first checking for 2
    while (num % 2 == 0)  
    {  
        cout << 2 << " ";  
        num = num / 2;  
    }  
  
    // now finding rest of prime factors
    for (int i = 3; i <= sqrt(num); i += 2)  
    {  
        while (num % i == 0)  
        {  
            cout << i << " ";  
            num = num / i;  
        }  
    }  
  
    // If num != 1 then it itself is a prime number
    if (num > 2)  
        cout << num << " ";  
}  
 
// main function
int main()  
{  
    // taking input
    int num;
    cin >> num;
    PrimeFactorisation(num);  
    
    return 0;  
}