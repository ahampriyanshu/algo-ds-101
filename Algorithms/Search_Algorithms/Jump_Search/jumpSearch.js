//Jump Search implementation in JavaScript.

var arr = [0, 1, 2, 4, 9, 16, 25, 36, 64, 81, 100, 121, 144, 189, 400, 625];
var n = arr.length;
var x = 144;

var step = Math.floor((Math.sqrt(n)));
var j = n-step-1;
for (var i = 0; i<n; i = i + step)
{
  if(arr[i]>x)
  {
    j = i - step;
    break;
  }
}
var ub = j + step;
for ( ; j<ub; j++)
{
  if(arr[j]==x)
  {
    console.log("Number found at index ",j);
  }
}
