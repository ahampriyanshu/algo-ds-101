/*Method:-
Sum of square of first N natural number = (N * (N + 1) * (2*N + 1)) / 6;
 exmple:-
  For N =4, Sum = (4 * (4 + 1) * (2 * 4 + 1)) /6;
                  = (4*5*9)/6
                  =180/6
                  = 30

  For N =5, Sum = (5 * (5 + 1) * (2 * 5 + 1)) /6;
                  = (5*6*11)/6
                  = 55  */            

// CPP Program to find sum 
// of square of first n 
// natural numbers 
#include <bits/stdc++.h> 
using namespace std; 
  
// Return the sum of square of 
// first n natural numbers 
int squaresum(int n) 
{ 
    return (n * (n + 1) * (2 * n + 1)) / 6; 
} 
  
// Driven Program 
int main() 
{ 
    int n = 4; 
    cout << squaresum(n) << endl; 
    return 0; 
} 

/*Output:

30 */