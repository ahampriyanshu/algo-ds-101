  let allPositives = arr => arr.every(n => n > 0)
  let allNegatives = arr => arr.every(n => n < 0)
  let sum = arr => arr.reduce((curr_max, max_so_far) => curr_max + max_so_far, 0)
  
  var maxSequence = function(arr){
    if(arr.length === 0 || allNegatives(arr)) return 0;
    if(allPositives(arr)) return sum(arr);
  
    var curr_max = 0, max_so_far = 0;
  
    for(var i = 0; i < arr.length; i++){  
      curr_max = Math.max(0, curr_max + arr[i]);
      max_so_far = Math.max(curr_max, max_so_far);
    }
    return max_so_far;
  }