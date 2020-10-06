def shell(a):
  n=len(a)
  gap=n//2
  while gap>0:
    for j in range(gap,n):
      key=a[j]
      i=j
      while i>0 and a[i-gap]>key:
        a[i]=a[i-gap]
        i=i-gap
      a[i]=key
    gap=gap//2
  return a

a=[2,7,4,6,1,8,5]
print(shell(a))
