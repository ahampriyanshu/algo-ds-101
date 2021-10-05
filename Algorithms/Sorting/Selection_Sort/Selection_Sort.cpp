//Selection sort, sort the array by swapping the curr element with the smallest element from indexes curr+1 to len-1
#include<iostream>
using namespace std;
void selection_sort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int min_index=i;
        for(int j=i+1;j<=n-1;j++){
            if(a[j]<a[min_index]){
                min_index=j;
            }
        }
      swap(a[i],a[min_index]);
    }
}
int main(){
    int n;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    selection_sort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<",";
    }
    return 0;
}
