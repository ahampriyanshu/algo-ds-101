function arrayProductExceptSelf(array) {
    const result = [];
    let product = 1;
    for (let i = 0; i < array.length; i++) {
        result[i] = product;
        product *= array[i];
    }
    product = 1;
    for (let i = array.length - 1; i >= 0; i--) {
        result[i] = result[i] * product;
        product*= array[i];
    }
    return result;
}

/* RETURNS PRODUCT OF ALL ELEMENTS OF GIVEN ARRAY EXCEPT ELEMENT ITSELF. */
/* Args:-
        arg1 => array to get product of elements except self.
*/

arrayProductExceptSelf([1,2,3,4]); // [ 24, 12, 8, 6 ]