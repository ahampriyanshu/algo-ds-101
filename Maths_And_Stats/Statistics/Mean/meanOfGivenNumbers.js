var arr = [10, 17, 25, 30, 40, 55, 60, 70];
var total = 0;
for (var i = 0; i < arr.length; i++) {
    total += arr[i];
}
var avg = total / arr.length;
console.log("Average of numbers is " + avg)