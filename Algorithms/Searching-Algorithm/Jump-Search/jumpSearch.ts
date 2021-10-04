//Jump Search implementation in Typescript.

let arr: number[] = [0, 1, 2, 4, 9, 16, 25, 36, 64, 81, 100, 121, 144, 189, 400, 625];
let x = 144;
let n = arr.length;

let step = Math.floor((Math.sqrt(n)));
let j = n-step-1;
for (let i = 0; i<n; i = i + step)
{
  if(arr[i]>x)
  {
    j = i - step;
    break;
  }
}
let ub = j + step;
for ( ; j<ub; j++)
{
  if(arr[j]==x)
  {
    console.log("Number found at index ",j,arr[0]);
  }
}
