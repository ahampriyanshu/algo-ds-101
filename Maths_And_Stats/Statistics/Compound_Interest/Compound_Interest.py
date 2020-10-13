# Python3 program to find compound 
# interest for given values. 
  
def compound_interest(principle, rate, time): 
  
    # Calculates compound interest  
    Amount = principle * (pow((1 + rate / 100), time)) 
    CI = Amount - principle 
    print("Compound interest is", CI) 
  
# Driver Code  
p = float(input("Enter principle amount: "))
r = float(input("Enter rate: "))
t = float(input("Enter time: "))
compound_interest(p, r, t) 
