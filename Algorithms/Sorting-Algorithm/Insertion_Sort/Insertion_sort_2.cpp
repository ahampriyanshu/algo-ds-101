#include<iostream>
using namespace std;

void Insertion_sort(int a[],int n){

  for(int i = 1; i <= n - 1; i++){
        int e = a[i];
        int j = i -1;
    while(j >= 0 and a[j]> e){
        a[j+1] = a[j];
        j = j - 1;
    }
    a[j+1] = e;

  }
}
int main(){
    int n;
    cin>>n;

    int arr[1000];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    Insertion_sort(arr,n);
    for(int i = 0; i < n; i++){
        cout<<arr[i];
    }
}
