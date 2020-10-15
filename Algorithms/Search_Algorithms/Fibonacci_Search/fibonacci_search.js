//JavaScript program for Fibonacci Search 

 /* 
  * Find an element in the given sorted array with the help of Fibonacci series
    in O(log N) time complexity. 
  * Let the length of given array be n [0...n-1] and the element to be searched be x.
  * Find the smallest Fibonacci number greater than or equal to n.
  * source: https://iq.opengenus.org/fibonacci-search/
  */

  //length/size: n , element to search: x
  function fibonacciSearch(n, arr, x){
    //Let this number be fb(M) [m’th Fibonacci number].
    //Let the two Fibonacci numbers preceding it be fb(M-1) [(m-1)’th Fibonacci number] 
    let fbMm2 = 0;
    let fbMm1 = 1;
    let fbM = fbMm1 + fbMm2;
    let offset = -1;

    //Find the smallest Fibonacci number greater than or equal to n
    while(fbM < n){
        fbMm2 = fbMm1;
        fbMm1 = fbM;
        fbM = fbMm1 + fbMm2;
    }


    //While the array has elements to be checked:
    //-> Compare x with the last element of the range covered by fb(M-2)
    //-> If x matches, return index value
    //-> Else if x is less than the element, move the third Fibonacci variable two Fibonacci down,

     let i = 0;

     while(fbM > 1){
        i = Math.min(offset + fbMm2, n - 1);

        if(arr[i] < x){
            fbM  = fbMm1;
            fbMm1 = fbMm2;
            fbMm2 = fbM - fbMm1;
            offset = i;
        } else if(arr[i] > x){
            fbM  = fbMm2;
            fbMm1 = fbMm1 - fbMm2;
            fbMm2 = fbM - fbMm1;
        } else
            return i;
     }

    //comparing the last element
    if(fbMm1 && arr[offset + 1] == x)
        return offset + 1;

    return -1;
}

let arr = [10, 15, 30, 60, 90, 100, 120];
let n = 7;
let x = 92;
console.log(fibonacciSearch(n, arr, x)); 