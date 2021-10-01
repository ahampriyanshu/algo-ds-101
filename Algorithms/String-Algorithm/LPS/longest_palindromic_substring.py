def longestPalSubstr(string): 
    """
    This function prints the longest palindrome substring (LPS) 
    of string. It also returns the length of the longest palindrome 
    :param string: The string to check for palindrome
    """

    maximumLength = 1

    start = 0
    length = len(string) 

    low = 0
    high = 0

    # One by one consider every character as center point of 
    # even and length palindromes 
    for i in range(1, length): 
        # Find the longest even length palindrome with center 
        # points as i-1 and i. 
        low = i - 1
        high = i 
        while((low >= 0) and (high < length) and (string[low] == string[high])): 
            if (high - low + 1 > maximumLength): 
                start = low 
                maximumLength = high - low + 1
            low -= 1
            high += 1

        # Find the longest odd length palindrome with center 
        # point as i 
        low = i - 1
        high = i + 1
        while ((low >= 0) and (high < length) and (string[low] == string[high])): 
            if high - low + 1 > maximumLength: 
                start = low 
                maximumLength = high - low + 1
            low -= 1
            high += 1

    print("Longest palindrome substring is: {}".format(string[start:start + maximumLength]))

# Driver program to test above functions 
string = "anaqwertyuioppoiuytrewqksl"
longestPalSubstr(string)