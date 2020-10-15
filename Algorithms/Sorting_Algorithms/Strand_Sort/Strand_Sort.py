def merge(list1, list2):
  output = []
  while len(list1) and len(list2):
    if list1[0] < list2[0]:
      output.append(list1.pop(0))
    else:
      output.append(list2.pop(0))
  output += list1
  output += list2
  return output
 
def strand(arr):
  i, s = 0, [arr.pop(0)]
  while i < len(arr):
    if arr[i] > s[-1]:
      s.append(arr.pop(i))
    else:
      i += 1
  return s
 
def strand_sort(arr):
  output = strand(arr)
  while len(arr):
    output = merge(output, strand(arr))
  return output
 
 
list1 = [12,4,43,17,10,9,6,28,13,1]
print("Unsorted List", list1)
 
list2 = strand_sort(list1)
print("Sorted List", list2)