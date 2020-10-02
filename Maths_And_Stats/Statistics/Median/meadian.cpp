#include<iostream>
#include<algorithm>
using namespace std;
#define max 50
float median(int b[],int n)
{
    sort(b,b+n);
    float c;
    if(n%2!=0)
    {
        c=b[n/2];
        return c;
    }
    else
    {
        c=(b[(n-1)/2]+b[n/2])/2.0;
        return c;
    }
}
int main()
{
    int a[max];
    int n;
    cout<<"Enter the total number of elements"<<endl;
    cin>>n;
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Elements are: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"Median= "<<median(a,n);
    return 0;
}
