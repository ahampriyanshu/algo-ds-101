#include<iostream>

int Kadane(int arr[], int size)
{
  int max_so_far=0;
  int max_ending_here=0;

  for(int i=0; i<size; i++)
  {
    max_ending_here= max_ending_here + arr[i];
    if(max_so_far<max_ending_here)
      max_so_far= max_ending_here;
    if(max_ending_here<0)
      max_ending_here=0;
  }

  return max_so_far;
}
