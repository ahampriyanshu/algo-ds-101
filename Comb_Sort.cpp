include<iostream>
#include<algorithm>
using namespace std;
void display(int *array, int size){
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void combSort(int *array, int size){
   int gap = size; //initialize gap size with size of array
   bool flag = true;
   while(gap != 1 || flag == true){
      gap = (gap*10)/13; //minimize gap by shrink factor
      if(gap<1)
         gap = 1;
      flag = false;
      for(int i = 0; i<size-gap; i++){ //compare elements with gap
         if(array[i] > array[i+gap]){
            swap(array[i], array[i+gap]);
            flag = true;
         }
      }
   }
}
int main(){
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n]; //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++){
      cin >> arr[i];
   }
   cout << "Array before Sorting: ";
   display(arr, n);
   combSort(arr, n);
   cout << "Array after Sorting: ";
   display(arr, n);
}
