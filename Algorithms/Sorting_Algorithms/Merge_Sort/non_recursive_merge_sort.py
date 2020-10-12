def mergeSort(a):  
      
    current_size = 1
      
    while current_size < len(a) - 1:  
          
        left = 0
        while left < len(a)-1:  
              
            mid = min((left + current_size - 1),(len(a)-1)) 
              
            right = ((2 * current_size + left - 1,  
                    len(a) - 1)[2 * current_size  
                        + left - 1 > len(a)-1])  
                              
            merge(a, left, mid, right)  
            left = left + current_size*2
              
        current_size = 2 * current_size  
  
def merge(a, l, m, r):  
    n1 = m - l + 1
    n2 = r - m  
    L = [0] * n1  
    R = [0] * n2  
    for i in range(0, n1):  
        L[i] = a[l + i]  
    for i in range(0, n2):  
        R[i] = a[m + i + 1]  
  
    i, j, k = 0, 0, l  
    while i < n1 and j < n2:  
        if L[i] > R[j]:  
            a[k] = R[j]  
            j += 1
        else:  
            a[k] = L[i]  
            i += 1
        k += 1
  
    while i < n1:  
        a[k] = L[i]  
        i += 1
        k += 1
  
    while j < n2:  
        a[k] = R[j]  
        j += 1
        k += 1
  
  

a = list(map(int, input("Enter the numbers: ").split()))
print("Given list is ")  
print(a)  
  
mergeSort(a)  
  
print("Sorted list is ")  
print(a)  
