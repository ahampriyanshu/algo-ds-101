/* A JavaScript program to perform Shell Sort */

shellSort = (array) => {
  for (var h = array.length; h > 0; h = parseInt(h / 2)) {
    for (var i = h; i < array.length; i++) {
      var k = array[i];
      for (var j = i; j >= h && k < array[j - h]; j -= h)
        array[j] = array[j - h];
      array[j] = k;
    }
  }
  return array;
};

var array = [8, 3, 5, 9, 1, 5, 9, 2, 3, 8, 4];
console.log(shellSort(array));
