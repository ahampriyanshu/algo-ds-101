function swap(arr, first_Index, second_Index) {
  var temp = arr[first_Index];
  arr[first_Index] = arr[second_Index];
  arr[second_Index] = temp;
}

function bubbleSort(arr) {
  if (arr.length < 1) return 0;
  var arrayLength = arr.length;
  for (let i = 0; i < arrayLength; i++) {
    for (let j = 0, end = arrayLength - i; j < end; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr, j, j + 1);
      }
    }
  }
  return arr;
}
console.log(bubbleSort([3, 0, 2, 5, -1, 4, 1]));
