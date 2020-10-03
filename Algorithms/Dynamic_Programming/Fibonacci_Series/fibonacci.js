/*
This function returns the nth fibonacci number, given 
*/
function fibonacci(n, memoizer) {
    memoizer = memoizer || {};
    if (memoizer[n]) {
        return memoizer[n];
    }
    if (n <= 1) {
        return 1;
    }
    return memoizer[n] = fibonacci(n - 1, memoizer) + fibonacci(n - 2, memoizer);
}
