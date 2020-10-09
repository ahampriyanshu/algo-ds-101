// Merge_sorted_array

function mergeSorted(a, b) {
    var answer = new Array(a.length + b.length), i = 0, j = 0, k = 0;
    while (i < a.length && j < b.length) {
      if (a[i] < b[j]) {
          answer[k] = a[i];
          i++;
      }else {
          answer[k] = b[j];
          j++;
      }
      k++;
    }
    while (i < a.length) {
      answer[k] = a[i];
      i++;
      k++;
    }
    while (j < b.length) {
      answer[k] = b[j];
      j++;
      k++;
    }
    return answer;
  }


  // Merge All array that we pass.
  var mergeAll = function(){
      return Array.prototype.slice.call(arguments).reduce(mergeSorted);
  };
  

  //Number of Sorted_Array to be merge
  var a = [2, 4, 7,9];
  var b = [3, 6, 11, 12];
  var c = [5, 8, 10, 13];
  
  console.log(mergeAll(a,b,c).map(function(x){return x;}));


  /* input arrays :
   * a = [2, 4, 7,9];
   * b = [3, 6, 11, 12];
   * c = [5, 8, 10, 13];
   * output single_array :
   * 2 3 4 5 6 7 8 9 10 11 12 13
   * /