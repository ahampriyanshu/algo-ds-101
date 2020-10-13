var data = [7, 9, 12, 13, 16];
var length = data.length;
var position = 0;
var median = 0;
data.sort(function (a, b) {
  return a - b;
});
if (length % 2 === 0) {
  position = Math.ceil(length / 2) - 1;
  median = (data[position] + data[position + 1]) / 2;
} else {
  position = Math.floor(length / 2);
  median = data[position];
}
console.log("Median is : ", median);
