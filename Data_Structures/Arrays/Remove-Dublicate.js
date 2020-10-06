function RemoveDuplicateItem(arr) {
    let newAr = [];


    arr.forEach((item) => {
        if (!newAr.includes(item)) {
            newAr.push(item)
        }
    })
    return newAr
}

let ar = [5, 2, 6, 2, 3, 2, 8, 6]
RemoveDuplicateItem(ar)
//output [5,2,6,3,8]