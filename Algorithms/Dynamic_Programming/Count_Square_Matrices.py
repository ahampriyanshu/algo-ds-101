def countSquareMatrices(a, N, M):

    count = 0

    for i in range(1, N):
        for j in range(1, M):
            if (a[i][j] == 0):
                continue

            # Calculating  number of square submatrices ending at (i, j)
            a[i][j] = min([a[i - 1][j], a[i][j - 1], a[i - 1][j - 1]])+1

    # Calculate the sum of the array
    for i in range(N):
        for j in range(M):
            count += a[i][j]

    return count

n = int(input())
m = int(input())

matrix = []
print("Enter elements row-wise")
for i in range(n):          # a for loop for row entries
    a =[]
    for j in range(m):      # a for loop for column entries
         a.append(int(input()))
    matrix.append(a)
    
print("\nNumber of square submatrices with all ones is",countSquareMatrices(matrix, n, m))
