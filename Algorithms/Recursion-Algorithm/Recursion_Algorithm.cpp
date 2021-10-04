
#include <bits/stdc++.h> 
using namespace std; 

void printFun(int test) 
{ 
	if (test < 1) 
		return; 
	else { 
		cout << test << " "; 
		printFun(test - 1); // statement 2 
		cout << test << " "; 
		return; 
	} 
} 

int main() 
{ 
	int test = 3; 
	printFun(test); 
} 
