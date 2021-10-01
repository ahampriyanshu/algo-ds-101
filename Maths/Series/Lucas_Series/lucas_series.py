def LucasSum(N): 
    a = 2
    b = 1
    c = 0
    print(a)
    while (b <= N): 
        c = a + b 
        print(c)
        a = b 
        b = c 


# Driver code 
N = int(input())
LucasSum(N)


