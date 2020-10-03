def three_LCS(A,B,C):
    m=len(A)
    n=len(B)
    o=len(C)
    L=[[[0 for i in range(o+1)]for j in range(n+1)]for k in range(m+1)]
    for i in range(m+1):
        for j in range(n+1):
            for k in range(o+1):
                if (i==0 or j==0 or k==0):
                    L[i][j][k]=0
                elif (A[i-1]==B[j-1] and A[i-1]==C[k-1]):
                     L[i][j][k]= 1+L[i-1][j-1][k-1]
                else:
                     L[i][j][k]=max(max(L[i-1][j][k],L[i][j-1][k]),L[i][j][k-1])
    return L[m][n][o]


X = 'ABCDAB'
Y = 'BDCABA'
Z = '12XBA'

print('Length of LCS of three strings is', three_LCS(X, Y, Z))
