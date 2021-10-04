
// creating function with default starting and ending index
function BinarySearch(arr,val,start=0,end=arr.length-1){

    // intializing loop to interate through array
    while(start<=end){   //condition for unexistence of element

        //finding middle index
        let mid=Math.floor((start+end)/2)

        if(arr[mid]===val){   //comparing value with requires value
            return mid;
        }
        
        if(val<arr[mid]){    //if value is small then change end to mid-1
            end=mid-1;
        }

        else{
            start=mid+1;     //if value is large then change start to mid+1
        }

    }
    return -1;               //no elment found then return -1
}




let l=[2,3,4,5,6,7,8,10,45,67,100]


// using function with default start and end
console.log(BinarySearch(l,6,0,9))

// looping through whole array
console.log(BinarySearch(l,-34))




////////// we can use node in terminal to print the result////////////