/**
*This class contians information to sort a number array using insertion sort.
*
*@class InsertionSort
*@constructor
**/
export class InsertionSort{


    constructor(){
    
    }
    
    /**
    *This method contains logic to sort a partially sorted array in O(n) time.
    *@method sort
    *@param {Array} arr The array to be sorted.
    *@return {Array} arr THe sorted array.
    **/
    public sort(arr:number[]):number[]{
    
      if(arr!==undefined){
       for(let i:number = 0; i< arr.length; i++){
    
        let j = i-1;
        let key = arr[i];
    
        while(j>-1 && arr[j]>key){
          arr[j+1] = arr[j];
          j--; 
        }
    
        arr[j+1] = key;
    
       }
       return arr;
      }
    
    }
    
    }