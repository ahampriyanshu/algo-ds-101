/**
 * @description given two linearly indepent vectors of R3, returns a vector that is perpendicular to both.
 * @param {Number[]} vectorA 
 * @param {Number[]} vectorB
 * @returns {Number[]} the perpendicular vector to both A and B
 */
export function crossProduct(vectorA, vectorB) {
    if (vectorA.length !== vectorB.length || vectorA.length !== 3) {
        throw ("The dimension of the vectors must be 3.")
    }
    return [
        vectorA[1] * vectorB[2] - vectorA[2] * vectorB[1],
        vectorA[2] * vectorB[0] - vectorA[0] * vectorB[2],
        vectorA[0] * vectorB[1] - vectorA[1] * vectorB[0]
    ]
}