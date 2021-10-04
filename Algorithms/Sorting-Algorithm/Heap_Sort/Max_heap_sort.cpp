/*
	Author : codewithrathi
*/

/*Problem Statement : 
Implement Heap sort to sort given set of values using max heap.*/

#include <bits/stdc++.h> 
using namespace std; 


void downadj(int heap[],int i,int n) //down adjust 
{ 
   int l=2*i,r=2*i+1; 
   int max=i; 
   if(l<n && heap[l]>heap[max]) 
   { 
       max=l; 
   } 
   if(r<n && heap[r]>heap[max]) 
   { 
       max=r; 
   } 
   if(max!=i) 
   { 
       swap(heap[i],heap[max]); 
       downadj(heap,max,n); 
   } 
}
 
void show(int arr[],int n,int x) //print array 
{ 
   if(x==1) 
   { 
       cout<<"ELEMENTS IN MAX HEAP IS AS :\n\n"; 
   } 
   else 
   { 
       cout<<"SORTED ARRAY IS :\n\n"; 
   } 

   for(int i=1;i<=n;i++) 
   { 
       cout<<"At position : "<<i<<" \t------> \t"; 
       cout<<arr[i]<<"\n"; 
   } 

   cout<<endl; 
} 

void upadj(int heap[],int i) //up adjust 
{ 
   while(i>1 && heap[i]>heap[i/2]) 
   { 
       swap(heap[i],heap[i/2]); 
       i=i/2; 
   } 
} 

void insert(int a[],int x) //construct max heap (Step 1) 
{ 
   int heap[x+1],n,i; 
   heap[0]=0,i=1; 
   while(i<(x+1)) 
   { 
       n=heap[0]; 
       heap[n+1]=a[i]; 
       heap[0]=n+1; 
       upadj(heap,n+1); 
       i++; 
   } 
   show(heap,heap[0],1); 
   n=heap[0]; 
   while(n>1) 
   { 
 swap(heap[1],heap[n]); //(step 2) 
 n--; //(step 3) 
 downadj(heap,1,n); //(step 4) 
} 
show(heap,heap[0],2); 
} 

int main() 
{ 
   int n; 
   cout<<"****************************************************\n"; 
   cout<<"IMPLEMENTATION OF HEAP SORT TO SORT USING MAX HEAP \n"; 
   cout<<"****************************************************\n"; 
   cout<<"\nEnter the Number of elements in Array ?\n"; 
   cin>>n; 
   int a[n+1]; 
   a[0]=n; 
   for(int i=1;i<n+1;i++) 
   { 
       cout<<"Enter the element "<<i<<endl; 
       cin>>a[i]; 
   } 
   insert(a,n); 
   cout<<"\nOPERATION COMPLETED!! THANK YOU"; 
   return 0; 
} 

/*
-----------------------------------------------------------------------------------------------------------------------------
OUTPUT :

****************************************************
IMPLEMENTATION OF HEAP SORT TO SORT USING MAX HEAP 
****************************************************

Enter the Number of elements in Array ?
11
Enter the element 1
1
Enter the element 2
3
Enter the element 3
5
Enter the element 4
4
Enter the element 5
6
Enter the element 6
13
Enter the element 7
10
Enter the element 8
9
Enter the element 9
8
Enter the element 10
15
Enter the element 11
17
ELEMENTS IN MAX HEAP IS AS :

At position : 1         ------>         17
At position : 2         ------>         15
At position : 3         ------>         10
At position : 4         ------>         8
At position : 5         ------>         13
At position : 6         ------>         3
At position : 7         ------>         6
At position : 8         ------>         1
At position : 9         ------>         5
At position : 10        ------>         4
At position : 11        ------>         9

SORTED ARRAY IS :

At position : 1         ------>         1
At position : 2         ------>         3
At position : 3         ------>         4
At position : 4         ------>         5
At position : 5         ------>         6
At position : 6         ------>         8
At position : 7         ------>         9
At position : 8         ------>         10
At position : 9         ------>         13
At position : 10        ------>         15
At position : 11        ------>         17


OPERATION COMPLETED!! THANK YOU

...Program finished with exit code 0
Press ENTER to exit console.
*/