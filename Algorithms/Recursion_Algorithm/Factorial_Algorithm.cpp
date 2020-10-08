#include<iostream>  
  
using namespace std; 
     
int main()    // main function: the execution of the program starts from here
{    
int factorial(int);  // function prototype
int f,value;    
cout<<"Enter any number: ";    
cin>>value;    
f=factorial(value);    
cout<<"Factorial of "<<value<<" is "<<f<<endl;    
return 0;    
}    
int factorial(int n)  // funtion definition  
{    
if(n<0)    
return(-1); /*Wrong value*/      
if(n==0)    
return(1);  /*Terminating condition*/    
else    
{    
return(n*factorial(n-1));        
}    
}  
