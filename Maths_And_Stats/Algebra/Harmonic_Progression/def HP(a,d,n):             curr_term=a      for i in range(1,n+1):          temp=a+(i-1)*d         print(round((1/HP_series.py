def HP(a,d,n):        
    curr_term=a 
    for i in range(1,n+1): 
        temp=a+(i-1)*d
        print(round((1/temp),5))


a = 2   
d = 1   
n = 5  
  
HP(a, d, n) 
