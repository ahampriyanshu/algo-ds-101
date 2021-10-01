def matrixMultiplication(matrixA, matrixB):
    resultMatrix = []
    sizeOfMatrixA = len(matrixA)
    sizeOfMatrixB = len(matrixB)

    for rowIndex in range(sizeOfMatrixA):
        tempList = []

        for columnIndex in range(sizeOfMatrixB):
            sum = 0

            for columnIndexMatrixA in range(len(matrixA[0])):
                sum += matrixA[rowIndex][columnIndexMatrixA] * matrixB[columnIndexMatrixA][columnIndex]

            tempList.append(sum)
        resultMatrix.append(tempList)

    return resultMatrix


A = [[1, 2, 3],
     [4, 5, 6],
     [7, 8, 9]]
B = [[9, 8, 7],
     [6, 5, 4],
     [3, 2, 1]]
print(matrixMultiplication(A, B))