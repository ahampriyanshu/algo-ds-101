function strandSort(arrin: number[]): number[] {

  /* if the array has no elements, then it dosent need to be sorted */
  if (arrin.length == 0) return

  let arrout: number[] = []
  /* 
  is the same as
  let subarr: number[], arrout: number[] = [] 
  but to run the JS compiled code without undefined error, I did this
  */

  while (arrin.length != 0) {
    let subarr: number[] = [] /* Start the new iteration with a new subarray */

    subarr.push(arrin.shift()) /* Get the first element into subarray */

    arrin.forEach((num) => {
      if (num > subarr[0]) {
        subarr.push(num) /* Add every element bigger than the first element to the subarray*/
      }
    })

    /* Remove from input array elements that where added to the subarray*/
    arrin = arrin.filter(num => subarr.indexOf(num) == -1)

    /* Find out if we concat the subarray before or after the output array */
    if (arrout.length == 0 || arrout[arrout.length - 1] > subarr[0]) {
      arrout = subarr.concat(arrout)
    } else {
      arrout = arrout.concat(subarr)
    }
  }

  return arrout /* Retun the output array */
}
console.log(strandSort([10, 5, 30, 40, 2, 4, 9]))

/*
 Example input
 strandSort([10, 5, 30, 40, 2, 4, 9])
*/


/*
 Example output
 {2, 4, 5, 9, 10, 30, 40}
 */