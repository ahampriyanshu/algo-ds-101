//Following is the C++ implementation of Bitonic Sort.
//Note: This code will yield required output only if the size
// of the array is a power of 2.
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/*The parameter n indicates the sorting direction, ASCENDING
   or DESCENDING; if (a[i] > a[j]) agrees with the direction,
   then a[i] and a[j] are interchanged.*/
void conditionalswap(int a[], int i, int j, int n)
{
    if(n==a[i]>a[j])
            swap(a[i],a[j]);
}


/*It recursively sorts a bitonic sequence in ascending order,
  if n = 1, and in descending order otherwise (means n=0).
  The sequence to be sorted starts at index position l meaning low,
  the parameter c is the number of elements to be sorted.*/
void merge_bitonic(int a[], int l, int c,int n)
{   int i;
    if(c>1)
    {
        int p=c/2;
        for(i=l;i<l+p;i++)
        {
            conditionalswap(a,i,i+p,n);
        }
        merge_bitonic(a,l,p,n);
        merge_bitonic(a,l+p,p,n);

    }
}

/* This function first produces a bitonic sequence by recursively
    sorting its two halves in opposite sorting orders, and then
    calls merge_bitonic to make them in the same order */
void sort_bitonic(int a[], int l, int c, int n )
{
    if(c>1)
    {
        int p=c/2;
        sort_bitonic(a,l,p,1);//sort in ascending order as n=1
        sort_bitonic(a,l+p,p,0);//sort in descending order as n=0
        merge_bitonic(a,l,c,n);//merge whole sequence in ascending order

    }
}

//Call for the bitonic sort function
void sort(int a[],int n,int u)
{
    sort_bitonic(a,0,n,u);
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int u=1;//u=1 means ascending order u=0 means descending.
    sort(a,n,u);

    //Printing of the sorted array
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    return 0;
}
