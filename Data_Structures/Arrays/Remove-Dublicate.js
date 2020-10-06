// RemoveDuplicateItem

function RemoveDuplicateItem(arr) {
    let newAr = [];


    arr.forEach((item) => {
        if (!newAr.includes(item)) {
            newAr.push(item)
        }
    })
    return newAr
}

