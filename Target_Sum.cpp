
#include <iostream>
using namespace std;

int SubsetSum(int arr[],int n, int sum)
{
    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
             if(i==0)
               t[i][j]=0;
             if(j==0)
               t[i][j]=1;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
             if(arr[i-1]<=j)  
                t[i][j]=t[i-1][j-arr[i-1]] + t[i-1][j];
            else
               t[i][j]=t[i-1][j]; 
        }
    }
 return t[n][sum];
}

int main()
{
	    int n;
	    cout<<"array size : ";
	    cin>>n;
	    int arr[n];
	    cout<<"array element :\n";
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
        int sum;
        cout<<"sum :";
        cin>>sum;
      cout<<"\ncount : "<<SubsetSum(arr,n,sum);
	 /* if(EqualSumPartition(arr,n))
	     cout<<"YES"<<endl;
	   else
	     cout<<"Not Possible"<<endl;*/
	return 0;
}
