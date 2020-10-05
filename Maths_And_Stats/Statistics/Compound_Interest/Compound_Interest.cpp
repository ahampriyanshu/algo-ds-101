/*Compound Interest*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
    double principle, rate, timeSpan;

    cout << "Enter the principle amount" << endl;
    cin >> principle;

    cout << "Enter the compound rate of interest" << endl;
    cin >> rate;
    
    cout << "Enter the time span or number of times the amount gets compounded" << endl;
    cin >> timeSpan;
  
    /* Calculate compound interest */
    /*Formula to calculate final amount after applying compound interest is given by:
	FinalAmount = (principle)*((1 + (rate)/100)^(timeSpan))*/
    double FinalAmount = principle * (pow((1 + rate / 100), timeSpan)); 
  
    cout << "Final amount after applying Compound interest = " << FinalAmount; 
  
    return 0; 
} 