n = 3
m = 3


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


arr = [ [ 1, 0, 1],
    [ 1, 1, 0 ],
    [ 1, 1, 0 ] ]

print(countSquareMatrices(arr, n, m))
