export function palindromeCheck(str: string): boolean {
    return str.split('').reverse().join('') === str;
};

console.log(palindromeCheck('palindrome')); // should return false
console.log(palindromeCheck('rotator')); // should return true
console.log(palindromeCheck('malayalam')); // should return true
console.log(palindromeCheck('racecar')); // should return true
console.log(palindromeCheck('github')); // should return false
