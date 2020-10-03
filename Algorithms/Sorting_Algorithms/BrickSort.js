/* A JavaScript program to perform Brick Sort */

// A utility function to sort the array values
function swap(arr, first_Index, second_Index) {
  var temp = arr[first_Index];
  arr[first_Index] = arr[second_Index];
  arr[second_Index] = temp;
}

// A function to perform the Brick Sort
function brickSort(arr) {
  if (arr.length < 1) return 0;
  var arrayLength = arr.length;
  var isSorted = false;
  while(!isSorted){
  isSorted = true;
  
  // Perform Bubble sort on odd indexed element
  for (let i=1; i<=arrayLength-2; i=i+2) 
    { 
      if (arr[i] > arr[i+1]) 
        { 
          swap(arr,i,i+1);
          isSorted = false; 
        } 
     }
     
  // Perform Bubble sort on even indexed element
  for (let i=0; i<=arrayLength-2; i=i+2) 
    { 
       if (arr[i] > arr[i+1]) 
         { 
           swap(arr,i,i+1);         
           isSorted = false; 
         } 
     }
   }
   return arr;
}
console.log(brickSort([3, 0, 2, 5, -1, 4, 1]));
