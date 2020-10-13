A = [2,3,80,45,6,111]

for i in range(len(A)):
    min = i
    for j in range(i+1, len(A)):
        if A[min] > A[j]:
            min = j
    A[i], A[min] = A[min],A[i]
for i in range(len(A)):
    print(A[i],end = " ")