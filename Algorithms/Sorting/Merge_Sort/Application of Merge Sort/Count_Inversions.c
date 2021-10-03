#include<stdio.h>
#include<stdlib.h>

long long int  merge(long long int a[], long long int start, long long int mid, long long int end)
{
	long long int i=start,j=mid,k=0;
	long long int temp[end-start+1];
	long long int count=0,len=mid;
 
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
 
	for(long long int i=start,k=0; i<=end; i++,k++)
	{
		a[i]=temp[k];
	}
 
	return count;
}
 
long long int merge_sort(long long int a[],long long int start,long long int end)
{
	//Base Case: num of elements=0 or 1;
	//long long int count=0;
 
	if(start<end)
	{
 
	   long long int mid=(start+end)/2;
 
	   long long int countLeft=merge_sort(a,start,mid);
	   long long int countRight=merge_sort(a,mid+1,end);
	   long long int count_during_Merge=merge(a,start,mid+1,end);
 
	   long long int ans=countLeft+countRight+count_during_Merge;
 
	   return ans;
    }
 
    return 0;
 
}


int main()
{
	long long int n;
	scanf("%lld",&n);
 
	long long int a[n];
	for(int i=0; i<n; i++)
        scanf("%lld",&a[i]);
 
	long long int ans=merge_sort(a,0,n-1);
	printf("%lld\n",ans);

    return 0;
} 