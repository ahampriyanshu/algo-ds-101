def selection_sort(array):       #function to sort using selection sort
    swaps=0
    comparison=0
    for i in range(len(array)):
        mini=-1
        for j in range(i,len(array)):
            if(mini==-1 or array[j]<array[mini]):
                mini=j
            comparison+=1
        swaps+=1
        temp=array[i]
        array[i]=array[mini]
        array[mini]=temp
        print("Array after ",i+1,"th pass is : ",array)
    print("Array after sorting is : ",array)
    print(swaps," number of swaps and",comparison," comparisons")

def input_array():                       #function for taking input of array
    attended=[]
    number_of_attendee=int(input("Enter number of attendee : "))
    for i in range(number_of_attendee):
        tep=int(input("Enter roll number of attendee:"))
        attended.append(tep)
    return attended

if __name__ == '__main__':
    arr=input_array()
    selection_sort(arr)
    print("Array after sorting using selection sort : ",arr)
    