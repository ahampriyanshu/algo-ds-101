/* 
* This function can run in any TS environment or be compiled to any JS environment: they're specific-agnostic.
* It returns the vector/cross product between two three-dimensional vectors.
* A 3D vector is described as an array of three numbers (x, y, z).
*/

/*
* A 3D Vector, which is an array of three numbers (x, y, z).
* @typedef {[number, number, number]} ThreeDimensionalVector
*/
type ThreeDimensionalVector = [number, number, number];

/*
* @description Given two three-dimensional vectors, returns the cross product: a vector that is perpendicular to both.
* @param {ThreeDimensionalVector} vectorA - The first vector;
* @param {ThreeDimensionalVector} vectorB - The second vector;
* @returns {ThreeDimensionalVector} - The resulting vector product (vectorC).
*/
function crossProduct(vectorA: ThreeDimensionalVector, vectorB: ThreeDimensionalVector): ThreeDimensionalVector {
    return [
        vectorA[1] * vectorB[2] - vectorA[2] * vectorB[1],
        vectorA[2] * vectorB[0] - vectorA[0] * vectorB[2],
        vectorA[0] * vectorB[1] - vectorA[1] * vectorB[0]
    ];
}
