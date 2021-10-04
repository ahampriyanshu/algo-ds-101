var heapSort = function(array) {
  var swap = function(array, firstIndex, secondIndex) {
    var temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
  };

  var maxHeap = function(array, i) {
    var l = 2 * i;
    var r = l + 1;
    var largest;
    if (l < array.heapSize && array[l] > array[i]) {
      largest = l;
    } else {
      largest = i;
    }
    if (r < array.heapSize && array[r] > array[largest]) {
      largest = r;
    }
    if (largest != i) {
      swap(array, i, largest);
      maxHeap(array, largest);
    }
  };
  var buildHeap = function(array) {
    array.heapSize = array.length;
    for (var i = Math.floor(array.length / 2); i >= 0; i--) {
      maxHeap(array, i);
    }
  };
  buildHeap(array);
  for (var i = array.length-1; i >= 1; i--) {
    swap(array, 0, i);
    array.heapSize--;
    maxHeap(array, 0);

    console.log(a + " ");
  }
};
var a = [6, 5, 3, 1, 8, 7, 2, 4];
heapSort(a);