// list of intervals as an array of objects
const arr = [
    { start: 1, end: 3 },
    { start: 2, end: 4 },
    { start: 5, end: 8 },
    { start: 6, end: 7 }
];


function mergeIntervals(arr) {
    // sort the array of intervals in ascending order based on the start value of each interval
    arr.sort(function(a, b) {
        if (a.start < b.start) return -1;
        if (a.start > b.start) return 1;
        return 0;
    });

    // result array which will work as stack
    let res = [];

    // push first interval into result array
    res.push(arr[0]);

    for (let i = 1; i < arr.length; i++) {
        // get the top of the result array
        // we will call it top interval
        const top = res[res.length - 1]

        // top interval's end is less than the current interval's start that means disjoint intervals
        // we can push the current interval to our result
        if (top.end < arr[i].start) {
            res.push(arr[i]);
        }
        // top interval's end is between the current interval's start and end
        // we can merge intervals with the ending at current interval's end
        else if (top.end < arr[i].end) {
            top.end = arr[i].end;
            // delete the top interval
            res.pop();
            // insert new modified interval
            res.push(top);
        }
        // Otherwise top interval's end is after the current interval's end
        // i.e after merge we will get top interval, hence no change required
    }

    // print the array of merged intervals
    console.log(res);
}

mergeIntervals(arr);