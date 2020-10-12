/*
A TypeScript program to return Compound Interest
Parameters: 
principal amount
time 
interest rate
number of times to compound per time period,
all numbers
Returns;
compound interest,
a number
*/
let compoundInterest = function (principal: number, time : number, rate : number, n: number) : number {
    return principal * (Math.pow((1 + (rate / n)), (n * time)));
}

//Test
console.log(compoundInterest(1000, 2, 0.05, 1));

