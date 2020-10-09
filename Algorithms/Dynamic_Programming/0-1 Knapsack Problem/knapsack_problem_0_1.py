#0/1 Knapsack problem


def knapsack(val, wt, N, C):
    
    table = [[ 0 for _ in range(0, C+1)] for _ in range(0, N+1)]
    table[0][0] = 0
    
    for i in range(1, N+1):
        for c in range(1, C+1):
            
            if c - wt[i-1] < 0:
                table[i][c] = table[i-1][c]
            else:
                table[i][c] = max(table[i-1][c], table[i-1][c-wt[i-1]]+val[i-1])
    return table[N][C]
    

N = int(input().strip())
W = int(input().strip())  # capacity
val = [ int(v) for v in input().strip().split(" ")]
wt =  [ int(w) for w in input().strip().split(" ")]
print(knapsack(val, wt, N, W))