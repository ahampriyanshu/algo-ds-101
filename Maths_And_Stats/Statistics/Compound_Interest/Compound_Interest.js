var principle = 1000;
var time = 2;
var rate = 5;

var ci = principle * Math.pow( (1 + rate/100), time);
console.log("Compound Interest is: " + ci)
