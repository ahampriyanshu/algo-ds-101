#Problem Statement
#Given an array of integers, print a sum triangle from it such that the first level has all array elements. From then, at each level number
#of elements is one less than the previous level and elements at the level is be the Sum of consecutive two elements in the previous level.
#For Example:
#input: [1,2,3,4]
#Output: [20]
#        [8,12]                             {8+12=20}
#        [3,5,7]                            {3+5=8,5+7=12}
#        [1,2,3,4]                          {1+2=3, 2+3=5, 3+4=7}
def Sumtriangle(Arr):
    if(len(Arr)<1):
        return
    #creating new array for containg sum of consecutive numbers
    temp = [0]*(len(Arr)-1)
    for i in range(len(Arr)-1):
        temp[i] = Arr[i]+Arr[i+1]
    #recursion over the new array
    Sumtriangle(temp)
    print(Arr)
a = [1,2,3,4,5,6]
Sumtriangle(a)