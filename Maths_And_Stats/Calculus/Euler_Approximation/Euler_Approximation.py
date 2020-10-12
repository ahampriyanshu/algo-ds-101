# Python Code to find approximation 
# of a ordinary differential equation 
# using euler method. 
  
# Consider a differential equation 
# dy / dx =(2x + 3y + 4xy) 
def func( x, y ): 
    return (2 * x + 3 * y + 4 * x * y) 
      
def euler( x0, y, h, x ): 
  
    # Iterating till the point at which we 
    # need approximation 
    while x0 < x: 
        temp = y 
        y = y + h * func(x0, y) 
        x0 = x0 + h 
    
  
    print("Approximate solution at x = ", x, " is ", "%.6f"% y) 
      
# Initial Values 
x0 = float(input("Enter value of x0:- "))
y0 = float(input("Enter value oy y0:- "))
h = float(input("Enter step size:- "))
  
# Value of x at which we need approximation 
x = float(input("Enter value of x at which you want to approximate:- "))
  
euler(x0, y0, h, x) 