function strStr(text: string, pattern: string): number {
    if (pattern === '')
        return 0;
    
    const prime = 101;
    const n = text.length;
    const m = pattern.length;
    const base = 26;
    let h = 0;
    let wh = 0; // word window hash, m in length
    
    if (m > n)
        return -1;
    
    const hash = (charCode: number, exp: number) => {
        return charCode * Math.pow(base, exp) % prime;
    };
    
    // hash the pattern and first window
    for (let i = 0; i < m; i++) {
        h += hash(pattern.charCodeAt(i), m - i - 1);
        wh += hash(text.charCodeAt(i), m - i - 1);
    }
    
    h %= prime;
    wh %= prime;
    
    // traverse word
    for (let i = 0; i <= (n - m); i++) {
        if (h === wh && pattern === text.substring(i, i + m)) {
            return i;
        } else {
            wh -= hash(text.charCodeAt(i), m - 1);
            wh *= base;
            wh %= prime;
            wh += text.charCodeAt(i + m);
            wh %= prime;
        }
    }
    return -1;
};
