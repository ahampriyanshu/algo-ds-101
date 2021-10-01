const eggDrop = (n: number, k: number) => {
  let eggFloor: number[][] = [];

  // A 2d array where entry eggFloor[i][j] will represent
  // the minimum number of trials needeed for i eggs and j floors
  for (let i = 0; i < n + 1; i++) {
    eggFloor.push(new Array(k + 1).fill(0));
  }

  // One trial for one floor and 0 trial for zero floor
  for (let i = 1; i < n + 1; i++) {
    eggFloor[i][1] = 1;
    eggFloor[i][0] = 0;
  }

  // We always need j trials for one egg and j floors
  for (let j = 1; j < k + 1; j++) {
    eggFloor[1][j] = j;
  }

  // Fill the rest of the entries in table using optimal
  // subtructure property
  for (let i = 2; i < n + 1; i++) {
    for (let j = 2; j < k + 1; j++) {
      eggFloor[i][j] = Number.MAX_SAFE_INTEGER;
      for (let x = 0; x < j + 1; x++) {
        let res = 1 + Math.max(eggFloor[i - 1][x - 1], eggFloor[i][j - x]);
        if (res < eggFloor[i][j]) {
          eggFloor[i][j] = res;
        }
      }
    }
  }

  // eggFloor[n][k] holds the result
  return eggFloor[n][k];
};

const n = 2;
const k = 36;
console.log(
  "Minimum worst case of trials in worst case with " +
    n +
    " eggs " +
    k +
    " floors is " +
    eggDrop(n, k)
);
