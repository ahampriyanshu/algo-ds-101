def mergeIntervals(arr):
        arr.sort(key = lambda x: x[0]) 
        m = []
        s = -10000
        max = -100000
        for i in range(len(arr)):
            a = arr[i]
            if a[0] > max:
                if i != 0:
                    m.append([s,max])
                max = a[1]
                s = a[0]
            else:
                if a[1] >= max:
                    max = a[1]
        if max != -100000 and [s, max] not in m:
            m.append([s, max])
        print("The Merged Intervals are :", end = " ")
        for i in range(len(m)):
            print(m[i], end = " ")
            
            
arr = [[6, 8], [1, 9], [2, 4], [4, 7]]
mergeIntervals(arr)