'''
Z algorithm for string searching.
@ Author - Sandip Dutta
'''

# Z Algorithm for String Searching in Linear Time
'''
Z Algorithm is a very fast string comparing algorithm.
It creates an additional Z Array which stores the length
of the longest substring from i'th position of the string 
which is also a prefix of string.

If Z[i] matches the length of the pattern, we have found
the pattern.
'''

def get_Z_arr(pattern, text):
    ''' Implements the Z-algorithm
    @ Args:
    > pattern - (str) String having the pattern
    > text - (str) The text in which to search the data.
    @ Return:
    > Z - The Z array for the data
    '''
    # L, R - variables which store the maximum window length
    L, R, k = 0, 0, 0

    # tempString[L,..., R] is a substring which is a prefix

    # $ is a special character for separating pattern from string
    tempString = pattern + "$" + text 
    totalLength = len(tempString)

    Z = [None] * totalLength # Z array

    for i in range(1, totalLength):    # Fill each element of Z Array
        # If i is beyond R
        # use normal way to compute the Z[i]
        if i > R:
            # Start from current position
            L = R = i
            # while R is within bounds and tempString[0..R] == tempString[i..i+R]
            while R < totalLength and tempString[R - L] == tempString[R]:
                R += 1
            # Z[i] is the largest prefix substring. R-L is the value
            Z[i] = R - L
            # [L, R] is the prefix substring, R exits loop with one more than length
            # Hence adjust the value
            R -= 1

        # If within [L, R]
        # Try to do with fewer computations as we already know [L, R]
        #  is a prefix substring
        else:
            # Get k value
            k = i -  L
            # Check if i + Z[k] exceeds the string
            # if does not, fill normally with previous
            # computed values
            if Z[k] < R - i + 1:
                Z[i] = Z[k]

            else:
                # Recall that [L, R] is the largest substring
                # If Z[i] where  L <= i <= R and i + Z[i] = t > R
                # Then [L, t] the largest substring.
                # Thus we further compute the values to get the proper R
                L = i
                while R < totalLength and tempString[R - L] == tempString[R]:
                    R += 1
                Z[i] = R - L
                # Decrease R by 1 to maintain condition
                R -= 1
    # print(Z)
    return Z

def ZSearch(text, pattern):
    ''' Searches for pattern using Z Algorithm'''
    lenPattern = len(pattern)
    Z = get_Z_arr(pattern, text) # Get the Z array

    patternPositions = [] # Positions where pattern is found

    for element in range(len(Z)):
        if Z[element] == lenPattern:
            patternPositions.append(element - lenPattern - 1)

    return patternPositions

def main():
    '''Driver Code'''
    pattern = input("Enter the pattern to be found > ")
    text = input("Enter the text where we need to find the pattern > ")
    positions = ZSearch(text, pattern)
    if positions:
        print(f"Pattern found at indices {positions}")
    else:
        print("! Pattern not found")

if __name__ == '__main__':
    main()