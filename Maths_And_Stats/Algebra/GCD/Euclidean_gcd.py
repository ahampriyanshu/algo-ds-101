def euclideanGCD(x, y): 

while(y): 
	x, y = y, x % y 

return x 

a = 10
b= 35

print ("The gcd of 10 and 35 is : ",end="") 
print (euclideanGCD(10,35)) 
