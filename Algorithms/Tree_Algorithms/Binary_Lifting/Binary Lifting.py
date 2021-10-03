import math
 
# Pre-processing to calculate values of memo[][]
def dfs(u, p, memo, lev, log, g):
     
    # Using recursion formula to calculate
    # the values of memo[][]
    memo[u][0] = p
    for i in range(1, log + 1):
        memo[u][i] = memo[memo[u][i - 1]][i - 1]
         
    for v in g[u]:
        if v != p:
            lev[v] = lev[u] + 1
            dfs(v, u, memo, lev, log, g)
 
# Function to return the LCA of nodes u and v
def lca(u, v, log, lev, memo):
     
    # The node which is present farthest
    # from the root node is taken as u
    # If v is farther from root node
    # then swap the two
    if lev[u] < lev[v]:
        swap(u, v)
         
    # Finding the ancestor of u
    # which is at same level as v
    for i in range(log, -1, -1):
        if (lev[u] - pow(2, i)) >= lev[v]:
            u = memo[u][i]
             
    # If v is the ancestor of u
    # then v is the LCA of u and v        
    if u == v:
        return v
         
    # Finding the node closest to the
    # root which is not the common ancestor
    # of u and v i.e. a node x such that x
    # is not the common ancestor of u
    # and v but memo[x][0] is
    for i in range(log, -1, -1):
        if memo[u][i] != memo[v][i]:
            u = memo[u][i]
            v = memo[v][i]
     
    # Returning the first ancestor
    # of above found node        
    return memo[u][0]
 
 
# Number of nodes
n = 9
 
log = math.ceil(math.log(n, 2))
g = [[] for i in range(n + 1)]
 
memo = [[-1 for i in range(log + 1)]
            for j in range(n + 1)]
 
# Stores the level of each node            
lev = [0 for i in range(n + 1)]
 
# Add edges
g[1].append(2)
g[2].append(1)
g[1].append(3)
g[3].append(1)
g[1].append(4)
g[4].append(1)
g[2].append(5)
g[5].append(2)
g[3].append(6)
g[6].append(3)
g[3].append(7)
g[7].append(3)
g[3].append(8)
g[8].append(3)
g[4].append(9)
g[9].append(4)
 
dfs(1, 1, memo, lev, log, g)
 
print("The LCA of 6 and 9 is", lca(6, 9, log, lev, memo))
print("The LCA of 5 and 9 is", lca(5, 9, log, lev, memo))
print("The LCA of 6 and 8 is", lca(6, 8, log, lev, memo))
print("The LCA of 6 and 1 is", lca(6, 1, log, lev, memo))