#include <iostream>
using namespace std;


int mean(int arr[], int n){
    int m = 0;
    for(int i=0; i<n; i++){
        m = m+arr[i];
    }
    m = m/n;
    return m;
}

int main(){
    int n;
    cout << "How many numbers do you want to enter ?";
    cin >> n;
    cout<<"Enter the numbers";
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int m = mean(arr,n);
    cout<<"The mean of numbers is: "<<m;
}