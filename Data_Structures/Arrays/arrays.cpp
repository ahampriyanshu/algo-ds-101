// C++ Array example

#include <iostream>
using namespace std;

/*
	* An array is a data-structure used to store values of same data-type contiguously.
	* We will see this with an example.
	* Suppose we have to input some numbers from user and display their sum but we don't know definitely how many numbers the user will input.
	* In this case, we can use the array data-structure to solve our problem.
*/

int main ()
{
  // first we display a message to user asking how many numbers he wants to input.
  cout<< "How many numbers you want to input? : ";
  
  // then we input and store number of input in variable 'n'
  
  int n;
  cin >> n;
  
  // now, we declare an array 'arr' of size 'n' to store those n numbers
  
  int arr[n];
  
  // now, we input n numbers using a for loop
  
  for(int i=0; i<n; i++)
  {
	cin >> arr[i];
  }
  
  // now, we decalare a variable 'sum' to store sum of these numbers 
  
  int sum = 0;
  
  // now, we add all the numbers in the variable 'sum'
  
  for(int j=0; j<n; j++)
  {
	sum = sum + arr[j];
  }
  
  // finally, we display the sum to the user
  
  cout << sum;
  
  return 0;
}