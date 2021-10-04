//Insertoion sort presumes the the array till curr index is sorted and places the curr element in the sort part at its correct place
#include<iostream>
using namespace std;
void insertionsort(int arr[],int len){
    for(int curr=1;curr<len;curr++){            //starting curr from 1 because we assumes that 0th element is already sorted
        int key=arr[curr];
        int pos=curr-1;                         //last element of sorted part of the array 
        while(pos>=0 and arr[pos]>key){         //while end if array finishes or we encounter element smaller than curr
            arr[pos+1]=arr[pos];                //shifting element at pos by 1 if its bigger than element at curr
            pos--;
        }
        arr[pos+1]=key;                         //pos is the index of element smaller than curr therefore we place key at pos+1
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
    insertionsort(arr,len);
    cout<<"Sorted array: ";
    for(int idx=0;idx<len;idx++){
        cout<<arr[idx]<<" ";
    }
    return 0;
}