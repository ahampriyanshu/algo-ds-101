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

    // result array
    let res = [];

    // push first interval into result array
    res.push(arr[0]);

    for (let i = 1; i < arr.length; i++) {
        // get the last interval of the result array
        const last = res[res.length - 1]

        // current interval end is less than the next interval's start that means disjoint intervals
        // we can add the interval to our result
        if (last.end < arr[i].start) {
            res.push(arr[i]);
        }
        // current interval end is between the next interval's start and end
        // we can merge intervals with ending at next interval's end
        else if (last.end < arr[i].end) {
            last.end = arr[i].end;
            // delete the last interval
            res.pop();
            // insert new modified interval
            res.push(last);
        }
        // Otherwise current interval end is after the next interval's end
        // we can merge intervals with ending at current interval's end hence no change required
    }

    // print the array of merged intervals
    console.log(res);
}

mergeIntervals(arr);