#O(N) T | O(1) S

def waterArea(heights):
	water = 0	
	tallestRight = [0 for x in heights]
	maxHtRight = 0	
	tallestLeft = [0 for x in heights]
	maxHtLeft = 0	
	
	for i in reversed(range(len(tallestRight))):
		tallestRight[i] = maxHtRight
		maxHtRight = max(maxHtRight, heights[i])
		
	for i in range(len(tallestLeft)):
		tallestLeft[i] = max(maxHtLeft, heights[i])
		maxHtLeft = max(maxHtLeft,heights[i])
		
	for i in range(len(heights)):			
		leftMax = tallestLeft[i]
		rightMax = tallestRight[i]		
		minHeight = min(leftMax, rightMax)
		height = heights[i]
		if height < minHeight:
			water += minHeight - height
		else:	
			water += 0
	return water

heights = input('Enter a list of non-negative numbers separated by spaces without any enclosing braces\n')
heights_str = list(heights.split(' '))
heights_int = [int(height) for height in heights_str]
water = waterArea(heights_int)
print(water)