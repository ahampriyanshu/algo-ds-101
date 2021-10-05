# Swap functions
def swap(A, i, j):
    temp = A[i]
    A[i] = A[j]
    A[j] = temp 
# reaggrange array
def rearrangeArray(A):
    for i in range(1, len(A), 2):
        if A[i - 1] > A[i]:
            swap(A, i - 1, i)
        if i + 1 < len(A) and A[i + 1] > A[i]:
            swap(A, i + 1, i)
if __name__ == '__main__': 
    A = []
    n = int(input("Enter number of elements : ")) 
    A = list(map(int,input("\nEnter the numbers:").strip().split()))[:n] 
    rearrangeArray(A)
print(A)
