def largestDivisibleSubset(nums):
    S = {-1: set()}
    for x in sorted(nums):
        S[x] = max((S[d] for d in S if x % d == 0), key=len) | {x}
    return list(max(S.values(), key=len))
    
if __name__ == '__main__': 
    arr = [1, 2, 17, 4] 
    print(largestDivisibleSubset(arr))
