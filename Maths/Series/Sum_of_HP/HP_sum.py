def HP(a,d,n): 
    sum=0       
    curr_term=a 
    for i in range(1,n+1): 
        temp=a+(i-1)*d
        sum+=(round((1/temp),5))
    print(sum)


a = 2   
d = 1   
n = 5  
  
HP(a, d, n) 
