#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[],int n)
{
    for(int i = 0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            if(arr[i] < arr[j])
            {
                swap(arr[i],arr[j]);
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++)cin>>arr[i];
    bubble_sort(arr,n);
    

}