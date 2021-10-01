var data = [12, 43, 52, 13, 1, 63, 100, 22, 67, 239];
var sum = data.reduce((acc, val) => acc + val, 0);
var mean = sum / data.length;

var standardDeviation = data.reduce((acc, val) => acc + Math.pow(val - mean, 2), 0); //Square of the sum of each value minus the mean
standardDeviation = Math.sqrt(standardDeviation / data.length); //Square root of the previously obtained value over the size of the population

console.log(standardDeviation);