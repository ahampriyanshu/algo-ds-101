/* 
* This class can run in any TS environment or be compiled to any JS environment: they're specific-agnostic.
* Basically, it helps getting an entire arithmetic progression, calculating a progression's nth term or the 
* sum of the progression faster without using iterations.
*/

class ArithmeticProgression {
    firstTerm: number;
    difference?: number;

    /*
    * @constructor
    * @params {Number} [firstTerm=0] - The first term of the progression is required for all methods in this class, so it's a required param.
    * @params {Number} [difference=1] - If known, this is the common difference between the progression's terms. It's required for the two main methods.
    */
    constructor(firstTerm: number = 0, difference: number = 1) {
        this.firstTerm = firstTerm;
        this.difference = difference;
    }

    /* 
    * Method to calculate an arithmetic progression, starting from a term,
    * with given difference, up to a given number of terms.
    * The "difference" parameter in the constructor is required.
    * This method follows this formula:
    *   an = a + n * d
    * @param {Number} nTerms - The maximum number of terms you wish to know;
    * @returns {Number[]} - The [nTerms] terms of the arithmetic progression.
    */
    calculate(nTerms: number): number[] {
        const terms = [];
        for (let term = this.firstTerm; (term / this.difference) < nTerms; term += this.difference) {
            terms.push(term);
        }
    
        return terms;
    }

    /* 
    * Method to calculate the nth term of an arithmetic progression.
    * The "difference" parameter in the constructor is required.
    * This method follows this formula:
    *   an = a1 + (n-1)d
    * @param {Number} nTerm - The nth term you wish to know;
    * @returns {Number} - The nth term of the arithmetic progression.
    */
    getNthTerm(nTerm: number): number {
        return this.firstTerm + ((nTerm - 1) * this.difference);
    }

    /*
    * Method to calculate the arithmetic series of an arithmetic progression,
    * which is the sum of all the progression's terms, starting from a term 
    * and ending with another, without knowing the difference.
    * This method follows this formula:
    *   S = 1/2 * n * (a1 + an)
    * @param {Number} lastTerm - The last term of the progression;
    * @param {Number} nTerms - The number of terms which compose the progression;
    * @returns {Number} - The arithmetic series of the progression.
    */
    getSeries(lastTerm: number, nTerms: number): number {
        return 1 / 2 * nTerms * ( this.firstTerm + lastTerm );
    }

    /*
    * There is no need to create a method to calculate
    * the difference between two terms, because, well,
    * that's just a difference.
    * lastTerm - firstTerm = common difference of the progression.
    * I'll do it anyways, because a method which does it can be handy.
    * @param {Number} secondTerm - The second term to get the difference along with the first;
    * @param {Boolean} abs - If you want the result as an absolute value or not;
    * @returns {Number} - The difference between the first and second terms.
    */
    getDifference(secondTerm: number, abs: boolean): number {
        return abs
                ? Math.abs(secondTerm - this.firstTerm)
                : secondTerm - this.firstTerm;
    }
}
