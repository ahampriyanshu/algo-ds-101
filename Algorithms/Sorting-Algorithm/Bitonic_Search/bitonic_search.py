def compAndSwap(a, i, j, dire):
    if (dire == 1 and a[i] > a[j]) or (dire == 0 and a[i] < a[j]):
        a[i], a[j] = a[j], a[i]
        
def bitonic_merge(a, low, cnt, dire):
    if cnt > 1:
        k = int(cnt / 2)
        for i in range(low, low + k):
            compAndSwap(a, i, i + k, dire)
        bitonic_merge(a, low, k, dire)
        bitonic_merge(a, low + k, k, dire)
        
def bitonic_sort(a, low, cnt, dire):
    if cnt > 1:
        k = int(cnt / 2)
        bitonic_sort(a, low, k, 1)
        bitonic_sort(a, low + k, k, 0)
        bitonic_merge(a, low, cnt, dire)
 
def sort(a, N, up):
    bitonic_sort(a, 0, N, up)
 
 
if __name__ == "__main__":
 
    a = []
 
    n = int(input().strip())
    for i in range(n):
        a.append(int(input().strip()))
    up = 1
 
    sort(a, n, up)
    print("\n\nSorted array is")
    for i in range(n):
        print("%d" % a[i])
