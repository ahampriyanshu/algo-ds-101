def AP(a,d,n): 
    sum=0       
    curr_term=a 
    for i in range(1,n+1): 
        print(curr_term, end=' ') 
        curr_term =curr_term + d 


a = 5   
d = 1   
n = 10 
  
AP(a, d, n) 
