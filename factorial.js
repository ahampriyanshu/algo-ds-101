function factorial(n) {
    if (n<0) {
        return("Negatives don't have factorial")
    }
    else if (n==0 || n==1) {
        return (1)
    }
    else {
        while(n>1) {
            return (n*factorial(n-1))
        }
    }
}
number = prompt("Enter number")
console.log(factorial(number))
