// a = starting_term   d = difference   n = number_of_terms
function harmonic_expression(a,d,n) {
    for (let i=0;i<n;i++)
        console.log("1/"+ (Number(a)+Number(i*d))+"\t");
}
let a,d,n;
a = prompt("Enter starting term");
d = prompt("Enter difference");
n = prompt("Enter number of terms");

harmonic_expression(a,d,n);
