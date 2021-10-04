       // binary search

 #include<bits/stdc++.h>
 using namespace std ;

 int binarySearch(int arr[], int l,int r,int x)
 {
      
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, mid + 1, r, x); 
    } 
    // We reach here when element is not 
    // present in array 
    return -1; 
 }

int main()
{
    int n ,i ,l , h , key ;
    cin >> n ;
    int arr[n] ;
    for(i=0;i<n;i++)
    {
        cin >> arr[i] ;
    }
        
    l=0 ;
    h=n-1 ;
     
        cout   << "enter the key you want to search : ";
        cin >> key ;
    //     while(h>=l)
    // {
    //     mid=(l+h)/2 ;

    //     if(arr[mid]==key)
    //     {
    //         cout  << "found\n" ;
    //         return 0 ;
    //     }
    //     else if (key>mid)
    //     {
    //         l=mid+1 ;
    //     }
    //     else if (key<mid)
    //     {
    //         h=mid-1 ;
    //     }  
       
    // }
        int value = binarySearch(arr, l, h, key);
        if(value)
            {
                cout << "found\n";
                return 0;
            }
        cout << "element not found \n"
             << endl;

        return 0;
 }