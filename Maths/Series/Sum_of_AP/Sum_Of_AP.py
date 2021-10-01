# Function to calculate sum of a given AP sequence
def Sum_AP(ap):
    terms = len(ap) # Number of terms in AP
    common_difference = [] # A list for storing all the common differences
    index = 0
    # Loop to get all common differences
    while index < (terms-1):
        # adding the common difference of current and net element
        common_difference.append(ap[index+1]-ap[index])
        # if this and previous common difference are not same and if index is not zero, sequence is not in AP
        if (index!=0) and (common_difference[index] != common_difference[index-1]):
            return "Not in AP"
        index += 1
    # this part will be executed only if sequence is in AP

    # if no of terms is even
    if terms % 2 == 0:
        # if all common difference are same, index will be term - 1
        if index == (terms - 1):
            # implementing the formula for sum of AP with even no of terms= (n/2)*(2*a +(n-1)*d)
            sum = (terms // 2) * ((2 * ap[0]) + ((terms - 1) * common_difference[0]))
            return "Sum of AP = "+str(sum)

    # if no of terms is even
    if terms % 2 == 1:
        # if all common difference are same, index will be term - 1
        if index == (terms-1):
            # implementing the formula for sum of AP with odd no of terms = n*(a+((n-1)/2)*d)
            sum = terms*(ap[0]+((terms-1)//2)*common_difference[0])
            return "Sum of AP = "+str(sum)


# Driver Code

# Calling function Sum_AP and passing into it the sequence given as input
ap = list(map(int,input("Enter elements : ").split()))
print(Sum_AP(ap))

'''
Input description: 
    Line 1 -- Sequence (seperated by spaces)

Output Description :
    Sum of AP = Sum

Example Outputs:

    Input 1:
    Enter elements : 1 2 3 4
    
    Output 1:
    Sum of AP = 10
    
    
    
    Input 2:
    Enter elements : 1 3 5
    
    Output 2:
    Sum of AP = 9
'''