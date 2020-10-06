def stoogesort(arr, l, h):
   if l >= h:
      return
   
   if arr[l]>arr[h]:
      t = arr[l]
      arr[l] = arr[h]
      arr[h] = t
  
   if h-l+1 > 2:
      t = (int)((h-l+1)/3)
      # sort first 2/3 elements
      stoogesort(arr, l, (h-t))
      # sort last 2/3 elements
      stoogesort(arr, l+t, (h))
      # sort first 2/3 elements again
      stoogesort(arr, l, (h-t))

arr = [1,4,2,3,6,5,8,7]
n = len(arr)
stoogesort(arr, 0, n-1)
print ("Sorted sequence is:")
for i in range(0, n):
   print(arr[i], end = " ")