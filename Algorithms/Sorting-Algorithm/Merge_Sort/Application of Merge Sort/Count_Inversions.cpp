#include<bits/stdc++.h>
using namespace std;

long long merge(long long a[], long long start, long long mid, long long end)
{
	long long i=start,j=mid,k=0;
	long long temp[end-start+1];
	long long count=0,len=mid;
 
	while(i<mid&&j<=end)
	{
		if(a[i]<=a[j])
		{
			temp[k]=a[i];
			k++;
			i++;
		}
		else
		{
			temp[k]=a[j];
			count+=len-i;
			k++;
			j++;
		}
	}
 
	while(i<mid)
	{
		temp[k]=a[i];
		k++;
		i++;
	}
 
	while(j<=end)
	{
		temp[k]=a[j];
		k++;
		j++;
	}
 
	for(long long i=start,k=0; i<=end; i++,k++)
	{
		a[i]=temp[k];
	}
 
	return count;
}
 
long long merge_sort(long long a[],long long start,long long end)
{
	//Base Case: num of elements=0 or 1;
	//long long count=0;
 
	if(start<end)
	{
 
	   long long mid=(start+end)/2;
 
	   long long countLeft=merge_sort(a,start,mid);
	   long long countRight=merge_sort(a,mid+1,end);
	   long long count_during_Merge=merge(a,start,mid+1,end);
 
	   long long ans=countLeft+countRight+count_during_Merge;
 
	   return ans;
    }
 
    return 0;
 
}


int main()
{
	long long n;
	cin>>n;
 
	long long a[n];
	for(int i=0; i<n; i++)
        cin>>a[i];
 
	long long ans=merge_sort(a,0,n-1);
	cout<<ans<<endl;

    return 0;
} 