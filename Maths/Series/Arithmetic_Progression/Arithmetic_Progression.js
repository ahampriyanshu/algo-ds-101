/* 
* These functions can run in any JS environment: they're specific-agnostic.
* Basically, they help getting an entire arithmetic progression,
* calculating a progression's nth term or the sum of the progression
* faster without using iterations.
*/

/* 
* Function to calculate an arithmetic progression, starting from a term,
* with given difference, up to a given number of terms.
* This function follows this formula:
*   an = a + n * d
* @param {Number} firstTerm - The term which starts the progression;
* @param {Number} difference - The common difference of the progression;
* @param {Number} nTerms - The maximum number of terms you wish to know;
* @returns {Number[]} - The [nTerms] terms of the arithmetic progression.
*/
function arithmeticProgression(firstTerm, difference, nTerms) {
    const terms = [];
    for (let term = firstTerm; (term / difference) < nTerms; term += difference) {
        terms.push(term);
    }

    return terms;
}

/* 
* Function to calculate the nth term of an arithmetic progression.
* This function follows this formula:
*   an = a1 + (n-1)d
* @param {Number} nTerm - The nth term you wish to know;
* @param {Number} firstTerm - The term which starts the progression;
* @param {Number} difference - The common difference of the progression;
* @returns {Number} - The nth term of the arithmetic progression.
*/
function arithmeticProgressionNthTerm(nTerm, firstTerm, difference) {
    return firstTerm + ((nTerm - 1) * difference);
}

/*
* Function to calculate the arithmetic series of an arithmetic progression,
* which is the sum of all the progression's terms, starting from a term 
* and ending with another, without knowing the difference.
* This function follows this formula:
*   S = 1/2 * n * (a1 + an)
* @param {Number} firstTerm - The term which starts the progression;
* @param {Number} lastTerm - The last term of the progression;
* @param {Number} nTerms - The number of terms which compose the progression;
* @returns {Number} - The arithmetic series of the progression.
*/
function arithmeticSeries(firstTerm, lastTerm, nTerms) {
    return 1 / 2 * nTerms * ( firstTerm + lastTerm );
}


/*
* There is no need to create a function to calculate
* the difference between two terms, because, well,
* that's just a difference.
* lastTerm - firstTerm = common difference of the progression.
*/
