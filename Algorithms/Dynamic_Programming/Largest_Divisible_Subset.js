var largestDivisibleSubset = function(nums) {
  if(nums.length < 2) return nums;
  let n = nums.length;
  nums.sort((a,b) => a - b)
  let dp = Array(n).fill(1);
  let parent = Array(n);

  for(let i = 0; i < n; i++) parent[i] = i;

  for(let i = 0; i < n; i++) {
    for(let j = 0; j < i; j++) {
      if(nums[i] % nums[j] === 0) {
        if(dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
          parent[i] = j;
        }
      }
    }
  }

  let max = Math.max(...dp)
  let maxIndex = -1;

  for(let i = 0; i < n; i++ ) {
    if(dp[i] == max) {
      maxIndex = i;
      break;
    }
  }


  let ans = [];
  let member = maxIndex;
  while(true) {
    ans.push(member)

    if(parent[member] == member) {
      break;
    }
    member = parent[member];
  }
  return ans.reverse().map(i => nums[i])
};
