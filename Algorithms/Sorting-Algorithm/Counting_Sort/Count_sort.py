"""Count Sort
Time Complexity : O(n)
Space Complexity : O(n+k), k is range of input data

It can work on negative no. also
"""
def count_sort(ls):
    mx=max(ls)
    mi=min(ls)
    rang=(mx-mi+1)      #range of input data
    count=[0]*rang      #count list
    out=['Null']*len(ls)    #output list intialised with NUll values
    
    #calculating frequency
    for i in ls:
        count[i-mi]=count[i-mi]+1

    #cumulative sum of Frequency
    for i in range(1,len(count)):
        count[i]=count[i]+count[i-1]

    #output the data in out array in sorted order
    for i in range(len(ls)-1,-1,-1):
        out[count[ls[i]-mi]-1]=ls[i]
        count[ls[i]-mi]=count[ls[i]-mi]-1

    #copy the content of out list to original list
    for i in range(len(out)):
        ls[i]=out[i]
        
    return ls

if __name__ == "__main__":
    ls=list(map(int,input("Enter the array :: ").split()))
    ls= count_sort(ls)
    print(ls)
