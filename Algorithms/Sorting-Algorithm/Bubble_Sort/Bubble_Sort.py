# This is the Python version of Bubble Sort
# Code is contributed by: Harsh Udai.
# 
# Bubble sort is an Sorting Algorithm which takes compelxity: O(n^2)

array=[5,4,3,2,1,6]

for i in range(0,len(array)):
    for j in range(0,len(array)-1):
        if(array[j]>array[j+1]): # swaps if greater element is before the smaller one
            temp=array[j]
            array[j]=array[j+1]
            array[j+1]=temp


print(array)