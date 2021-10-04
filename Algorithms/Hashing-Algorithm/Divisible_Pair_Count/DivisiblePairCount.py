def DivisiblePairCount(arr, n) :

    res = 0

    for i in range(0, n):
        for j in range(i+1, n):

            if (arr[i] % arr[j] == 0 or arr[j] % arr[i] == 0):
                res+=1

    return res

if __name__=='__main__':
    arr = [int(item) for item in input("Enter the array items : ").split()]
    n = len(arr);
    print("Number of divisible pairs are:", DivisiblePairCount(arr, n) )

