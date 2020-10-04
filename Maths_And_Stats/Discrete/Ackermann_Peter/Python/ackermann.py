def ackermann(m,n):
     if m == 0:
          return (n + 1)
     elif n == 0:
          return ackermann(m - 1, 1)
     else:
          return ackermann(m - 1, ackermann(m, n - 1)) 

#Example
# ackermann(2, 1) --> 5
# ackermann(2, 2) --> 7