const sortInsertion = (arr) => {
	for (let i = 1; i < arr.length; i++) {
		const value = arr[i];
		let lastIndex = i - 1;
		while (lastIndex >= 0 && arr[lastIndex] > value) {
			arr[lastIndex + 1] = arr[lastIndex];
			lastIndex--;
		}
		arr[lastIndex + 1] = value;
	};
	return arr;
};

const sortBucketPositive = (arr) => {
	const length = arr.length;
	const maxValue = Math.max(...arr);
	const divider = Math.ceil((maxValue + 1) / length);
	
	const buckets = [];
	
	// Place array values inside buckets
	for (let i = 0; i < length; i++) {
		const value = arr[i];
		const bucketIndex = Math.floor(value / divider);
		
		// If bucket does not exist
		// Instantiate a new array inside the buckets array
		if (!buckets[bucketIndex]) {
			buckets[bucketIndex] = [];
		};
		
		buckets[bucketIndex].push(value);
	};
	
	// Iterate through buckets and perform insertion sort
	for (let i = 0; i < length; i++) {
		// Ignore empty buckets
		if (!buckets[i]) {
			continue;
		}
		
		buckets[i] = sortInsertion(buckets[i]);
	};
	
	// Merge and return buckets
	return buckets.flat();
};

// This bucket sort implementation works with both positive and negative values
const sortBucket = (arr) => {
	const positiveArr = [];
	const absNegativeArr = [];
	
	// Split array into two arrays
	// An array containing the positive values
	// And an array containing the absolute value of all the negative values
	for (let i = 0; i < arr.length; i++) {
		const value = arr[i];
		if (value >= 0) {
			positiveArr.push(value);
		}
		else {
			absNegativeArr.push(Math.abs(value));
		}
	};
	
	const sortedPositiveArr = sortBucketPositive(positiveArr);
	const sortedNegativeArr = sortBucketPositive(absNegativeArr).reverse().map(x => -x);
	
	return sortedNegativeArr.concat(sortedPositiveArr);
};


// Driver Code

// Test Cases:
// Standard shuffled array
// Backwards array
// Already sorted array
// Empty array
// Array of length 1
// Exclusively negative elements
// Negative and positive elements
// Equal values

const arrays = [
	[3, 8, 9, 10, 2, 6, 4, 5, 7, 1],
	[10, 9, 8, 7, 6, 5, 4, 3, 2, 1],
	[1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
	[3],
	[-1, -2, -5, -4, -10, -8, -3, -9, -6, -7],
	[10, -3, -8, 12, 6],
	[5, 5, 3, 2]
];

for (let i = 0; i < arrays.length; i++) {
	const arr = arrays[i];
	const sortedArr = sortBucket(arr);
	console.log(`${arr} => Bucket Sorted = ${sortedArr}!`);
};