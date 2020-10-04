A = input("Sequence 1: ")
B = input("Sequence 2: ")

c = []

def LCS(A,B,m,n):
    if m==0 or n==0:
        return 0
    elif A[m-1] == B[n-1]:
        return 1 + LCS(A,B,m-1,n-1)
    else:
        return max(LCS(A,B,m,n-1),LCS(A,B,m-1,n))


print(LCS(A,B,len(A),len(B)))