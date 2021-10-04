#include <bits/stdc++.h>
using namespace std;
//swap of elements
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
//rearrange elements high and low
void rearrange(int arr[], int n)
{
    for (int i = 1; i < n; i += 2)
    {
        if (arr[i - 1] > arr[i]) {
            swap(arr, i - 1, i);
        }
        if (i + 1 < n && arr[i + 1] > arr[i]) {
            swap(arr, i + 1, i);
        }
    }
}
 
int main()
{
    //enter array by user
    int n;
    cout<<"Enter the number of elements:"<<endl;
    cin>>n;
    
    int arr[n];
    
     cout<<"Enter array elements:"<<endl;
     for(int i = 0; i < n;  i++){
        cin>>arr[i];
     }
 
    rearrange(arr, n);
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<endl;
    }
 
    return 0;
}
