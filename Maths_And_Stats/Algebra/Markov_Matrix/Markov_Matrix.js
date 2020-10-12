function isMarkovMatrix(matrix) {
    let isRight = isRightMarkov(matrix)
    let isLeft = isLeftMarkov(matrix)
    if (isRight && isLeft) { //If the matrix is a right and left Markov algorithm -> doubly markov matrix
        return 3
    } else if (isLeft) { //If the matrix is a left markov algorithm
        return 2
    } else if (isRight) { //If the matrix is a right markov algorithm
        return 1
    } else { //If every test fails, then its not a Markov matrix
        return 0
    }
}

function isRightMarkov(matrix) { //Each row summing to 1
    if (
        matrix
            .map(val => { //Get each row of the matrix and transform it to the
                //sum of all the elements in each row 
                return val.reduce((prev, curr) => prev + curr)
            })
            .every(row => row == 1) //Check if every sum equals to 1
    ) {
        return true //If check is true
    }
    return false //If check is false
}

function isLeftMarkov(matrix) { //Each collumn summing to 1
    let rot_matrix = matrix.map((val, index) => matrix.map(row => row[index])) //Rotates the matrix 90°

    //When rotated, collumns become rows, so we can reuse the isRightMarkov function

    return isRightMarkov(rot_matrix) //See if its a right markov matrix
}

//EXAMPLE INPUT
let example_matrix = [
    [0.9, 0.1],   //Right markov matrix example
    [0.5, 0.5],

    /* [0.9, 0.5], //left markov matrix example
    [0.1, 0.5],

    [1, 0, 0,], //not markov matrix example
    [0, 0, 2],
    [0, 0, 1]

    [1, 0, 0,], //doubly markov matrix example
    [0, 1, 0],
    [0, 0, 1] */
]

//EXAMPLE OUTPUT
switch (isMarkovMatrix(example_matrix)) {
    case 3:
        console.log("doubly markov matrix")
        break
    case 2:
        console.log("left markov matrix")
        break
    case 1:
        console.log("right markov matrix")
        break
    case 0:
        console.log("its not a markov matrix")
        break
}