#include<iostream>
#include "include/functions.h"
using namespace std;

int main()
{
  int size;
  cout<<"Enter the size of the array: ";
  cin>>size;

  int arr[size];

  cout<<"Enter array elements"<<endl;
  for(int i=0; i<size; i++)
  {
    cout<<"enter "<<i<<"th element: ";
    cin>>arr[i];
  }

  cout<<"The largest contiguous subsequence sum for the given array is:"<<Kadane(arr,size)<<endl;
}

