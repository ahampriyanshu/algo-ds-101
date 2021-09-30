function rotatedSearch(arr, target) {
    let left = 0 ,right = arr.length-1;
    // First part : Find the pivot that is point from array is rotated
    // For example pivot(index) in 5 6 7 1 2 is 2
    while(left < right){
        let mid = left + Math.floor((right-left)/2) ;
        if(arr[right] < arr[mid]){
            left = mid+1;
        }else{
            right = mid;
        }
    }   

    let pivot = left;
    
    // reassign left and right for next binary search
    left = 0 ; 
    right = arr.length-1;

    // select the part of array where the target lie.
    // we have two sorted part of array divided by pivot
    if(target <= arr[right] && arr[pivot]<=target ){
        left = pivot;
    }else{
        right = pivot;
    }

    // binary search on the part containing target
    while(left<=right){
        let mid = left + Math.floor((right-left)/2);
        if(arr[mid] == target){
            return mid;
        }
        if(arr[mid]<target){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return -1;
};

// testing
var testArray = [] ;
var size = prompt('Enter the size of the array\n') ;

for(var i = 0 ; i < size ; i++){
	testArray[i] = prompt('Enter next element ');
}
var target = prompt('Enter target number to be searched\n');

console.log(rotatedSearch(testArray,target));
// edge cases
// console.log(rotatedSearch([8,7,6,5,2,1],6));
// console.log(rotatedSearch([1,2,3,4,5,6],6));
