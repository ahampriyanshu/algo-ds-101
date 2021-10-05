function pancakeSort(arr){
  findMaxIndex = (arr2, k) => {
    let max = -Infinity 
    let maxIndex = 0
    
    for(let i = 0; i < k; i++){
        if(arr2[i] >= max){
          max = arr2[i]
          maxIndex = i
        }       
    }
    return maxIndex
  }
  flip = (arr3, k2) => {
    let i = 0
       
    while (i < k2) {
      let temp = arr3[k2]
      arr3[k2] = arr3[i]
      arr3[i] = temp
      i++
      k2--
    }
    return arr3
  }
  let i = arr.length
  while(i > 1){
  	let maxIndex = findMaxIndex(arr, i)
  	if(maxIndex !== i - 1){
  		flip(arr, maxIndex)
  		flip(arr, i - 1)
  	}
  i--
  }
  return arr
}

pancakeSort([4,3,1,2,5,6]);//[1,2,3,4,5,6]
