def largestDivisibleSubset(nums):
    S = {-1: set()}
    for x in sorted(nums):
        S[x] = max((S[d] for d in S if x % d == 0), key=len) | {x}
    return list(max(S.values(), key=len))

if __name__ == '__main__': 

    lst = [] 
    n = int(input("Enter number of elements : ")) 
    for i in range (n):
        x=int(input("enter no. \n")) 
        lst.insert(i,x)
        i+=1

    print(largestDivisibleSubset(lst))
