const manhattanDistance = (x1, y1, x2, y2) => {
	return Math.abs(x2 - x1) + Math.abs(y2 - y1);
};

// Test Cases:
// Horizontal Direction
// Vertical Direction
// Diagonal Direction
// No Movement
// Non-(0, 0) Origin
// Negative and Positive Values Mixed
const startXPositions = [0, 0, 0, 0, 1, -3];
const startYPositions = [0, 0, 0, 0, 1, 4];
const endXPositions = [5, 0, 5, 0, 6, 2];
const endYPositions = [0, 5, 5, 0, 6, -8];

for (var i = 0; i < startXPositions.length; i++) {
	const startXPos = startXPositions[i];
	const startYPos = startYPositions[i];
	const endXPos = endXPositions[i];
	const endYPos = endYPositions[i];
	
	console.log(`The manhattan distance between (${startXPos}, ${startYPos}) and (${endXPos}, ${endYPos}) is ${manhattanDistance(startXPos, startYPos, endXPos, endYPos)}!`);
};