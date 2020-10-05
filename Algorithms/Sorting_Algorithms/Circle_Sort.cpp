#include<bits/stdc++.h> 
using namespace std; 
bool circleSortRec(int a[], int low, int high) 
{ 
    bool swapped = false; 
    if (low == high) 
        return false;
    int lo = low, hi = high; 
    while (lo < hi) 
    {  
        if (a[lo] > a[hi]) 
        { 
            swap(a[lo], a[hi]); 
            swapped = true; 
        } 
        lo++; 
        hi--; 
    } 
    if (lo == hi) 
        if (a[lo] > a[hi + 1]) 
        { 
            swap(a[low], a[hi+1]); 
            swapped = true; 
        } 
    int mid = (high - low) / 2; 
    bool firstHalf = circleSortRec(a, low, low+mid); 
    bool secondHalf = circleSortRec(a, low+mid+1, high); 
    return swapped || firstHalf || secondHalf; 
} 
void circleSort(int a[], int n) 
{ 
    while (circleSortRec(a, 0, n-1)) 
    { 
       ; 
    } 
} 
int main() 
{ 
    int a[] = {-1, 5, 15, 2, 12, 44, 60, 8}; 
    int n = sizeof(a)/sizeof(a[0]); 
    cout<<"\nUnsorted : "; 
    for (int i=0; i<n; i++) 
        cout << a[i] << " "; 
    circleSort(a, n); 
    cout<<"\nSorted : "; 
    for (int i=0; i<n; i++) 
        cout << a[i] << " "; 
    return 0;
}
