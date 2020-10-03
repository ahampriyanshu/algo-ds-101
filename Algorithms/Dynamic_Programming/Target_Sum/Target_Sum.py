arr = list(map(int, input('Enter array: ').split()))
targetSum = int(input('Enter target sum: '))

dp = [[0 for i in range(targetSum + 1)] for i in range(len(arr))]
visited = [[0 for i in range(targetSum + 1)] for i in range(len(arr))]

def findNumberOfSubsetsMemo(arr, i, targetSum, n) : 
    
    print(i, targetSum)

    # Base condition
    if (i == n) : 
        if (targetSum == 0) : 
            return 1;  
        else : 
            return 0;  

    if(targetSum < 0):

        return 0;
   
    #Retrieve if already solved
    if (visited[i][targetSum] == 1) : 
        return dp[i][targetSum];  
    
    #Set as solved
    visited[i][targetSum] = 1;  
  
    # Recursion call
    dp[i][targetSum] = findNumberOfSubsetsMemo(arr, i + 1, targetSum, n) + findNumberOfSubsetsMemo(arr, i + 1, targetSum - arr[i], n);  
      
    return dp[i][targetSum];

def findNumberOfSubsetsRecur(arr, n, i,sum, count): 
      
    if (i == n): 
  
        if (sum == 0): 
            count += 1
        return count 
  
    count = findNumberOfSubsetsRecur(arr, n, i + 1, sum - arr[i], count) 
    count = findNumberOfSubsetsRecur(arr, n, i + 1, sum, count) 
    return count

print('By Memo:', findNumberOfSubsetsMemo(arr, 0, targetSum, len(arr)))