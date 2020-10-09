const readline = require('readline')
const reader = readline.createInterface(process.stdin, process.stdout); 

function countDivisiblePairs(arr) {
    let res = 0, n = arr.length
    for(let i=0;i<n;++i)
        for(let j=i+1;j<n;++j)
            if(arr[i]%arr[j] === 0 || arr[j]%arr[i] === 0)
                ++res
    return res
}

reader.question('Enter array elements seperated by space: ', arr => {
    let numbers = arr.split(" ")
    console.log("There are " + countDivisiblePairs(numbers) + " divisible pairs in given array.")
    reader.close()
})