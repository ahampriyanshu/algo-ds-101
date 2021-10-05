function swap(arr, i, j)
{
    var temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
 
// Function to rearrange the array such that every second element
// of the array is greater than its left and right elements
function rearrangeArray(arr, n)
{

    for (let i = 1; i < n; i += 2)
    {
        // if the previous element is greater than the current element,
        // swap the elements
        if (arr[i - 1] > arr[i]) {
            swap(arr, i - 1, i);
        }
 
        // if the next element is greater than the current element,
        // swap the elements
        if (i + 1 < n && arr[i + 1] > arr[i]) {
            swap(arr, i + 1, i);
        }
    }
}

const arr = [ 1, 2, 3, 4, 5, 6, 7 ];
const n = arr.length;

rearrangeArray(arr, n);

// print output array
for (let i = 0; i < n; i++) {
    console.log(arr[i]);
}

/* 
    Output:

            1
            3
            2
            5
            4
            7
            6

*/
