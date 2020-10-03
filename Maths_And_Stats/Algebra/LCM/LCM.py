def lcm(x:int, y:int) -> int:
	'''
    Input: 2 integers x and y 

    Output: The smallest integer which is divisible by both x and y
    '''
    greater = max(x,y)
	lesser = min(x,y)

	multiple = 1
	while ((greater * multiple) % lesser != 0):
    # I use <greater * multiple> instead of <lesser * multiple> because greater steps through the number line faster
		multiple += 1
	return greater * multiple


def main():
    num1 = int(input())
    num2 = int(input())
    print(f"LCM({num1}, {num2}) = {lcm(num1,num2)}")


if __name__ == "__main__":
    main()