function counting_sort(arrin) {
    let arrout = new Array(arrin.length) //Creates the output array

    let arrcount = new Array(arrin.reduce(
        (prev, cur) => {
            return biggest = prev > cur ? prev : cur;
        }
    )).fill(0) //Creates the counting array (number = index - 1, value = quantity)

    //Gets the numbers quatities in their respective index
    arrin.forEach(val => arrcount[val - 1] += 1)

    let startpos = 0 //Starting position to fill with numbers

    arrcount.forEach((val, index) => {
        if (val != 0) { //If this number exists in the input array, its quantity is different than 0

            //Fill the output array with the number by its quantity beggining in the starting position
            //and ending after the number quantity
            arrout.fill(index + 1, startpos, startpos + val)

            startpos += val //Changes the starting position to the last known position for the next number
        }
    })

    return arrout //Return the sorted array
}

//Example of this algorithm
let example_input = [1, 4, 1, 2, 7, 5, 2]
let output = counting_sort(example_input)
console.log(`${example_input} sorted is ${output}`)

//Author -> GuilhermeOliveiraCasagrande