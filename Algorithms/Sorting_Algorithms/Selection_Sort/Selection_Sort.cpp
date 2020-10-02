//Selection sort, sort the array by swapping the curr element with the smallest element from indexes curr+1 to len-1
#include<iostream>
using namespace std;
void selectionsort(int arr[],int len){
    for(int curr=0;curr<len;curr++){
        int min_idx=curr;
        for(int itr=curr+1;itr<len;itr++){
            if(arr[itr]<arr[min_idx]){
                min_idx=itr;
            }
        }
        swap(arr[curr],arr[min_idx]);
    }
}
int main(){
    int len;
    cout<<"Enter the number of elements to sort: ";
    cin>>len;
    int arr[len]={0};
    cout<<"Enter the elements to sort: \n";
    for(int idx=0;idx<len;idx++){
        cin>>arr[idx];
    }
    selectionsort(arr,len);
    cout<<"Sorted array: ";
    for(int idx=0;idx<len;idx++){
        cout<<arr[idx]<<" ";
    }
    return 0;
}