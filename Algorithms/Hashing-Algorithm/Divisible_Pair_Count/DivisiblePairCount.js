
let DivisiblePairCount = (arr, n) => {
    let count = 0; // set count = 0
    for (let i = 0; i < n; i++) // iterate through the array from i = 0
    {
        for (let j = i + 1; j < n; j++) // iterate through the array start from the element next to arr[i]
        {
            if (
                (arr[i] % arr[j] == 0)  
                || (arr[j] % arr[i] == 0)
                )
                {
                    count++; // increase count by 1, if it is under the condition
                }
        }
    }
    return count;    
}
let arr = [2,3,5,8,9];
console.log(DivisiblePairCount(arr, arr.length));