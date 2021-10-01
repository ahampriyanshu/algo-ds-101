def Maximum_Achievable_coins(arr, n):
    matrix = [[0 for x in range(n)] for y in range(n)]

    for diagonal in range(n):
        for j in range(diagonal,n):
            i = j - diagonal

            x = 0
            if( (i+2) <= j):
                x =  matrix[i+2][j]
            y = 0
            if( (i+1) <= (j-1)):
                y =  matrix[i+1][j-1]
            z = 0
            if( i <= (j-2)):
                z =  matrix[i][j-2]

            matrix[i][j] = max(arr[i]+min(x,y), arr[j]+min(y,z))
    return print("The maximum possible amount of money that we can definitely win if we move first is: "+str(matrix[0][n-1]))

if __name__ == '__main__':
    n = int(input('Coin numbers: '))
    arr = []
    [arr.append(int(input('Coin number '+str(x+1)+' : '))) for x in range(n)]
    Maximum_Achievable_coins(arr, n)
