function quickSort(array) { // assumes an array of ints
    if (array.length <= 1) {
       return array;
       } else {
            var left = [], right = [], nextArray = [], length = array.length;
            var pivot = array.splice(Math.floor(Math.random()*array.length),1); // get random pivot
            length--;
             for (var i = 0; i < length; i++) {
                if (array[i] <= pivot) {    // compare left/right of pivot
                   left.push(array[i]);      
             } else {
                     right.push(array[i]);
           }
         }
       return nextArray.concat(quickSort(left), pivot, quickSort(right));                                                                          //returned untill sorting occurs
    }
 }

// use node to run, uncomment below to test
//  var array = [9, 0, 2, 7, -2, 6, 1 ];
//  console.log("Given array --> " + array);
//  var arrayAfterQuickSort = quickSort(array);
//  console.log("Array after QuickSort: " + arrayAfterQuickSort);