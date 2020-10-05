// C++ Program for counting sort 
// it is beneficial for counting the frequency of characters
//https://www.hackerearth.com/practice/algorithms/sorting/counting-sort/practice-problems/algorithm/counting-sort-problem/
//https://www.hackerearth.com/problem/algorithm/counting-sort/


# include <bits/stdc++.h>
using namespace std;
// counting sort sorting algorithm
void CountingSort(int input_array[],int s, int r)
{
	int output_array[s];
	int count_array[r];
	
	
	for(int i=0;i<r;i++)
		count_array[i]=0;
		
	
	for(int i=0;i<s;i++)
		count_array[input_array[i]]++;
	
	for(int i=1;i<r;i++)
		count_array[i]=count_array[i]+count_array[i-1];
	
	
	for(int i=0;i<s;i++)
		output_array[--count_array[input_array[i]]] = input_array[i];
	

	for(int i=0;i<s;i++)
		input_array[i]=output_array[i];
}

int main()
{
	int size=0;
	int range = 10;
	cin>>size;
	int array[size];
	for(int i=0;i<size;i++)
	{
		cin>>array[i];
	}
	CountingSort(array,size,range);  // counting sort called
	for(int i=0;i<size;i++)
	{
		cout<<myarray[i]<<" ";
	}
	return 0;
}
