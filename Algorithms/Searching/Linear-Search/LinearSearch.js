var colors = ["red", "orange", "yellow", "green", "blue", "indigo", "violet", "black"];

function linearSearch(arr, ele) {
  for (var i=0; i<arr.length; i++) {
    if (arr[i] == ele) {
      return i;
    }
  } return null;
}

linearSearch(colors, "black"); // returns 7 i.e. colors[7] = 'black'
linearSearch(colors, "white"); // returns null - Element not found.
