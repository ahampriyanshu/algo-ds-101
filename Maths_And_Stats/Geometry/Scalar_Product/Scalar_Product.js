/**
 * @description given two equal-length vectors, returns a single scalar number.
 * @param {Number[]} vectorA 
 * @param {Number[]} vectorB
 * @returns {Number} scalar number
 */
export function scalarProduct(vectorA, vectorB) {
    if (vectorA.length != vectorB.length) {
        throw ("The dimension of the vectors must be the same.")
    }
    return vectorA.reduce((accumulator, _, i) => accumulator += (vectorA[i] * vectorB[i]), 0)
}