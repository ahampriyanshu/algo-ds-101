matB = []
matA = []

rows,columns = map(int,input("Enter rows and columns for matrices").split())

for i in range(rows):
    matA.append([])
    for j in range(columns):
        matA[i].append(int(input(f"Enter a no. for matrixA[{i}][{j}] : ")))

for i in range(rows):
    matB.append([])
    for j in range(columns):
        matB[i].append(int(input(f"Enter a no. for matrixB[{i}][{j}] : ")))

print("------------------------------\n  Matrix A is : ")        
for i in matA:
    print(i)
    
print("------------------------------\n  Matrix B is : ")        
for i in matB:
    print(i)



matM = []
for i in range(rows):
    matM.append([])
    for j in range(columns):
        sum_of_column = 0
        for k in range(rows):
            sum_of_column += matA[i][k]*matB[k][i]
        matM[i].append(sum_of_column)

print("------------------------------\nMultiplication of the Matrix A and B is : ")  
for i in matM:
    print(i)
    
    
    
#          OUTPUT
#Enter rows and columns for matrices2 2
#Enter a no. for matrixA[0][0] : 1
#Enter a no. for matrixA[0][1] : 2
#Enter a no. for matrixA[1][0] : 3
#Enter a no. for matrixA[1][1] : 4
#Enter a no. for matrixB[0][0] : 1
#Enter a no. for matrixB[0][1] : 1
#Enter a no. for matrixB[1][0] : 1
#Enter a no. for matrixB[1][1] : 1
#------------------------------
#  Matrix A is : 
#[1, 2]
#[3, 4]
#------------------------------
#  Matrix B is : 
#[1, 1]
#[1, 1]
#------------------------------
#Multiplication of the Matrix A and B is : 
#[3, 3]
#[7, 7]
