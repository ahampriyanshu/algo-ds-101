/* PigeonholeSort Implementation in Typescript
It is suitable for sorting elements where number of 
elements is approximately the same as the number of
possible values
*/
const pigeonholeSort = (array: number[]): number[] => {
  const max = Math.max(...array);
  const min = Math.min(...array);
  const range = max - min + 1;
  let phole = new Array(range).fill(0);

  for (let i = 0; i < array.length; i++) {
    phole[array[i] - min]++;
  }

  let index = 0;

  for (let j = 0; j < range; j++) {
    while (phole[j]-- > 0) {
      array[index++] = j + min;
    }
  }

  return array;
};

const array = [9, 4, 2, 5, 1, 7, 8, 6];
console.log(pigeonholeSort(array));
