var twoSum = function(nums, target) {

var ans = [];
var map = {};
for (var i = 0; i < nums.length; i++) {
    if (map[target - nums[i]] !== undefined)
    {
        ans[0] = parseInt(map[target - nums[i]]) ;
        ans[1] = i;
        return ans;
    } 
    map[nums[i]] = i;
}
};

//Dynamic array
var nums=["2","7","11,"15"];
//Dynamic variable using eval/ Can use window too          
eval("target=9");
//passing using apply.
twoSum.apply(nums,target);
