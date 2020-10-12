#include<bits/stdc++.h> 
using namespace std;

int rotatedSearch(vector<int> &A, int B) {

    //low and high are the indices between which we search-
    int low=0; 
    int high=A.size()-1;
    
    //finding the pivot of rotation-
    for(int i=0; i<A.size()-1; i++){
        if(A[i]>A[i+1]){                
            
            if(B>=A[0])
                high=i;                //search only in the left of pivot
            
            else if(B<=A[A.size()-1])
                low=i+1;              //search only in the right of pivot
            
            break;    
        }
    }
    
    //implementing Binary Search-
    while(high>=low){                  
        int mid=low+(high-low)/2;
        if(A[mid]==B) return mid;     //B is found
        else if(A[mid]>B) high=mid-1;
        else if(A[mid]<B) low=mid+1;
    }
    return -1;                       //B is not found
}
