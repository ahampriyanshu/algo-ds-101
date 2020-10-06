def DivisiblePairCount(arr) :
    
    count = 0
    k = len(arr)
    for i in range(0, k):
        for j in range(i+1, k):

            if (arr[i] % arr[j] == 0 or arr[j] % arr[i] == 0):
                count += 1

    return count

if __name__ == "__main__":
    #give input in form of a list -- [1,2,3]
    arr = [int(item) for item in ''.join(list(input())[1:-1]).split(',')]
    print(DivisiblePairCount(arr))
