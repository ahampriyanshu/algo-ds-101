function BinarySearch(arr,val){
    let start=0;
    let end=arr.length-1;
    while(start<=end){
        let mid=Math.floor((start+end)/2)
        if(arr[mid]===val){
            return mid;
        }
        if(val<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return -1;
}

let l=[2,3,4,5,6,7,8,10,45,67,100]
console.log(BinarySearch(l,45))