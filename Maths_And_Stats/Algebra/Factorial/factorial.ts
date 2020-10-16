// tail recyrsion not work in js, but not the worst decision

const factorial = (n: number): number => rFactorial(n, 1);

const rFactorial = (n:number, acc:number): number => (n <= 0) ? acc : rFactorial(n-1, n*acc);

factorial(11)
