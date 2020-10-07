import sys

def sumOfSeries(n):
   x = (n * (n + 1) / 2)
   return (int)(x * x)
# main
n = sys.argv[1]
print(sumOfSeries(int(n)))
