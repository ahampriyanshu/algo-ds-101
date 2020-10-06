function targetSum(arr, target) {
  return countSub(arr, arr.length, 0, target, 0)
}

function countSub(arr, n, i, sum, count) {
  if(i === n) {
    if(sum === 0) {
      count += 1  
    }
    return count 
  }
  count = countSub(arr, n, i+1, sum - arr[i], count)
  count = countSub(arr, n, i+1, sum, count)

  return count   
}