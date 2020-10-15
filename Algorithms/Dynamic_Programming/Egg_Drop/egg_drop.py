INT_MAX=32767

def egg_drop(n,k):
    m=[[0 for x in range(k+1)]for x in range(n+1)]
    for i in range(1,n+1):
        m[i][0]=0
        m[i][1]=1
    
    for j in range(1,k+1):
        m[1][j]=j

    for i in range(2,n+1):
        for j in range(2,k+1):
            m[i][j]=INT_MAX
            for x in range(1,j+1):
               res = 1 + max(m[i-1][x-1], m[i][j-x]) 
               if res < m[i][j]: 
                m[i][j] = res
    print(m) 
    return m[n][k]

n=2
k=6
print(egg_drop(n,k))
