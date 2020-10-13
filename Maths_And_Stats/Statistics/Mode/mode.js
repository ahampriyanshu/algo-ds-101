var arrayOne = [];
var counter=0,repeater,temp,mode;
var number1 = prompt("Enter Size of Array/Set -> ");

for(var i=0;i<number1;i++){
    arrayOne[i] = prompt("Enter " + (i+1) + " th number of the Set ->");
}

for(var i=0;i<number1;i++){
    temp = arrayOne[i];
    repeater = 0;
    for(var j=0;j<number1;j++){
        if(temp == arrayOne[j]){
            repeater++;
        }
    }
    if(repeater > counter){
        mode = temp;
        counter = repeater;
    }
}
alert("Mode of the entered Set is -> " + mode);