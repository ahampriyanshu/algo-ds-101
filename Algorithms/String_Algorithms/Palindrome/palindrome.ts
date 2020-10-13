import { ReadLine, createInterface } from 'readline';

const r1: ReadLine = createInterface({
    input: process.stdin,
    output: process.stdout
});

function palindromeCheck(str: string): boolean {
    return str.split('').reverse().join('') === str;
};

r1.question('Input a word to check if it is a palindrome: ', (answer: string) => {
    const isPalindrome: boolean = palindromeCheck(answer);

    if (!isPalindrome) {
        console.log('It is NOT a palindrome!')
    } else {
        console.log('It is a palindrome!');
    }

    process.exit(1);
});
