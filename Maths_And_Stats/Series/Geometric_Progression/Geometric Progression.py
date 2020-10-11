def gp(a,r,n):
	for i in range(n):
		temp = a*pow(r,i)
		print(temp,end=" ")
a = int(input())
r = int(input())
n = int(input())
gp(a,r,n)
