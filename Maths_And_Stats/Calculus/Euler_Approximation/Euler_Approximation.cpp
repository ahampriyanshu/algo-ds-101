/* CPP  Program to find approximation 
   of a ordinary differential equation 
   using euler method.*/
#include <iostream> 
using namespace std; 
  
// Consider a differential equation 
// dy/dx=(x + y + xy) 
float func(float x, float y) 
{ 
    return (x + y + x * y); 
} 
  
// Function for Euler formula 
void euler(float x0, float y, float h, float x) 
{ 
    float temp = -0; 
  
    // Iterating till the point at which we 
    // need approximation 
    while (x0 < x) { 
        temp = y; 
        y = y + h * func(x0, y); 
        x0 = x0 + h; 
    } 
  
    // Printing approximation 
    cout << "Approximate solution at x = "
         << x << "  is  " << y << endl; 
} 
  
// Driver program 
int main() 
{ 
    // Initial Values 
    float x0; 
    float y0; 
    float h;
    cin>>x0>>y0>>h;
  
    // Value of x at which we need approximation 
    float x ;
    cin>>x;
  
    euler(x0, y0, h, x); 
    return 0; 
} 
