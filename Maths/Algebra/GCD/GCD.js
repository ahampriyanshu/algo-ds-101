function gcd_two_numbers(x, y) {
    // Check if number is numerial or not
    if ((typeof x !== 'number') || (typeof y !== 'number'))
        return false;
    // Taking absolute values
    x = Math.abs(x);
    y = Math.abs(y);
    // Calculating GCD
    while (y) {
        var t = y;
        y = x % y;
        x = t;
    }
    return x;
}

// Test Cases
console.log(gcd_two_numbers(12, 13));
console.log(gcd_two_numbers(9, 3));

// Output : >
// 1 
// 3