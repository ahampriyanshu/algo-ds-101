<script> 
let recursiveFunction = function (arr, x, start, end) { 
	
	// Base Condition 
	if (start > end) return false; 

	// Middle index 
	let mid=Math.floor((start + end)/2); 

	// Compare mid with given key x 
	if (arr[mid]===x) return true; 
		
	// search left half of mid 
	if(arr[mid] > x) 
		return recursiveFunction(arr, x, start, mid-1); 
	else
		// search in the right half of mid 
		return recursiveFunction(arr, x, mid+1, end); 
} 
 
let arr = [1, 3, 5, 7, 8, 9]; 
let x = 5; 

if (recursiveFunction(arr, x, 0, arr.length-1)) 
	document.write("Element found!<br>"); 
else document.write("Element not found!<br>"); 

x = 6; 

if (recursiveFunction(arr, x, 0, arr.length-1)) 
	document.write("Element found!<br>"); 
else document.write("Element not found!<br>"); 
</script>									 
