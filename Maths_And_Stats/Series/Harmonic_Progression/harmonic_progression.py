def HP(a,d,n):      
    curr_term=a 
    for i in range(1,n+1): 
        temp=a+(i-1)*d
        print(1/temp)


a = 2   
d = 1   
n = 5  
  
HP(a, d, n) 
