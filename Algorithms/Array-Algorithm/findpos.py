def findposition(arr, x) :
    flag = True
    for i in range(0, len(arr)) :
        if (x != arr[i]) :
            continue
        if (flag==True) :
            first = i
        last = i
        flag = False
     
    if (flag==False) :
        print( "First Occurrence in array = ", first , "\n" + " Last Occurrence in array = ", last)
    else :
        print("Element Not Found")
         
arr = [1, 2, 2, 2, 2, 3, 4, 7, 8, 8 ]
x=int(input("Enter the Element : "))
findposition(arr, x)