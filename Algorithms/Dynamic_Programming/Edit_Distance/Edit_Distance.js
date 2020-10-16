var string1 = prompt("Enter String 1 -> ");
var string2 = prompt("Enter String 2 -> ");
var length1 = string1.length,length2=string2.length;
var array1 = [];
for(var i=0;i<=length1;i++){
    array1[i] = [];
}
for(var i=0;i<=length1;i++){
    array1[i][0] = i;
}
for(var i=0;i<=length2;i++){
    array1[0][i]=i;
}
for(var i=1;i<=length1;i++){
    for(var j=1;j<=length2;j++){
        if(string1[i-1]==string2[j-1]){
            array1[i][j]=array1[i-1][j-1];
            [i][j]=array1[i-1][j-1];
        }
        else{
            array1[i][j]=Math.min(Math.min(array1[i-1][j],array1[i][j-1]),array1[i-1][j-1])+1;
        }
    }
}
alert("Edit Distance is -> " + array1[length1][length2]);