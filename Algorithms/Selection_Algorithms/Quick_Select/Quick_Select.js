function partition(array3, l, r){ 
    var x = array3[r], i = l,temp;
    for (var j = l; j <= r - 1; j++) { 
        if (array3[j] <= x) { 
            temp = array3[i];
            array3[i] = array3[j];
            array3[j] = temp; 
            i++; 
        } 
    } 
    temp = array3[i];
    array3[i] = array3[j];
    array3[j] = temp; 
    return i; 
}
function termFinder(array1, l, r, k){ 
    if (k > 0 && k <= r - l + 1) { 
        var index = partition(array1, l, r); 
        if (index - l == k - 1){
            return array1[index]; 
        }
        if (index - l > k - 1){
            return termFinder(array1, l, index - 1, k);
        }
        return termFinder(array1, index + 1, r,k - index + l - 1); 
    }
    return "error"; 
}
var array1 = [];
var length1 = parseInt(prompt("Enter length of array -> "));
for(var i=0;i<length1;i++){
    array1[i] = parseInt(prompt("Enter " + (i+1) + " th element of the array -> "));
}
var num1 = parseInt(prompt("Enter value of k for 'k th' smallest element -> "));

alert("K-th smallest element is " + termFinder(array1,0, length1-1,num1)); 