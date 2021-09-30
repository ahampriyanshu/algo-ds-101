var inputArray = [];
var size = prompt('Enetr the size: ');

for(var i=0; i<size; i++) {
	
	inputArray[i] = prompt('Enter Element ' + (i+1) + ' : ');
}


let nums = inputArray;
console.log("Original array:");
console.log(nums);
let is_Sorted = true;
while (is_Sorted){
	for (let i = 0; i< nums.length - 1; i++){
	  if (nums[i] > nums[i + 1])
	    {
      	let temp = nums[i];
        nums[i] = nums[i + 1];
        nums[i+1] = temp;
        is_Sorted = true;
      }
   }

		if (!is_Sorted)
	    break;

   is_Sorted = false;

   for (let j = nums.length - 1; j > 0; j--){
		 if (nums[j-1] > nums[j])
  	   {
  	     let temp = nums[j];
         nums[j] = nums[j - 1];
         nums[j - 1] = temp;
  	     is_Sorted = true;
       }
   }
}
console.log("Sorted array:")
console.log(nums);
