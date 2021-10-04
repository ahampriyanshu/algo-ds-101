#include<bits/stdc++.h>  
using namespace std;  
  

void flip(int arr[], int i)  
{  
    int temp, start = 0;  
    while (start < i)  
    {  
        temp = arr[start];  
        arr[start] = arr[i];  
        arr[i] = temp;  
        start++;  
        i--;  
    }  
}  
  
int findMax(int arr[], int n)  
{  
    int mi, i;  
    for (mi = 0, i = 0; i < n; ++i)  
    {
        if (arr[i] > arr[mi])  
                mi = i;  
    }
    return mi;  
}  
  
void pancakeSort(int *arr, int n)  
{  
    for (int curr_size = n; curr_size > 1; --curr_size)  
    {  
        int mi = findMax(arr, curr_size);  
  
        if (mi != curr_size-1)  
        {  
            flip(arr, mi);  
            flip(arr, curr_size-1);  
        }  
    }  
}  
void printArray(int arr[], int n)  
{  
    for (int i = 0; i < n; ++i)  
        cout<< arr[i]<<" ";  
    cout << "\n";   
}  
  

int main()  
{  
    int N,i,j;
    cout << "Enter Size of Array :- " << "\n";
    cin >> N;
    int A[N];
    cout << "Enter Array Elements:- " << "\n";
    for(i = 0 ; i < N;i++)
        cin >> A[i];
    
    pancakeSort(A, N);  
    cout<<"Sorted Array "<<"\n";  
    printArray(A, N);  
  
    return 0;  
}  