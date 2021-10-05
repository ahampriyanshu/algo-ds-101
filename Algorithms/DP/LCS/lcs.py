#Longest Common Subsequence
text1=input()
text2=input()
m=len(text1)
n=len(text2)
dp=[[0 for j in range(n+1)]for i in range(m+1)]
for i in range(m+1):
  for j in range(n+1):
    if i==0 or j==0:
      dp[i][j]=0
    elif text1[i-1]==text2[j-1]:
      dp[i][j]=1+dp[i-1][j-1]
    else:
      dp[i][j]=max(dp[i-1][j],dp[i][j-1])
print(dp[m][n])
