import math
 
# Pre-processing to calculate values of memo[][]
def dfs(u, p, memo, lev, log, g):

    memo[u][0] = p
    for i in range(1, log + 1):
        memo[u][i] = memo[memo[u][i - 1]][i - 1]
         
    for v in g[u]:
        if v != p:
            lev[v] = lev[u] + 1
            dfs(v, u, memo, lev, log, g)
 
# Function to return the LCA of nodes u and v
def lca(u, v, log, lev, memo):

    if lev[u] < lev[v]:
        swap(u, v)

    for i in range(log, -1, -1):
        if (lev[u] - pow(2, i)) >= lev[v]:
            u = memo[u][i]
             
    if u == v:
        return v

    for i in range(log, -1, -1):
        if memo[u][i] != memo[v][i]:
            u = memo[u][i]
            v = memo[v][i]
    
    return memo[u][0]
 

print("Enter Number of Nodes") 
n = input()

log = math.ceil(math.log(n, 2))
g = [[] for i in range(n + 1)]
 
memo = [[-1 for i in range(log + 1)]
            for j in range(n + 1)]
 
lev = [0 for i in range(n + 1)]

print("Enter The Edges")  
for i in range (1, (2*n-1)):
    m = input()
    n = input()
    g[m].append(n)

 
dfs(1, 1, memo, lev, log, g)

print("Enter The Edges to find LCA") 
e1 = input()
e2 = input()
print("The LCA is", lca(e1, e2, log, lev, memo))